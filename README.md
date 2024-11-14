## Prototipo Gateway Modbus MQTT

Interfaz Modbus controlable mediante tópicos MQTT.

### Repositorios Relacionados

Este prototipo está basado en los siguientes repositorios:

- **Portal WiFi**: Interfaz web para configurar credenciales WiFi. Link: [repo](https://github.com/microdevg/wifi_manager_portal.git).


- **Modbus Api**: Interfaz Modbus sencilla basado en callbacks y peticiones en queues. Link:[repo](https://github.com/microdevg/modbus_api_simple).



### Frontedn simple con python en entorno virtual

En la carpeta frontend se encuenta el programa client.py que sirve para realizar pruebas. El mismo depende de paho-mqtt.
Para instalar esta libreria :
```bash
    pip install paho-mqtt
        
        
```
Se recomienda usar un entorno virtual:
```bash
    python3 -m venv .venv
    source .venv/Scripts/activate

    python client.py
```