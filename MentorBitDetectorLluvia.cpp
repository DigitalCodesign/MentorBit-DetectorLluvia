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
        

    Autor: Digital Codesign
    Version: 1.0.0
    Fecha de creación: Septiembre de 2024
    Fecha de version: Septiembre de 2024
    Repositorio: https://github.com/DigitalCodesign/MentorBit-DetectorLluvia
    Descripcion: 
        Esta libreria esta especificamente diseñada para ser utilizada junto con 
        el modulo MentorBit detector de lluvia
    Metodos principales:
        MentorBitDetectorLluvia -> constructor de la clase
        obtenerLecturaDigital -> obtiene un valor de true o false (umbral ajustable con el potenciometro)
        obtenerLecturaAnalogica -> da un valor analogico de 2 bytes 

*/

#include <MentorBitDetectorLluvia.h>

MentorBitDetectorLluvia::MentorBitDetectorLluvia(uint8_t detector_pin, uint8_t analog_detector_pin){
    _detector_pin = detector_pin;
    _analog_detector_pin = analog_detector_pin;
    pinMode(_detector_pin, INPUT);
}

bool MentorBitDetectorLluvia::obtenerLecturaDigital(){
    bool value;
    value = digitalRead(_detector_pin);
    return value;
}

uint16_t MentorBitDetectorLluvia::obtenerLecturaAnalogica(){
    uint16_t value;
    value = analogRead(_analog_detector_pin);
    return value;
}