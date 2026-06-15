#include "kmeans.h"
#include "io_modulo.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <ctime>

double distanciaEuclidiana(const Coord_3D& p1, const Coord_3D& p2) {
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2) + std::pow(p1.z - p2.z, 2));
}

bool condicionParada(const std::vector<Coord_3D>& centroidesAntiguos, const std::vector<Coord_3D>& centroidesNuevos, double tolerancia = 1e-4) {
    for (size_t i = 0; i < centroidesAntiguos.size(); ++i) {
        if (distanciaEuclidiana(centroidesAntiguos[i], centroidesNuevos[i]) > tolerancia) {
            return false;
        }
    }
    return true;
}

void ejecutarKMeans(const std::vector<Coord_3D>& datos, int k) {
    if (datos.empty() || k <= 0 || k > 6) { 
        std::cerr << "Datos inválidos o número de k fuera de rango (máximo 6)." << std::endl;
        return;
    }

    std::vector<Coord_3D> centroides;
    std::srand(std::time(0));
    
    for (int i = 0; i < k; ++i) {
        centroides.push_back(datos[std::rand() % datos.size()]);
    }

    std::vector<int> asignaciones(datos.size(), 0);
    bool convergio = false;

    while (!convergio) {
        for (size_t i = 0; i < datos.size(); ++i) {
            double minDist = std::numeric_limits<double>::max();
            int mejorCluster = 0;
            for (int j = 0; j < k; ++j) {
                double dist = distanciaEuclidiana(datos[i], centroides[j]);
                if (dist < minDist) {
                    minDist = dist;
                    mejorCluster = j;
                }
            }
            asignaciones[i] = mejorCluster;
        }

        std::vector<Coord_3D> nuevosCentroides(k, {0.0, 0.0, 0.0});
        std::vector<int> conteos(k, 0);

        for (size_t i = 0; i < datos.size(); ++i) {
            int clusterIdx = asignaciones[i];
            nuevosCentroides[clusterIdx].x += datos[i].x;
            nuevosCentroides[clusterIdx].y += datos[i].y;
            nuevosCentroides[clusterIdx].z += datos[i].z;
            conteos[clusterIdx]++;
        }

        for (int j = 0; j < k; ++j) {
            if (conteos[j] > 0) {
                nuevosCentroides[j].x /= conteos[j];
                nuevosCentroides[j].y /= conteos[j];
                nuevosCentroides[j].z /= conteos[j];
            }
        }

        convergio = condicionParada(centroides, nuevosCentroides);
        centroides = nuevosCentroides;
    }

    std::vector<Labeled> datosClasificados;
    std::vector<double> dispersiones(k, 0.0);
    std::vector<int> puntosPorCluster(k, 0);

    for (size_t i = 0; i < datos.size(); ++i) {
        int c = asignaciones[i];
        char etiqueta = 'A' + c; 
        datosClasificados.push_back({datos[i], etiqueta});
        
        dispersiones[c] += std::pow(distanciaEuclidiana(datos[i], centroides[c]), 2);
        puntosPorCluster[c]++;
    }

    guardarClasificados(datosClasificados, "clasificados.csv"); 

    std::ofstream summary("summary.txt");
    for (int j = 0; j < k; ++j) {
        char etiqueta = 'A' + j;
        double md = (puntosPorCluster[j] > 0) ? dispersiones[j] / puntosPorCluster[j] : 0.0;
        summary << etiqueta << ": " << puntosPorCluster[j] << ", (" 
                << centroides[j].x << ", " << centroides[j].y << ", " << centroides[j].z 
                << "), " << md << "\n";
    }
}
