//
// Created by alice on 14/4/2026.
//

#ifndef TAREA_2_SEM2_CORE_NUMERIC_H
#define TAREA_2_SEM2_CORE_NUMERIC_H


#include <vector>
#include <array>
#include <stdexcept>
#include <cmath>
#include <concepts>
#include <iterator>

template<typename C>
concept Iterable = requires(C c) {
    std::begin(c);
    std::end(c);
};

template<typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
};

template<typename T>
concept Divisible = requires(T a, std::size_t n) {
    { a / n } -> std::same_as<T>;
};

// Concept personalizado
template<typename T>
concept Comparable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
};

namespace core_numeric {

// Suma de elementos
template<typename C>
auto sum(const C& container) {
    using T = typename C::value_type;
    T result{};
    for (const auto& value : container) {
        result = result + value;
    }
    return result;
}

// Promedio
template<typename C>
auto mean(const C& container) {
    using T = typename C::value_type;
    auto total = sum(container);
    size_t count = 0;
    for (const auto& _ : container) count++;
    return total / static_cast<T>(count);
}

// Varianza
template<typename C>
auto variance(const C& container) {
    using T = typename C::value_type;
    auto avg = mean(container);
    T sum_sq{};
    for (const auto& value : container) {
        auto diff = value - avg;
        sum_sq = sum_sq + (diff * diff);
    }
    size_t count = 0;
    for (const auto& _ : container) count++;
    return sum_sq / static_cast<T>(count);
}

// Máximo
template<typename C>
auto max(const C& container) {
    using T = typename C::value_type;
    auto it = std::begin(container);
    if (it == std::end(container)) {
        throw std::runtime_error("Container vacío");
    }
    T max_val = *it;
    for (const auto& value : container) {
        if (max_val < value) {
            max_val = value;
        }
    }
    return max_val;
}

// transformada reducida
template<typename C, typename Func>
auto transform_reduce(const C& container, Func&& func) {
    using T = typename C::value_type;
    T result{};
    for (const auto& value : container) {
        result = result + func(value);
    }
    return result;
}

// Funciones variádicas
template<typename T, typename... Args>
auto sum_variadic(T first, Args... args) {
    return (first + ... + args);
}

template<typename T, typename... Args>
auto mean_variadic(T first, Args... args) {
    auto total = sum_variadic(first, args...);
    constexpr size_t count = 1 + sizeof...(Args);
    return total / static_cast<decltype(total)>(count);
}

template<typename T, typename... Args>
auto max_variadic(T first, Args... args) {
    T max_val = first;
    auto update = [&max_val](const auto& val) {
        if (max_val < val) max_val = val;
    };
    (update(args), ...);
    return max_val;
}

}

#endif
