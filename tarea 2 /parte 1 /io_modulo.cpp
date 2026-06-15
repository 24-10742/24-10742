#include "io_modulo.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Coord_3D> cargarDatos(const std::string& nombreArchivo) {
    std::vector<Coord_3D> datos;
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return datos;
    }

    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string valor;
        Coord_3D punto;
        
        if (std::getline(ss, valor, ',')) punto.x = std::stod(valor);
        if (std::getline(ss, valor, ',')) punto.y = std::stod(valor);
        if (std::getline(ss, valor, ',')) punto.z = std::stod(valor);
        
        datos.push_back(punto);
    }
    return datos;
}

void guardarClasificados(const std::vector<Labeled>& datos, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    for (const auto& d : datos) {
        archivo << d.coord.x << "," << d.coord.y << "," << d.coord.z << "," << d.label << "\n";
    }
}
