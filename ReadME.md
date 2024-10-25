# LM35-ESP32

Archivos utilizados para la practica de laboratorio en la
materia de:
* Redes Industriales.
* Semestre 9

## Descripción:
Aplicacion movil para solicitar a un ESP32 la temperatura de un sensor LM35.

La aplicacion fue construida en: [MIT APP INVENTOR](https://appinventor.mit.edu/)

## Codigo:
```ino
//Se usa la libreria BluetoothSerial para realizar la conección
//Entre la aplicacion movil y el ESP-32
#include "BluetoothSerial.h"

//Se crea una instancia de la libreria:
BluetoothSerial SerialBT;

//En el voidLop() se lee la temperatura del sensor
//por medio del pin 4 (GPIO4)
void loop() {
  lectura = analogRead(pin);
  
//Condicion if para leer el valor que nos manda la app
  if (SerialBT.available()) {
    valor = (SerialBT.read());
    if (valor = 1) {
      temp =  (1.1 * lectura * 100.0)/1024.0;
      SerialBT.print(temp);
      Serial.println (temp);
      delay(1000);
    }
  }
}
```

El codigo de la App usa un sistema de bloques:

1. Se inicia el Bluethooth del celuar para buscar los dispositivos y enlistarlos.

2. El `ListPiker1` se encarga de crear la lista con los dispositivos.

3. Con el boton: `Dispositivos BT Accesibles` podemos ver la lista de dispositivos a los que podemos conectarnos.

4. La logica del programa consiste en crear un bucle `When` que se ejecuta cuando se selecciona el boton: `Nueva Lectura` el cual se encarga de mandar un `1` como texto al ESP32 para ejecutar su logica y enviar el valor de la temperatura.

5. Despues de resivir la temp, la App procesa los datos para mostrarlos en el label `Temperatura: `.

6. Si la Temp sobrepasa los 50° se lanza una alerta para informar que existe una temeperatura alta

*para mas informacion de la App consulta las capturas de pantalla*

## Contribución:
Gracias por leer hasta aqui, este fue una pequeña practica que realice durante mi carrera.

Los codigos son libres de usar y mejorar en otros proyectos

## License

[MIT](https://choosealicense.com/licenses/mit/)
