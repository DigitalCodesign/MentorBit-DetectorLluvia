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

#ifndef MentorBitDetectorLluvia_h
#define MentorBitDetectorLluvia_h

#include <Arduino.h>
#include <MentorPort.h>

class MentorBitDetectorLluvia : public MentorPort {

    public: 

        MentorBitDetectorLluvia(uint8_t detector_pin = 0, uint8_t analog_detector_pin = 0);
        
        void configPort(const Port& port) override;

        bool obtenerLecturaDigital() const;
        bool estaLloviendo() const;
        uint8_t intensidadLluviaPorcentaje() const;
        uint16_t obtenerLecturaAnalogica() const;

    private:

        Port _port;
        
};

#endif