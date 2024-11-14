#ifndef FLASH_MEM_H
#define FLASH_MEM_H



#include "base.h"
// Nombres de los espacios utilizados en memoria flash
#define SSID_KEY "nombrewifi"
#define PASSWORD_KEY "wificontraseña"

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



#endif