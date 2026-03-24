#include "GestorPacientes.h"
#include "Cola/Nodo.h"
#include <iostream>

void GestorPacientes::cargarPacientes(std::vector<Paciente>& nuevosPacientes) {
    for (int i = 0; i < nuevosPacientes.size(); i++) {
        pacientes.push(nuevosPacientes[i]);
    }
}

void GestorPacientes::mostrarSalaEspera() {
    std::shared_ptr<Nodo<Paciente>> actual = pacientes.getPrimero();

    std::cout << "========== SALA DE ESPERA ==========\n\n";
    while (actual != nullptr) {
        Paciente pActual = actual->getDato();
        std::cout << pActual << std::endl;
        actual = actual->getSig();
    }
}

void GestorPacientes::ingresarEmergencia(Paciente& pacienteEmergencia) {
    // Decisiones: si el paciente no tiene triaje R no lo consideramos emergencia.
    if (pacienteEmergencia.getTriaje() != 'R') return;

    // Si no existe, lo creamos nuevo en el principio.
    if (!pacientes.exists(pacienteEmergencia)) {
        pacientes.push_front(pacienteEmergencia);
    }else {
        // Si existe, lo movemos al inicio.
        pacientes.remove(pacienteEmergencia);
        pacientes.push_front(pacienteEmergencia);
    }
}

void GestorPacientes::procesarAltasVoluntarias() {
    std::shared_ptr<Nodo<Paciente>> actual = pacientes.getPrimero();

    double sumaTemperatura = 0;
    int numeroPacientes = 0;
    while (actual != nullptr) {
        Paciente pActual = actual->getDato();
        // Los pacientes que se van deben tener triaje V y espera en false.
        if (pActual.getTriaje() == 'V' && !pActual.getEspera()) {
            sumaTemperatura += pActual.getTemperatura();
            ++numeroPacientes;
            pacientes.remove(pActual);
        }
        actual = actual->getSig();
    }

    double promedioTemperatura = sumaTemperatura / numeroPacientes;
    std::cout << "Pacientes que se van: " << numeroPacientes << std::endl;
    std::cout << "Temperatura promedio: " << promedioTemperatura << std::endl;
}
