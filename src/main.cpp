#include <iostream>
#include "Pacientes/GestorPacientes.h"
#include "Pacientes/Paciente.h"

int main() {

    std::vector<Paciente> nuevosPacientes = {
        Paciente(1001, 815,  'V', 36.5, true),
        Paciente(1002, 830,  'A', 37.2, false),
        Paciente(1003, 845,  'R', 38.1, false),
        Paciente(1004, 900,  'V', 36.8, false),
        Paciente(1005, 915,  'A', 39.0, false),
        Paciente(1006, 930,  'R', 37.7, false),
        Paciente(1007, 945,  'V', 36.3, true),
        Paciente(1008, 1000, 'A', 38.4, false),
        Paciente(1009, 1015, 'R', 37.0, false),
        Paciente(1010, 1030, 'V', 36.9, false)
    };

    GestorPacientes gestorPacientes;

    gestorPacientes.cargarPacientes(nuevosPacientes);
    std::cout << "\t CARGA DE PACIENTES\n\n";
    gestorPacientes.mostrarSalaEspera();

    Paciente pacienteEmergenciaExistente = Paciente(1003, 845,  'R', 38.1, false);
    gestorPacientes.ingresarEmergencia(pacienteEmergenciaExistente);
    std::cout << "\t EMERGENCIA PACIENTE EXISTENTE\n\n";
    gestorPacientes.mostrarSalaEspera();

    Paciente pacienteEmergenciaNuevo = Paciente(6666, 815, 'R', 40.0, true);
    gestorPacientes.ingresarEmergencia(pacienteEmergenciaNuevo);
    std::cout << "\t EMERGENCIA PACIENTE NUEVO\n\n";
    gestorPacientes.mostrarSalaEspera();

    std::cout << "\t PROCESAR ALTAS VOLUNTARIAS\n\n";
    gestorPacientes.procesarAltasVoluntarias();
    gestorPacientes.mostrarSalaEspera();

    return 0;
}