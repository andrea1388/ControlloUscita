class ControlloUscita {
    public:
        ControlloUscita(int pin, bool invertito, bool statoinizialeOn);
        void Elabora();
        void OndaQuadra(unsigned long int TOn, unsigned long int TOff);
        void On(unsigned long int TOn);
        void Off(unsigned long int TOff);
        void On();
        void Off();
        void OnOff(unsigned long int TOn, unsigned long int TOff);
        void Inverti();
        bool isOn();
        bool Completato();

    protected:
        int _pin;
        typedef enum {NIENTE, ON, OFF, ONOFF, QUADRA} tipoazione;
        tipoazione azione;
        unsigned long int durata, tinizio,_ton,_toff;
        unsigned char von,voff;
};