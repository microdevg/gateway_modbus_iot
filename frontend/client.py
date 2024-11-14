import paho.mqtt.client as mqtt

# Definir los tópicos
request_topic = "MODBUS_REQUEST"
response_topic = "MODBUS_RESPONSE"

import time





def finish(client):

# Detener el loop y desconectar
    client.loop_stop()
    client.disconnect()


# Definir las funciones de callback

# Callback cuando el cliente se conecta al servidor
def on_connect(client, userdata, flags, rc):
    print(f"Conectado con código de resultado: {rc}")
    # Suscribirse a los tópicos después de la conexión
    client.subscribe(response_topic)
    # Publicar un mensaje en los dos tópicos
|1

# Callback cuando se recibe un mensaje en un tópico
def on_message(client, userdata, msg):
    print(f"[modbus_response] {msg.payload.decode()}")

# Crear el cliente MQTT
client = mqtt.Client()

# Asignar las funciones de callback
client.on_connect = on_connect
client.on_message = on_message

# Configurar el servidor MQTT
broker = "test.mosquitto.org"  # Usamos el servidor público de Mosquitto
port = 1883  # Puerto por defecto

# Conectar al servidor MQTT
client.connect(broker, port, 60)



# Mantener la conexión y esperar mensajes
client.loop_start()

# Esperar para que los mensajes sean enviados y recibidos
time.sleep(5)


try:
    while True:
        ret = input(f"\nRequest modbus format   \n| Funcion| cantidad de registros| direccion de inicio|\n=> ")
        if ret == 'X':
            finish(client)
        client.publish(request_topic,ret)
        time.sleep(2)

except KeyboardInterrupt:
    print("Interrupción recibida, desconectando...")




