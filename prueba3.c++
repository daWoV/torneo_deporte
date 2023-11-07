//Autor: Dael Chávez Ferreyra - A01771963
//Fecha: 06/11/2023

//Este programa es la implementación del ADT de Torneo de un deporte

#include <string>
#include <iostream>

struct Jugador {
    std::string nombre;
    int numero;
    std::string posicion;
    float average;
};

struct Equipo {
    int numeroJugadores;
    std::string nombre;
    int juegosGanados;
    int juegosPerdidos;
    int juegosEmpatados;
    int puntos;
    Jugador* jugadores;

    Equipo(int numJugadores, const std::string& nombre) {
        this->numeroJugadores = numJugadores;
        this->nombre = nombre;
        this->juegosGanados = 0;
        this->juegosPerdidos = 0;
        this->juegosEmpatados = 0;
        this->puntos = 0;
        this->jugadores = new Jugador[numJugadores];
    }
};

class Torneo {
public:
    int numeroEquipos;
    int numeroJugadores;
    Equipo** equipos;

    Torneo(int numEquipos, int numJugadores) {
        this->numeroEquipos = numEquipos;
        this->numeroJugadores = numJugadores;
        this->equipos = new Equipo*[numEquipos];

        for (int i = 0; i < numEquipos; i++) {
            this->equipos[i] = nullptr;
        }
    }

    // Función para insertar un equipo en el torneo
    void createEquipo(const std::string& nombreEquipo) {
        for (int i = 0; i < numeroEquipos; i++) {
            if (!equipos[i]) {
                equipos[i] = new Equipo(numeroJugadores, nombreEquipo);
                break;
            }
        }
    }

    // Función para obtener información de un equipo
    Equipo* readEquipo(const std::string& nombreEquipo) {
        for (int i = 0; i < numeroEquipos; i++) {
            if (equipos[i] && equipos[i]->nombre == nombreEquipo) {
                std::cout << "Nombre del equipo: " << equipos[i]->nombre << std::endl;
                std::cout << "Puntos: " << equipos[i]->puntos << std::endl;
                std::cout << "Ganados: " << equipos[i]->juegosGanados << std::endl;
                std::cout << "Empatados: " << equipos[i]->juegosEmpatados << std::endl;
                std::cout << "Perdidos: " << equipos[i]->juegosPerdidos << std::endl;   
                return equipos[i];
            }
        }
        std::cout << "Equipo no encontrado." << std::endl;
        return nullptr;
    }

    Jugador* readJugador(const std::string& nombreEquipo, const std::string& nombreJugador) {
        for (int i = 0; i < numeroEquipos; i++) {
            if (equipos[i] && equipos[i]->nombre == nombreEquipo) {
                if (equipos[i]) {
                    for (int j = 0; j < equipos[i]->numeroJugadores; j++) {
                        if (equipos[i]->jugadores[j].nombre == nombreJugador) {
                            std::cout << "Nombre del jugador: " << equipos[i]->jugadores[j].nombre << std::endl;
                            std::cout << "Numero: " << equipos[i]->jugadores[j].numero << std::endl;
                            std::cout << "Posicion: " << equipos[i]->jugadores[j].posicion << std::endl;
                            std::cout << "Average: " << equipos[i]->jugadores[j].average << std::endl;
                            return &(equipos[i]->jugadores[j]);
                        }
                    }
                }   
            }
        }
        std::cout << "Jugador no encontrado." << std::endl;
        return nullptr;
    }

    // Función para actualizar información de un equipo
    void updateEquipo(const std::string& nombreEquipo, int juegosGanados, int juegosPerdidos, int juegosEmpatados, int puntos) {
        for (int i = 0; i < numeroEquipos; i++) {
            if (equipos[i] && equipos[i]->nombre == nombreEquipo) {
                equipos[i]->juegosGanados = juegosGanados;
                equipos[i]->juegosPerdidos = juegosPerdidos;
                equipos[i]->juegosEmpatados = juegosEmpatados;
                equipos[i]->puntos = puntos;
                break;
            }
        }
    }

    // Función para actualizar información de un jugador
    void updateJugador(const std::string nombreEquipo, const std::string& nombreJugador, int numero, const std::string& posicion, float average) {
        for (int i = 0; i < numeroEquipos; i++) {
            if (equipos[i] && equipos[i]->nombre == nombreEquipo) {
                if (equipos[i]) {
                    for (int j = 0; j < equipos[i]->numeroJugadores; j++) {
                        if (equipos[i]->jugadores[j].nombre == nombreJugador) {
                            equipos[i]->jugadores[j].numero = numero;
                            equipos[i]->jugadores[j].posicion = posicion;
                            equipos[i]->jugadores[j].average = average;
                            break;
                        }
                    }
                }   
            }
        }
    }

