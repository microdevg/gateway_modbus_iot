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

char id[20]; 
char pass[20];
nvs_set_str_IgnoreAndReturn(ESP_OK);
nvs_set_str_IgnoreAndReturn(ESP_OK);
nvs_commit_ExpectAnyArgsAndReturn(ESP_OK);
nvs_close_Stub(ESP_OK);
nvs_open_IgnoreAndReturn(ESP_OK);
nvs_close_ExpectAnyArgs();
nvs_flash_init_IgnoreAndReturn(ESP_OK);
esp_err_t  err = flash_mem_save( id, pass);
TEST_ASSERT_EQUAL(ESP_OK,err);




}
