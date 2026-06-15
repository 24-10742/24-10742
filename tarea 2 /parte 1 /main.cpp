#include <iostream>
#include <string>
#include <vector>
#include "io_modulo.h"
#include "kmeans.h"
#include "estructuras.h"

// El ejecutable se debe invocar como: cluster <k> <datos> [cite: 46]
int main(int argc, char* argv[]) {
    // Valida que se pasen exactamente los argumentos requeridos [cite: 46]
    if (argc != 3) {
        std::cerr << "Uso: cluster <k> <datos>" << std::endl;
        return 1;
    }

    int k = std::stoi(argv[1]);
    std::string archivoDatos = argv[2];

    // El cargador pone los datos en un vector que no debe ser modificado (const) [cite: 61]
    const std::vector<Coord_3D> datos = cargarDatos(archivoDatos);

    if (datos.empty()) {
        std::cerr << "Error: No se pudieron cargar los datos o el archivo está vacío." << std::endl;
        return 1;
    }

    // Se difiere la lógica al módulo del algoritmo [cite: 43]
    ejecutarKMeans(datos, k);

    std::cout << "Clasificación completada. Revise clasificados.csv y summary.txt" << std::endl;

    return 0;
}
