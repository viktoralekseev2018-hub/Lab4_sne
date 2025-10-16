#include <iostream>
#include <iomanip>
#include <cmath>

double f(double x) {
    return x * x - sin(x) - 2;
}

double half_division(double a, double b, double epsilon, int max_iterations) {
    if (f(a) * f(b) > 0) {
        std::cout << "Ошибка: функция не меняет знак на концах отрезка" << std::endl;
        return NAN;
    }

    double x;
    for (int i = 1; i <= max_iterations; i++) {
        x = (a + b) / 2;

        std::cout << "Итерация " << i << ": x = " << std::setprecision(10) << x
                  << ", f(x) = " << f(x)
                  << ", отрезок [" << a << ", " << b << "]" << std::endl;

        if (fabs(f(x)) < epsilon || (b - a) < epsilon) {
            std::cout << "Корень найден с точностью " << epsilon << " за " << i << " итераций" << std::endl;
            return x;
        }

        if (f(a) * f(x) < 0) {
            b = x;
        } else {
            a = x;
        }
    }

    std::cout << "Достигнуто максимальное количество итераций" << std::endl;
    return x;
}

int main() {
    std::cout << "Метод половинного деления:\n";
    double root = half_division(-3.0, -1.0, 1e-6, 50);
    std::cout << "Найденный корень: " << std::setprecision(10) << root << std::endl;
    return 0;
}
