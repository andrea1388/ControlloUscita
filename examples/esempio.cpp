#include <Arduino.h>
#include "ControlloUscita.h"

#define RELEFARI A0
#define RELESIRENA 6
#define RELEAPRICANCELLO 7

ControlloUscita sirena(RELESIRENA,true,false);
ControlloUscita apricancello(RELEAPRICANCELLO,true,false);
ControlloUscita fari(RELEFARI,true,false);
ControlloUscita led(LED_BUILTIN,false,false);

void setup() {
    lampada.On();
}

void loop() {
    sirena.Elabora();
    apricancello.Elabora();
    fari.Elabora();
    led.Elabora();
}

void qualcheEvento() {
    fari.Off();
    lampada.Inverti();
    apricancello.OnOff(700,1000);
    f(!fari.isOn()) fari.On(180000);
    led.OndaQuadra(100,900);
}