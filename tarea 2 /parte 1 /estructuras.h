#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

// Estructura requerida para los puntos en 3D
struct Coord_3D {
    double x;
    double y;
    double z;
};

// Estructura requerida para los puntos etiquetados
struct Labeled {
    Coord_3D coord;
    char label;
};

#endif
