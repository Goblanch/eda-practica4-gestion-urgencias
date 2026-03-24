#pragma once
#include <vector>

#include "Cola/Cola.h"
#include "Paciente.h"

class GestorPacientes {
public:
    void cargarPacientes(std::vector<Paciente>& nuevosPacientes);

    void mostrarSalaEspera();

    void ingresarEmergencia(Paciente& pacienteEmergencia);

    void procesarAltasVoluntarias();

private:
    Cola<Paciente> pacientes;

};