#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "api_config.h"



#define PROGRAM_NAME        "Gateway Modbus MQTT"



void error(void){ printf("Error in api_config, reset\n");}

void main_aplication(void){

}


void app_main(void)
{
    printf(PROGRAM_NAME);
    api_config(main_aplication,error);
}
