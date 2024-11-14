#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "api_config.h"
#include <modbus_api.h>

#include "mqtt.h"




#define MQTT_URL                        "mqtt://test.mosquitto.org"
#define MQTT_TOPIC_SUB                  "MODBUS_REQUEST"
#define MQTT_TOPIC_PUB                  "MODBUS_RESPONSE"
#define ADDRESS_SLAVE                   1
#define BAUDRATE                        115200







char mb_rsp[1024]={0};
int enable = 0;



mb_communication_info_t modbus_cfg = {
                            .baudrate = BAUDRATE,
                            .mode = MB_MODE_RTU,                    //  MB_MODE_ASCII DISPONIBLE TAMBIEN 
                            .port = UART_NUM_1,                     // UART_NUM 0 ,1 , 2
                            .parity = UART_PARITY_DISABLE,          // UART_PARITY_DISABLE , UART_PARITY_EVEN , UART_PARITY_ODD    
                            .slave_addr = ADDRESS_SLAVE,
};




void mqtt_data_cb(char* data, char* topic);

void mqtt_connected_cb();

void mqtt_disconnected_cb();

void error(void);



void main_aplication(void){
    printf("\nConectado al WiFi, ahora conectarme a los servicios MQTT\n");

    mqtt_init(          MQTT_URL, 
                        mqtt_connected_cb,
                        mqtt_disconnected_cb,
                        mqtt_data_cb);
}






void app_main(void)
{
    api_config(main_aplication,error);
}









/***
 * Funcion callback, recibe la respuesta modbus y la publica.
 */
void server_iot(    mb_param_request_t* req, void* buff,size_t len, bool ok){
    sprintf(mb_rsp,"[%d]",req->reg_start);
    //iot_publish_dummy(buff,req->reg_size);
     uint16_t* b = (uint16_t*) buff;
    for (int counter = 0; counter < req->reg_size; counter++){
        sprintf(&(mb_rsp[strlen(mb_rsp)]),"| %d ", b[counter]);
    }
    sprintf(&(mb_rsp[strlen(mb_rsp)]),"|\n ");
    printf(mb_rsp);


    mqtt_publish(mb_rsp,MQTT_TOPIC_PUB,2,0);
    mb_rsp[0]=0;

}




int parse_buffer(const char *buffer, mb_param_request_t *req) {
    if (!buffer || !req) return -1;

    char *token;
    char temp_buffer[50];  // Asumimos un tamaño máximo de buffer razonable
    strncpy(temp_buffer, buffer, sizeof(temp_buffer) - 1);
    temp_buffer[sizeof(temp_buffer) - 1] = '\0';  // Aseguramos el null terminator

    // Primero, extraemos el comando
    token = strtok(temp_buffer, "|");
    if (!token) return -1;
    req->command = atoi(token);

    // Luego, extraemos el tamaño del registro
    token = strtok(NULL, "|");
    if (!token) return -1;
    req->reg_size = atoi(token);

    // Finalmente, extraemos el inicio del registro
    token = strtok(NULL, "|");
    if (!token) return -1;
    req->reg_start = atoi(token);

    return 0;  // Retornamos 0 en caso de éxito
}






void mqtt_data_cb(char* data, char* topic){
    printf("\n[MQTT]%s > %s\n",topic,data);
    mb_param_request_t req ={0};
    if (parse_buffer(data, &req) == 0) {
        printf("Command: %d\n", req.command);
        printf("Reg Size: %d\n", req.reg_size);
        printf("Reg Start: %d\n", req.reg_start);
        esp_err_t err =  modbus_api_send_request(&req);
        vTaskDelay(100/portTICK_PERIOD_MS);
    } else {
        printf("%s 0>Error al parsear el buffer.\n",data);
        mqtt_publish("Formato de peticion erroneo\n",MQTT_TOPIC_PUB,2,0);


    }
    
}




void mqtt_connected_cb(){
    printf("\n[MQTT] Se conecto al servidor %s\n",MQTT_URL);
    mqtt_subcribe(MQTT_TOPIC_SUB, 2);
    enable = 1;
    // Inicio la interfaz modbus
    esp_err_t err = modbus_api_config(&modbus_cfg,server_iot);
    if(err != ESP_OK){
        printf("Error al inicial modbus api\n");
    }
 }



void mqtt_disconnected_cb(){  printf("\n[MQTT] Se desconecto del servidor\n");}


void error(void){ printf("Error in api_config, reset\n");}