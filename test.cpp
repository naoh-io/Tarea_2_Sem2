//
// Created by alice on 14/4/2026.
//

#include <iostream>
#include <vector>
#include <string>
#include "core_numeric.h"

int main() {
    std::cout << "Casos que si compilan:" << std::endl;

    // 1. Vector de enteros
    std::vector<int> ints = {1, 2, 3, 4, 5};
    std::cout << "sum(ints): " << core_numeric::sum(ints) << std::endl;
    std::cout << "mean(ints): " << core_numeric::mean(ints) << std::endl;
    std::cout << "max(ints): " << core_numeric::max(ints) << std::endl;

    // 2. Vector de doubles
    std::vector<double> doubles = {1.1, 2.2, 3.3};
    std::cout << "sum(doubles): " << core_numeric::sum(doubles) << std::endl;

    // 3. Funciones variádicas
    std::cout << "sum_variadic: " << core_numeric::sum_variadic(1, 2, 3, 4) << std::endl;
    std::cout << "max_variadic: " << core_numeric::max_variadic(10, 20, 5, 30) << std::endl;

    // 4. transform_reduce
    auto squares = core_numeric::transform_reduce(ints, [](int x) { return x * x; });
    std::cout << "suma de cuadrados: " << squares << std::endl;

    // Casos de no compilacion --------------------------

    std::cout << "\nCasos que no compilan:" << std::endl;

    /*
    // CASO 1: std::string no es Addable (no tiene operator+ que retorne el mismo tipo)
    std::vector<std::string> strings = {"hola", "mundo"};
    // auto error1 = core_numeric::sum(strings);
    // error: std::string no cumple Addable

    // CASO 2: int* (puntero) no es Addable
    std::vector<int*> punteros = {new int(1), new int(2)};
    // auto error2 = core_numeric::sum(punteros);
    // error: int* no cumple Addable

    // CASO 3: Clase sin operator< (no cumple Comparable)
    class SinComparacion {
        int val;
    public:
        SinComparacion(int v) : val(v) {}
        SinComparacion operator+(const SinComparacion& other) const {
            return SinComparacion(val + other.val);
        }
        // Falta operator<
    };
    std::vector<SinComparacion> no_comp = {SinComparacion(1), SinComparacion(2)};
    // auto error3 = core_numeric::max(no_comp);
    // error: SinComparacion no cumple Comparable

    // CASO 4: int no es Iterable (no tiene begin/end)
    int single = 42;
    // auto error4 = core_numeric::sum(single);
    // error: int no cumple Iterable

    // CASO 5: string no es Comparable
    std::vector<std::string> palabras = {"a", "b", "c"};
    // auto error5 = core_numeric::max(palabras);
    // error: string no cumple Comparable
    */

    std::cout << "\nTodos los casos que compilaron funcionaron correctamente" << std::endl;

    return 0;
}