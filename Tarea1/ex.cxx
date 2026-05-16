#include <iostream>
#include <vector>
#include <numeric> // Necesaria para accumulate
#include <cmath>   // Para operaciones matemáticas

using namespace std;

// Ejercicio 3: Promedio y Varianza

// Calcula el promedio: suma de elementos dividida entre el total
double mean(const vector<double>& data) {
    if (data.empty()) return 0.0;
    double sum = accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}

// Calcula la varianza: promedio de los cuadrados de las desviaciones
double variance(const vector<double>& data) {
    if (data.empty()) return 0.0;
    
    double m = mean(data);
    double cumulative_sum = 0.0;
    
    for (double x : data) {
        cumulative_sum += (x - m) * (x - m);
    }
    
    return cumulative_sum / data.size();
}
