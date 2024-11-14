#ifndef  WIFI_PORTAL_H
#define WIFI_PORTAL_H

#include "base.h"
/**
 * @brief Inicia un servidor web como interfaz para manejar credenciales WiFi.
 *        El servidor tiene la direccion http://my-esp32.com
 * @return * int* Una variable int* que me indica cuando la inicializacion 
 * se realizo correctamente y el servidor termino.
 * [1] Webserver funcionando.
 * [0] Termino el webserver.
 * @note Se recomienda almacenar las credenciales en memoria y 
 * reiniciar el microcontrolador para limpiar recursos de manera sencilla.
 */
int *  portal_wifi_ap(void);


#endif