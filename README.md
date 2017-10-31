# ControlloUscita
Libreria Arduino per generazione di impulsi di lunghezza definita e onde quadre

Modo d'uso:

// ControlloUscita(int pin, bool invertito, bool statoinizialeOn)
ControlloUscita sirena(RELESIRENA,true,false);

void loop() {
  sirena.Elabora();
}

void Allarme() {
  sirena.On(10000); // 10 secondi
}
