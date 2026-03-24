#pragma once
#include <string>
#include <ostream>

class Paciente {
private:
    std::string codigo; // No se valida
    int num_historial;
    int hora_llegada; //formato hhmm
    char triaje; // v, a, r No hay que validarlo
    double temperatura;
    bool espera; // Determina si un paciente espera cola o se va.
public:
    Paciente(int num, int hora, char tri, double temp, bool esp)
    {
        num_historial = num;
        hora_llegada = hora;
        triaje = tri;
        temperatura = temp;
        actualizarCodigo();
        espera = esp;
    }
    void setNumeroHistorial(int num);
    void setHoraLlegada(int hora);
    void setTriaje(char tri);
    void setTemperatura(double temp);
    void actualizarCodigo();
    int getNumeroHistorial();
    int getHoraLlegada();
    bool getEspera();
    std::string getCodigo();
    char getTriaje();
    double getTemperatura();
    bool operator==(const Paciente& other) const {
        return num_historial == other.num_historial;
    }
    friend std::ostream& operator<<(std::ostream &os, const Paciente &p)
    {
        os<<"Numero de historial: "<< p.num_historial<<std::endl;
        os<<"Hora de llegada: "<<p.hora_llegada<<std::endl;
        os<<"Triaje: "<<p.triaje<<std::endl;
        os<<"Temperatura: "<<p.temperatura<<std::endl;
        return os;
    }
    void mostrarInformacion();

};