    // Función para eliminar un equipo
    void deleteEquipo(const std::string& nombreEquipo) {
        for (int i = 0; i < numeroEquipos; i++) {
            if (equipos[i] && equipos[i]->nombre == nombreEquipo) {
                delete[] equipos[i]->jugadores;
                delete equipos[i];
                equipos[i] = nullptr;
                break;
            }
        }
    }

    //Función para eliminar un jugador
    void deleteJugador(const std::string& nombreEquipo, const std::string& nombreJugador) {
        for (int i = 0; i < numeroEquipos; i++) {
            if (equipos[i] && equipos[i]->nombre == nombreEquipo){
                for (int j = 0; j < equipos[i]->numeroJugadores; j++) {
                    if (equipos[i]->jugadores[j].nombre == nombreJugador) {
                        equipos[i]->jugadores[j].nombre = "";
                        equipos[i]->jugadores[j].numero = 0;
                        equipos[i]->jugadores[j].posicion = "";
                        equipos[i]->jugadores[j].average = 0;
                        break;
                    }
                }
            }
        }
    }

    // Función para mostrar la tabla de equipos
    void mostrarTabla() {
        // Ordenar equipos por puntos (puedes usar algún algoritmo de ordenamiento)
        for (int i = 0; i < numeroEquipos - 1; i++) {
            for (int j = 0; j < numeroEquipos - i - 1; j++) {
                if (equipos[j] && equipos[j + 1] && equipos[j]->puntos < equipos[j + 1]->puntos) {
                    Equipo* temp = equipos[j];
                    equipos[j] = equipos[j + 1];
                    equipos[j + 1] = temp;
                }
            }
        }

        // Mostrar la tabla
        std::cout << "Tabla de Posiciones:" << std::endl;
        for (int i = 0; i < numeroEquipos; i++) {
            if (equipos[i]) {
                std::cout << equipos[i]->nombre << " - Puntos: " << equipos[i]->puntos << " - Ganados: " << equipos[i]->juegosGanados << " - Empatados: " << equipos[i]->juegosEmpatados << " - Perdidos: " << equipos[i]->juegosPerdidos << std::endl;
            }
        }
    }

    // Función para agregar un jugador a un equipo específico
    void agregarJugadorAEquipo(const std::string& nombreEquipo, const Jugador& jugador) {
        for (int i = 0; i < numeroEquipos; i++) {
            if (equipos[i] && equipos[i]->nombre == nombreEquipo) {
                for (int j = 0; j < equipos[i]->numeroJugadores; j++) {
                    if (equipos[i]->jugadores[j].nombre.empty()) {
                        equipos[i]->jugadores[j] = jugador;
                        break;
                    }
                }
            }
        }
    }
};

int main() {
    Torneo torneo(4, 11);

    // Ejemplo de uso:
    torneo.createEquipo("Equipo A");
    torneo.createEquipo("Equipo B");
    torneo.createEquipo("Equipo C");
    torneo.createEquipo("Equipo D");

    Jugador jugador1 = { "Jugador 1", 1, "Delantero", 0.8 };
    torneo.agregarJugadorAEquipo("Equipo A", jugador1);

    Jugador jugador2 = { "Jugador 2", 2, "Defensor", 0.7 };
    torneo.agregarJugadorAEquipo("Equipo B", jugador2);

    torneo.mostrarTabla();

    torneo.updateEquipo("Equipo A", 5, 2, 3, 18);
    torneo.updateEquipo("Equipo B", 4, 3, 3, 15);
    torneo.updateEquipo("Equipo C", 3, 4, 3, 12);
    torneo.updateEquipo("Equipo D", 2, 5, 3, 9);

    torneo.mostrarTabla();
    torneo.deleteEquipo("Equipo D");
    torneo.mostrarTabla();
    torneo.createEquipo("ValentinoFC");
    torneo.mostrarTabla();
    torneo.updateEquipo("ValentinoFC", 1, 1, 1, 33);
    torneo.mostrarTabla();

    torneo.readEquipo("Equipo A");
    torneo.readJugador("Equipo B", "Jugador 2");
    torneo.updateJugador("Equipo B", "Jugador 2", 2, "Hola", 0.9);
    torneo.readJugador("Equipo B", "Jugador 2");

    torneo.deleteJugador("Equipo B", "Jugador 2");
    torneo.readJugador("Equipo B", "Jugador 2");

    return 0;
}
