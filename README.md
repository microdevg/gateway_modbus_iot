## Prototipo Gateway Modbus MQTT

Interfaz Modbus controlable mediante tópicos MQTT.

### Repositorios Relacionados

Este prototipo está basado en los siguientes repositorios:

- **Portal WiFi**: Interfaz web para configurar credenciales WiFi. Link: [repo](https://github.com/microdevg/wifi_manager_portal.git).


- **Modbus Api**: Interfaz Modbus sencilla basado en callbacks y peticiones en queues. Link:[repo](https://github.com/microdevg/modbus_api_simple).



### Correr las pruebas


Para correr las pruebas en un entornos docker, primero se debe instalar docker, luego inicializarlo y por ultimo:
```bash
    # Inicio el contenedor docker
    docker run -it --rm -v ${PWD}:/home/dev/project throwtheswitch/madsciencelab
    # Si necesitas ser user root
    #  docker run -it --rm -v ${PWD}:/home/dev/project -u root  throwtheswitch/madsciencelab
```
Una vez dentro del contenedor corremos los test con:
```bash
    ceedling test:all
```
Obtengo la cobertura de los test con:
```bash
    ceedling gcov:all
```
Esto genera un informa en formato html en : `build/artifacts/gcov/gcovr`




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