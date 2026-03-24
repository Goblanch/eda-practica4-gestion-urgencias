#pragma once
#include <string>

class Paciente {
private:
    std::string codigo; // No se valida
    int num_historial;
    int hora_llegada; //formato hhmm
    char triaje; // v, a, r No hay que validarlo
    double temperatura;
public:
    Paciente(int num, int hora, char tri, double temp)
    {
        num_historial = num;
        hora_llegada = hora;
        triaje = tri;
        temperatura = temp;
        actualizarCodigo();
    }
    void setNumeroHistorial(int num);
    void setHoraLlegada(int hora);
    void setTriaje(char tri);
    void setTemperatura(double temp);
    void actualizarCodigo();
    int getNumeroHistorial();
    int getHoraLlegada();
    std::string getCodigo();
    char getTriaje();
    double getTemperatura();

};
