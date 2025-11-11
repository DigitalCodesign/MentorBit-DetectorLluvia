# MentorBit-DetectorLluvia

Esta librería está diseñada para que puedas detectar la presencia de lluvia o humedad en superficies usando tu placa MentorBit y el **módulo de sensor de lluvia**.

Si estás empezando en el mundo de la electrónica, ¡no te preocupes! MentorBit está pensado para que aprender sea fácil y divertido. Esta placa ya incluye un montón de componentes (LEDs, pulsadores, pantallas, etc.) y utiliza conectores especiales (JST) para que puedas añadir nuevos sensores y módulos sin tener que pelearte con un montón de cables. Pásate por nuestra web para saber más de MentorBit y nuestros productos [pinchando aquí](https://digitalcodesign.com/).

![Render del Módulo MentorBit Detector de Lluvia.](https://github.com/DigitalCodesign/MentorBit-DetectorLluvia/blob/main/assets/RainDetector_Module.png)

Con esta librería, podrás saber cuándo empieza a llover y crear reacciones automáticas ante la humedad en tus proyectos.

---

## Descripción

### ¿Qué es un sensor de lluvia?

Un sensor de lluvia funciona detectando gotas de agua sobre una superficie conductora. Cuando cae agua sobre el panel del sensor, su resistencia eléctrica cambia, lo cual permite determinar si está lloviendo o hay humedad presente.

Este tipo de sensor es ideal para proyectos de automatización, protección de dispositivos o monitoreo ambiental.

---

### ¿Qué hace esta librería?

La librería **MentorBit-DetectorLluvia** facilita la lectura del sensor digital y te proporciona una función sencilla para saber si el sensor ha detectado agua.

Así puedes centrarte en el desarrollo de tu idea sin preocuparte por el tratamiento de señales o configuraciones complejas.

---

### ¿Qué puedes construir con este módulo?

- Un sistema que cierre ventanas automáticamente cuando llueve.
- Una estación meteorológica casera.
- Alarmas de protección para dispositivos expuestos al exterior.
- Sistemas de riego inteligentes que eviten regar si está lloviendo.

---

## Cómo empezar

### 1. **Conexión del Módulo**

Conecta el módulo detector de lluvia a uno de los puertos analógico-digital con conector JST de 4 pines que estan en la sección "Puertos para Módulos" de la placa MentorBit. Puedes usar tanto el pin analogico como el pin digital para obtener información de este módulo.

### 2. **Instalación de la Librería**

- Abre tu entorno de programación IDE de Arduino.
- Ve al menú *Programa -> Incluir Librería -> Administrar Librerías...*
- En el buscador, escribe ***MentorBit-DetectorLluvia*** y haz clic en "Instalar".

![Ejemplo de búsqueda en el gestor de librerías del IDE de Arduino.](https://github.com/DigitalCodesign/MentorBit-DetectorLluvia/blob/main/assets/library_instalation_example.png)

---

## Ejemplo Básico: Detectar lluvia

Este ejemplo imprime un mensaje si el sensor detecta gotas de agua.

```cpp
#include <MentorBitDetectorLluvia.h>

// Definimos los pines a los que se va a conectar el modulo
#define PIN_ANALOGICO A4
#define PIN_DIGITAL 24

// Creamos el objeto del sensor
MentorBitDetectorLluvia Detector_lluvia(PIN_DIGITAL, PIN_ANALOGICO);

void setup() {
    // Inicializamos el monitor Serial a una velocidad de 9600 baudios
    Serial.begin(9600);
}

void loop() {
    if (Detector_lluvia.obtenerLecturaDigital()) {
        Serial.println("¡Lluvia detectada!");
    } else {
        Serial.println("Sin lluvia.");
    }
    delay(1000);
}
```

---

## Funciones Principales

- `bool obtenerLecturaDigital()`  
  Devuelve `true` si se ha detectado presencia de agua, `false` si no.

- `uint16_t obtenerLecturaAnalogica()`  
  Devuelve el valor analogico medido por el sensor.

---

## Recursos Adicionales

- [Web del fabricante](https://digitalcodesign.com/)
- [Tienda Online de Canarias](https://canarias.digitalcodesign.com/shop)
- [Tienda Online de Península](https://digitalcodesign.com/shop)
- [Web Oficial de MentorBit](https://digitalcodesign.com/mentorbit)
- [Web Oficial del Módulo de Lluvia](https://canarias.digitalcodesign.com/shop/00039086-mentorbit-modulo-detector-de-lluvia-8140?category=230&order=create_date+desc#attr=)
- [Manual de usuario del Módulo](https://drive.google.com/file/d/15jhHWeUDYdCFEy5gRsNnJ5bLMTA1X6o_/view?usp=drive_link)
- [Modelo 3D del Módulo en formato .STEP](https://drive.google.com/file/d/1HQxT88MSzlSvJ_GRGNyVe74X1aEhiH53/view?usp=drive_link)
