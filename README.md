
# MentorBit-DetectorLluvia

Esta librería está diseñada para interactuar con el módulo de Detector de Lluvia de MentorBit, permitiendo obtener lecturas digitales y analógicas desde el sensor de lluvia.

Puedes encontrar el producto y más material de electrónica y robótica en nuestra tienda oficial: [https://digitalcodesign.com/shop](https://digitalcodesign.com/shop)

## Modo de Empleo

Una vez que tengas la librería instalada en el Arduino IDE, inclúyela en tu proyecto con la siguiente línea:

```cpp
#include <MentorBitDetectorLluvia.h>
```

### Constructor

Una vez incluida la librería, usamos el constructor para crear el objeto del módulo Detector de Lluvia y definimos los pines a los que está conectado el sensor:

```cpp
MentorBitDetectorLluvia detector(detector_pin, analog_detector_pin);
```

Siendo `detector_pin` el pin digital al que está conectado el sensor y `analog_detector_pin` el pin analógico para las lecturas del sensor de lluvia.

### Métodos Principales

#### `obtenerLecturaDigital()`

Devuelve `true` o `false` dependiendo de la lectura digital del sensor, con un umbral ajustable a través del potenciómetro:

```cpp
bool lectura = detector.obtenerLecturaDigital();
```

#### `obtenerLecturaAnalogica()`

Devuelve un valor analógico de 2 bytes, correspondiente a la lectura del sensor de lluvia en formato de valor entre 0 y 1023:

```cpp
uint16_t lectura_analogica = detector.obtenerLecturaAnalogica();
```

#### `configPort(const Port& port)`

Configura los pines y otros parámetros del puerto en el que está conectado el módulo. Se puede usar para redefinir los pines de conexión al sensor:

```cpp
Port puerto;
puerto.type = 'm';
puerto.gpios[0] = 2;  // Pin digital
puerto.gpios[1] = A0;  // Pin analógico
detector.configPort(puerto);
```
