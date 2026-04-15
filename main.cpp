#include <iostream>
#include "core_numeric.h"

int main() {
    std::cout << "RESULTADOS:" << std::endl;
    std::cout << "Suma: " << core_numeric::sum(v) << std::endl;
    std::cout << "Promedio: " << core_numeric::mean(v) << std::endl;
    std::cout << "Maximo: " << core_numeric::max(v) << std::endl;
    std::cout << "Varianza: " << core_numeric::variance(v) << std::endl;

    std::cout << "\nVARIADICAS" << std::endl;
    std::cout << "Suma variádica: " << core_numeric::sum_variadic(1,2,3,4,5) << std::endl;
    std::cout << "Max variádico: " << core_numeric::max_variadic(3,7,2,9,1,5) << std::endl;

    std::cout << "\nTRANSFORMADA REDUCIDA" << std::endl;
    auto cuadrados = core_numeric::transform_reduce(v, [](int x) { return x * x; });
    std::cout << "Suma de cuadrados: " << cuadrados << std::endl;
    return 0;
}