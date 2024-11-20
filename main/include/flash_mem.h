#ifndef FLASH_MEM_H
#define FLASH_MEM_H



#include "base.h"
#include "nvs.h"

// Nombres de los espacios utilizados en memoria flash
#define SSID_KEY "nombrewifi"
#define PASSWORD_KEY "wificontraseña"
#define PARTITION_NAME  "storage"
/**
 * @brief Inicio la memoria nvs
 * 
 */
esp_err_t flash_mem_init();


/**
 * @brief Almaceno dos cadenas de caracteres en memoria flash.
 * 
 * @param id Id de WiFi.
 * @param pass  Contraseña de WiFi.
 */
esp_err_t flash_mem_save(char* id,char* pass);



/**
 * @brief Extraigo dos cadenas de caracteres desde memoria.
 * 
 * @param id Id de WiFi.
 * @param pass  Contraseña de WiFi.
 * @return esp_err_t 
 */
esp_err_t flash_mem_get(char* id, char* pass);


/**
 * @brief Elimino credenciales almacenadas
 * 
 * @return esp_err_t 
 */
esp_err_t flash_memory_clear_credentials();



/**
 * @brief Desinicializo la memoria flash. Libero recursos.
 * 
 */
esp_err_t flash_mem_deinit();


/**
 * @brief Devuelve el my_handler interno
 * 
 * @return nvs_handle_t 
 */
nvs_handle_t* get_phandle();


#endif