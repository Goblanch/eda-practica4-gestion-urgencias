#include "Paciente.h"
#include <iostream>

void Paciente::setNumeroHistorial(int num)
{
    num_historial = num;
    actualizarCodigo();
}
void Paciente::setHoraLlegada(int hora)
{
    hora_llegada = hora;
    actualizarCodigo();
}
void Paciente::setTriaje(char tri)
{
    triaje = tri;
}
void Paciente::setTemperatura(double temp)
{
    temperatura = temp;
}
void Paciente::actualizarCodigo()
{
    codigo = std::to_string(num_historial) +   " - " + std::to_string(hora_llegada);
}
int Paciente::getNumeroHistorial()
{
    return num_historial;
}
int Paciente::getHoraLlegada()
{
    return hora_llegada;
}
std::string Paciente::getCodigo()
{
    return codigo;
}
char Paciente::getTriaje()
{
    return triaje;
}
double Paciente::getTemperatura()
{
    return temperatura;
}
void Paciente::mostrarInformacion()
{
    std::cout<<"Numero de historial: "<< num_historial<<std::endl;
    std::cout<<"Hora de llegada: "<< hora_llegada<<std::endl;
    std::cout<<"Triaje: "<< triaje<<std::endl;
    std::cout<<"Temperatura: "<< temperatura<<std::endl;
}
