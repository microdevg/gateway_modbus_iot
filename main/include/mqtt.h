#ifndef _MQTT_H
#define _MQTT_H
#include "base.h"



/**
 * @brief 
 * 
 * @param uri 
 * @param conn 
 * @param disconn 
 * @param data_received 
 * @return esp_err_t 
 */
esp_err_t mqtt_init(const char* uri, esp_callback_t conn, esp_callback_t disconn,callback_data_t data_received);


/**
 * @brief Publico mensaje en topico. 
 * 
 * @param msg  mensaje a publicar en cstring.
 * @param topic to
 * pico a donde se publica en cstring.
 * @param qos  calidad del servicio.
 * @param retain  retencion del ultimo mensaje.
 * @return esp_err_t 
 */
esp_err_t mqtt_publish(const char* msg, const char* topic,int qos, int retain);


/**
 * @brief Publico mensaje en topico. 
 * 
 * @param msg  mensaje a publicar en cstring.
 * @param topic to
 * pico a donde se publica en cstring.
 * @param qos  calidad del servicio.
 * @param retain  retencion del ultimo mensaje.
 * @return esp_err_t 
 */
esp_err_t mqtt_publish_on_queue(const char* msg, const char* topic,int qos, int retain);



/**
 * @brief  Suscripcion a topico.
 * 
 * @param topic topico 
 * @param qos   calidad del mensaje
 * @return esp_err_t 
 */
esp_err_t mqtt_subcribe( char* topic, int qos);

#endif