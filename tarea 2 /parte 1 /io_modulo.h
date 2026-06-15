#ifndef IO_MODULO_H
#define IO_MODULO_H

#include <vector>
#include <string>
#include "estructuras.h"

std::vector<Coord_3D> cargarDatos(const std::string& nombreArchivo);
void guardarClasificados(const std::vector<Labeled>& datos, const std::string& nombreArchivo);

#endif
