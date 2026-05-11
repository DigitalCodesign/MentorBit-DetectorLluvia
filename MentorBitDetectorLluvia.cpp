/*


            ██████╗    ██╗    ██████╗    ██╗   ████████╗    █████╗    ██╗               
            ██╔══██╗   ██║   ██╔════╝    ██║   ╚══██╔══╝   ██╔══██╗   ██║               
            ██║  ██║   ██║   ██║  ███╗   ██║      ██║      ███████║   ██║               
            ██║  ██║   ██║   ██║   ██║   ██║      ██║      ██╔══██║   ██║               
            ██████╔╝   ██║   ╚██████╔╝   ██║      ██║      ██║  ██║   ███████╗          
            ╚═════╝    ╚═╝    ╚═════╝    ╚═╝      ╚═╝      ╚═╝  ╚═╝   ╚══════╝          
                                                                                        
     ██████╗    ██████╗    ██████╗    ███████╗   ███████╗   ██╗    ██████╗    ███╗   ██╗
    ██╔════╝   ██╔═══██╗   ██╔══██╗   ██╔════╝   ██╔════╝   ██║   ██╔════╝    ████╗  ██║
    ██║        ██║   ██║   ██║  ██║   █████╗     ███████╗   ██║   ██║  ███╗   ██╔██╗ ██║
    ██║        ██║   ██║   ██║  ██║   ██╔══╝     ╚════██║   ██║   ██║   ██║   ██║╚██╗██║
    ╚██████╗   ╚██████╔╝   ██████╔╝   ███████╗   ███████║   ██║   ╚██████╔╝   ██║ ╚████║
     ╚═════╝    ╚═════╝    ╚═════╝    ╚══════╝   ╚══════╝   ╚═╝    ╚═════╝    ╚═╝  ╚═══╝ 
        

    @author Digital Codesign
    @version 1.1.0
    @date Fecha de creación: Septiembre de 2024
    @date Fecha de versión: Mayo de 2026
    @see Repositorio: https://github.com/DigitalCodesign/MentorBit-DetectorLluvia
    * @brief Descripción: 
        Esta librería está específicamente diseñada para ser utilizada junto con 
        el módulo MentorBit detector de lluvia. Se ha optimizado para garantizar 
        la correcta configuración del hardware y se han implementado métodos de 
        "Calidad de Vida" (QoL) que adaptan el comportamiento eléctrico del sensor 
        a una lógica natural e intuitiva para el usuario.
    * @details Métodos principales:
        - MentorBitDetectorLluvia  -> Constructor de la clase.
        - obtenerLecturaDigital    -> Obtiene la lectura cruda del comparador (umbral ajustable con el potenciómetro).
        - obtenerLecturaAnalogica  -> Obtiene el valor analógico crudo (0-1023) del sensor.
    * Métodos extendidos y de control (Quality of Life):
        - estaLloviendo            -> Evalúa de forma intuitiva si el sensor detecta agua.
        - intensidadLluviaPorcentaje -> Mapea el valor analógico a un porcentaje (0% seco, 100% inundado).

*/

#include <MentorBitDetectorLluvia.h>

/**
 * @brief Constructor de la clase MentorBitDetectorLluvia.
 * Asigna los pines por defecto a los que está conectado el módulo físico.
 * @param detector_pin Pin digital para leer la salida del comparador de umbral (por defecto 0).
 * @param analog_detector_pin Pin analógico para medir la cantidad de agua continua (por defecto 0).
 */
MentorBitDetectorLluvia::MentorBitDetectorLluvia(uint8_t detector_pin, uint8_t analog_detector_pin) {

    _port.gpios[0] = analog_detector_pin;
    _port.gpios[1] = detector_pin;

}

/**
 * @brief Configura el puerto de hardware asociado al sensor.
 * Define internamente los pines asignados como entradas (INPUT) para garantizar
 * lecturas eléctricas correctas y estables, evitando estados flotantes.
 * @param port Estructura constante por referencia con la configuración del puerto.
 */
void MentorBitDetectorLluvia::configPort(const Port& port) {

    _port.type = port.type;
    _port.location = port.location;
    _port.gpios[0] = port.gpios[0];
    _port.gpios[1] = port.gpios[1];

    pinMode(_port.gpios[0], INPUT);
    pinMode(_port.gpios[1], INPUT);

}

/**
 * @brief Obtiene el estado lógico crudo de la salida digital del módulo.
 * El umbral de disparo de esta salida se ajusta físicamente mediante el potenciómetro
 * integrado en la placa del sensor. Típicamente devuelve LOW cuando detecta agua y HIGH en seco.
 * @return true o false dependiendo del estado eléctrico del pin digital.
 */
bool MentorBitDetectorLluvia::obtenerLecturaDigital() const {

    return digitalRead(_port.gpios[1]);

}

/**
 * @brief Comprueba de forma intuitiva y semántica si está lloviendo.
 * Invertir la lectura digital cruda para que la lógica de programación sea natural
 * (true = hay agua, false = está seco).
 * @return true si el sensor detecta humedad/agua por encima del umbral, false si está seco.
 */
bool MentorBitDetectorLluvia::estaLloviendo() const {

    return digitalRead(_port.gpios[1]) == false;

}

/**
 * @brief Convierte la lectura analógica a un porcentaje de intensidad de lluvia.
 * Invierte matemáticamente el comportamiento del hardware (donde 0 es máxima conductividad) 
 * para devolver un formato amigable.
 * @return Un valor de 0 a 100, donde 0% es completamente seco y 100% es máxima cantidad de agua.
 */
uint8_t MentorBitDetectorLluvia::intensidadLluviaPorcentaje() const {

    uint16_t raw_value = analogRead(_port.gpios[0]);
    if (raw_value > 1023) raw_value = 1023;
    return map(raw_value, 0, 1023, 100, 0);

}

/**
 * @brief Obtiene el valor analógico crudo (raw) del sensor de lluvia.
 * Debido a la conductividad del agua, los valores altos indican alta resistencia 
 * (superficie seca) y los valores bajos indican baja resistencia (superficie mojada).
 * @return Valor de 10 bits comprendido entre 0 y 1023.
 */
uint16_t MentorBitDetectorLluvia::obtenerLecturaAnalogica() const {

    return analogRead(_port.gpios[0]);

}
