#include "ControlloUscita.h"
#include <Arduino.h>
ControlloUscita::ControlloUscita(int pin, bool invertito, bool statoinizialeOn) {
    _pin=pin;
    azione=NIENTE;
    von=1;
    voff=0;
    if (invertito) {
        von=0;
        voff=1;
    }
    pinMode(pin, OUTPUT);
    if (statoinizialeOn) digitalWrite(pin,von); else digitalWrite(pin,voff); 
}
void ControlloUscita::Elabora() {
    unsigned long int now=millis();
    if((now - tinizio) < durata) return;
    switch(azione) {
        case OFF:
            digitalWrite(_pin,voff); 
            azione=NIENTE;
            break;
        case ON:
            digitalWrite(_pin,von); 
            azione=NIENTE;
            break;
        case ONOFF:
            digitalWrite(_pin,voff); 
            durata=_toff;
            tinizio=now;
            azione=OFF;
            break;
        case QUADRA:                      
            tinizio=now;
            if(isOn()) {
                digitalWrite(_pin,voff); 
                durata=_toff; 
            } else {
                digitalWrite(_pin,von); 
                durata=_ton;
            }
            break;
        case NIENTE:  
            break;    
    }

}

void ControlloUscita::On(unsigned long Ton) {
    digitalWrite(_pin,von);
    durata=Ton;
    tinizio=millis();
    azione=OFF;
}

void ControlloUscita::OnOff(unsigned long Ton, unsigned long Toff) {
    if(azione!=NIENTE) return;
    _ton=Ton;
    _toff=Toff;
    digitalWrite(_pin,von);
    durata=Ton;
    tinizio=millis();
    azione=ONOFF;
}

void ControlloUscita::Off(unsigned long Toff) {
    digitalWrite(_pin,voff);
    durata=Toff;
    tinizio=millis();
    azione=ON;
}

void ControlloUscita::Off() {
    digitalWrite(_pin,voff);
    azione=NIENTE;
}

void ControlloUscita::On() {
    digitalWrite(_pin,von);
    azione=NIENTE;
}

void ControlloUscita::Inverti() {
    if(isOn()) Off(); else On();
    azione=NIENTE;
}

void ControlloUscita::OndaQuadra(unsigned long TOn, unsigned long TOff) {
    _ton=TOn;
    _toff=TOff;
    digitalWrite(_pin,von);
    durata=TOn;
    tinizio=millis();
    azione=QUADRA;

}

bool ControlloUscita::Completato() {
    return azione==NIENTE;
}

bool ControlloUscita::isOn() {
    return (digitalRead(_pin)==von);
}