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
    double cumulative_sum = 0.0
    
    for (double x : data) {
        cumulative_sum += (x - m) * (x - m);
    }
    
    return cumulative_sum / data.size();
}
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

/**
 * Ejercicio 4: Coeficiente de Correlación de Pearson
 * Calcula la relación lineal entre dos conjuntos de datos VA y VB.
 */
double pearson_r(const vector<double>& VA, const vector<double>& VB) {
    // Se asume que VA y VB tienen el mismo tamaño n
    size_t n = VA.size();
    if (n == 0) return 0.0;

    double sum_A = 0.0, sum_B = 0.0, sum_AB = 0.0;
    double sum_A2 = 0.0, sum_B2 = 0.0;

    for (size_t i = 0; i < n; ++i) {
        sum_A += VA[i];
        sum_B += VB[i];
        sum_AB += VA[i] * VB[i];
        sum_A2 += VA[i] * VA[i];
        sum_B2 += VB[i] * VB[i];
    }

    double num = (n * sum_AB) - (sum_A * sum_B);
    double den = sqrt((n * sum_A2 - pow(sum_A, 2)) * (n * sum_B2 - pow(sum_B, 2)));

    // Evitar división por cero si no hay varianza en los datos
    if (den == 0) return 0.0;

    return num / den;
}
// ejercicio 5//
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// --- Funciones Auxiliares Internas ---
// Estas funciones ayudan a las principales para no repetir código

int char_to_int(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return 0;
}

char int_to_char(int n) {
    if (n >= 0 && n <= 9) return n + '0';
    return n - 10 + 'A';
}

// Convierte un número en base 'b' a decimal (int)
int to_decimal_internal(vector<char> s, int base) {
    int res = 0;
    int power = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        res += char_to_int(s[i]) * pow(base, power);
        power++;
    }
    return res;
}

// Convierte un decimal (int) a una base 'b' (vector<char>)
vector<char> from_decimal_internal(int n, int base) {
    if (n == 0) return {'0'};
    vector<char> res;
    while (n > 0) {
        res.push_back(int_to_char(n % base));
        n /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

// --- EJERCICIO 5: Implementación de las funciones solicitadas ---

// 1. Decimal a Sistemas de Pulpos
vector<char> dec_to_septapus(int n) { return from_decimal_internal(n, 7); }
vector<char> dec_to_octopus(int n) { return from_decimal_internal(n, 8); }
vector<char> dec_to_hexakaidecapus(int n) { return from_decimal_internal(n, 16); }

// 2. Sistemas de Pulpos a Decimal (Nota: el retorno pide vector<char>, 
// así que convertimos el int resultado a caracteres decimales)
vector<char> septapus_to_dec(vector<char> s) { 
    int d = to_decimal_internal(s, 7);
    string res = to_string(d);
    return vector<char>(res.begin(), res.end());
}

vector<char> octopus_to_dec(vector<char> s) {
    int d = to_decimal_internal(s, 8);
    string res = to_string(d);
    return vector<char>(res.begin(), res.end());
}

vector<char> hexakaidecapus_to_dec(vector<char> s) {
    int d = to_decimal_internal(s, 16);
    string res = to_string(d);
    return vector<char>(res.begin(), res.end());
}

// 3. Conversiones entre sistemas (Usando decimal como puente)
vector<char> septapus_to_octopus(vector<char> s) {
    return dec_to_octopus(to_decimal_internal(s, 7));
}

vector<char> septapus_to_hexakaidecapus(vector<char> s) {
    return dec_to_hexakaidecapus(to_decimal_internal(s, 7));
}

vector<char> octapus_to_septapus(vector<char> s) {
    return dec_to_septapus(to_decimal_internal(s, 8));
}

vector<char> octopus_to_hexakaidecapus(vector<char> s) {
    return dec_to_hexakaidecapus(to_decimal_internal(s, 8));
}

vector<char> hexakaidecapus_to_septapus(vector<char> s) {
    return dec_to_septapus(to_decimal_internal(s, 16));
}

vector<char> hexakaidecapus_to_octopus(vector<char> s) {
    return dec_to_octopus(to_decimal_internal(s, 16));
}
