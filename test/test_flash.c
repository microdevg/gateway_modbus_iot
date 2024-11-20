#include "unity.h"
#include "flash_mem.h"
#include "mock_esp_err.h"
#include "mock_nvs.h"
#include "mock_nvs_flash.h"




void setUp(void) {
    // Código que se ejecuta antes de cada test (si es necesario)
}

void tearDown(void) {
    // Código que se ejecuta después de cada test (si es necesario)
}

void test_flash_mem_init(void){

char id[20]={0}; 
char pass[20]={0};
    // Inicio la prueba
    // flash_init devolvera ESP_OK 
    nvs_flash_init_ExpectAndReturn(ESP_OK);
    // nvs_open devolvera ESP_OK
    nvs_open_ExpectAnyArgsAndReturn(ESP_OK);
    // nvs_open devolvera ESP_OK
    nvs_set_str_ExpectAnyArgsAndReturn(ESP_OK);
    //nvs_open por segunda vez devolvera ESP_OK
    nvs_set_str_ExpectAnyArgsAndReturn(ESP_OK);
    //nvs_commit devolvera ESP_OK
    nvs_commit_ExpectAnyArgsAndReturn(ESP_OK);
    //nvs_close no devolvera nada, 
    //solo verifico que se llamo
    nvs_close_ExpectAnyArgs();

    /**
         * @brief Las condiciones que le impongo a flash_mem_save
         *  Debe llamarse a flashinit y esta debe devolver ESP_OK
         *  Debe llamarse a nvs_open y esta debe devolver ESP_OK
         *  Debe llamarse 2 veces a nvs_set_str y debe devolver ESP_OK
         *  Debe llamarse a nvs_commit con retorno de ESP_OK
         *  Por ultimo se llama a nvs_close y no tiene retorno.
         */
    esp_err_t  err = flash_mem_save( id, pass);
    TEST_ASSERT_EQUAL(ESP_OK,err);
}
