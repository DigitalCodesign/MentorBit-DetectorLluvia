# MentorBitDetectorLluvia

Librería para la detección de lluvia mediante sensor de lluvia en módulos compatibles con MentorBit.

## Descripción

La librería `MentorBitDetectorLluvia` permite la lectura de datos de un sensor de lluvia en módulos compatibles con MentorBit. Ofrece tanto lectura digital (presencia o ausencia de lluvia) como lectura analógica (intensidad de la lluvia), permitiendo una monitorización precisa de las condiciones climáticas.

## Modo de Empleo

1.  **Instalación:**
    * Abre el IDE compatible con MentorBit.
    * Ve a "Herramientas" -> "Gestionar librerías..."
    * Busca "MentorBitDetectorLluvia" e instálala.

2.  **Ejemplo básico:**

    ```c++
    #include <MentorBitDetectorLluvia.h>

    MentorBitDetectorLluvia lluvia(A0, 2); // Sensor conectado a A0 (analógico) y 2 (digital)

    void setup() {
      Serial.begin(9600);
      Serial.println("Sensor de lluvia inicializado.");
    }

    void loop() {
      bool lluviaDigital = lluvia.obtenerLecturaDigital();
      uint16_t lluviaAnalogica = lluvia.obtenerLecturaAnalogica();

      Serial.print("Lectura Digital: ");
      Serial.println(lluviaDigital ? "Lluvia detectada" : "Sin lluvia");

      Serial.print("Lectura Analógica: ");
      Serial.println(lluviaAnalogica);

      delay(1000);
    }
    ```

## Constructor y Métodos Públicos

### Constructor

* `MentorBitDetectorLluvia(uint8_t detector_pin = 0, uint8_t analog_detector_pin = 0)`: Crea un objeto `MentorBitDetectorLluvia`.
    * `detector_pin`: Número de pin analógico al que está conectado el sensor para la lectura analógica. Si no se especifica, se asume que no está conectado a ningún pin inicialmente.
    * `analog_detector_pin`: Número de pin digital al que está conectado el sensor para la lectura digital. Si no se especifica, se asume que no está conectado a ningún pin inicialmente.

### Métodos

* `bool obtenerLecturaDigital()`: Devuelve `true` si se detecta lluvia (lectura digital), `false` en caso contrario.
* `uint16_t obtenerLecturaAnalogica()`: Devuelve el valor analógico de la intensidad de la lluvia.
