# EDA PRÁCTICA URGENCIAS
Práctica 4 de Gestión de Urgencias de Estructura de Datos y Algoritmos.
### Contenido - Ficheros
Paciente.cpp y Paciente.h -> Aquí únicamente tendremos la clase paciente con sus getters y setters. Además de una sobrecarga del operador << y un método para actualizar código.
GestorPacientes.cpp y GestorPacientes.h -> Gestor encargado de atender pacientes en caso de urgencia y dar el alta.
Cola.h -> Cola genérica. Hacemos uso de Templates.
Nodo.h -> Nodo genérico. Tambiñen hacemos uso de Templates.


### Observaciones a tener en cuenta
A la hora de dar el alta hemos decidido meter un atributo llamado espera (bool). Si es falso y además el triaje es 'V' (Verde) vamos a eliminarlo de nuestra cola. Ya que le daremos el alta.

