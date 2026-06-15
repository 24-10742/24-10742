#include <iostream>
#include <string>
#include "io_modulo.h"
#include "kmeans.h"

// El ejecutable se invoca: cluster <k> <datos> [cite: 46, 47]
int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Uso: cluster <k> <datos>" << std::endl;
        return 1;
    }

    int k = std::stoi(argv[1]);
    std::string archivoDatos = argv[2];

    // El vector no debe ser modificado una vez cargado [cite: 61]
    const std::vector<Coord_3D> datos = cargarDatos(archivoDatos);

    if (datos.empty()) {
        std::cerr << "No se pudieron cargar los datos." << std::endl;
        return 1;
    }

    ejecutarKMeans(datos, k);

    std::cout << "Clasificacion completada. Revise clasificados.csv y summary.txt" << std::endl;

    return 0;
}
