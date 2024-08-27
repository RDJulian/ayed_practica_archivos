#include "lector.hpp"
#include <fstream>
#include <iostream>

std::string convertir_ficha(char ficha, std::string ficha_j1, std::string ficha_j2) {
    std::string resultado;
    if (ficha == '0') {
        resultado = '-';
    } else {
        resultado = (ficha == '1' ? ficha_j1 : ficha_j2);
    }
    return resultado;
}

void imprimir_tablero(std::string partida, std::string ficha_j1, std::string ficha_j2) {
    for (int i = 0; i < 3; i++) {
        std::cout << convertir_ficha(partida[i * 3 + 0], ficha_j1, ficha_j2)
                << " " << convertir_ficha(partida[i * 3 + 1], ficha_j1, ficha_j2)
                << " " << convertir_ficha(partida[i * 3 + 2], ficha_j1, ficha_j2)
                << std::endl;
    }
}

void imprimir_partida(std::string partida, std::string jugador1, std::string jugador2, std::string ficha_j1,
                      std::string ficha_j2, std::string resultado) {
    imprimir_tablero(partida, ficha_j1, ficha_j2);
    std::cout << "Jugador 1: " << jugador1 << std::endl;
    std::cout << "Jugador 2: " << jugador2 << std::endl;
    if (resultado == "0") {
        std::cout << "Hubo empate" << std::endl;
    } else {
        std::cout << "Ganó " << (resultado == "1" ? jugador1 : jugador2) << std::endl;
    }
    std::cout << std::endl;
}

void lector::leer_partidas(std::string ruta) {
    std::ifstream archivo(ruta);
    if (archivo.is_open()) {
        std::string ficha_j1;
        std::string ficha_j2;
        std::string partida;
        std::string jugador1;
        std::string jugador2;
        std::string resultado;

        while (std::getline(archivo, ficha_j1, ',')) {
            std::getline(archivo, ficha_j2, ',');
            std::getline(archivo, partida, ',');
            std::getline(archivo, jugador1, ',');
            std::getline(archivo, jugador2, ',');
            std::getline(archivo, resultado);

            imprimir_partida(partida, jugador1, jugador2, ficha_j1, ficha_j2, resultado);
        }
    } else {
        std::cout << "Error: no se pudo leer el archivo." << std::endl;
    }
    archivo.close();
}
