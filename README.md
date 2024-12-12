# MentorBit-DetectorLluvia

Esta librería está diseñada para interactuar con el módulo de Detector de Lluvia de MentorBit, permitiendo obtener lecturas digitales y analógicas desde el sensor de lluvia.

Puedes encontrar el producto y más material de electrónica y robótica en nuestra tienda oficial: [https://digitalcodesign.com/shop](https://digitalcodesign.com/shop)

## Modo de Empleo

Una vez que tengas la librería instalada en el Arduino IDE, inclúyela en tu proyecto con la siguiente línea:

```cpp
#include <MentorBitDetectorLluvia.h>
```

## Constructor

### `MentorBitDetectorLluvia(uint8_t detector_pin = 0, uint8_t analog_detector_pin = 0)`

Este constructor inicializa los pines del módulo, especificando el pin digital y el pin analógico para las lecturas del sensor de lluvia. Los parámetros `detector_pin` y `analog_detector_pin` son opcionales.

```cpp
MentorBitDetectorLluvia detector(2, A0);  // Pin digital 2 y pin analógico A0
```

## Métodos Principales

### `obtenerLecturaDigital()`

Devuelve `true` o `false` dependiendo de la lectura digital del sensor, con un umbral ajustable a través del potenciometro.

```cpp
bool lectura = detector.obtenerLecturaDigital();
```

### `obtenerLecturaAnalogica()`

Devuelve un valor analógico de 2 bytes, correspondiente a la lectura del sensor de lluvia en formato de valor entre 0 y 1023.

```cpp
uint16_t lectura_analogica = detector.obtenerLecturaAnalogica();
```
