#include <iostream>

int main() {
    //1
    std::cout << 3.14 << std::endl;
    //вывод числа пи
    //2
    std::cout << "1 13 49" << std::endl;
    //вывол строки чисел
    //3
    std::cout << "Enter the simbol" << std::endl;
    char simbol;
    std::cin >> simbol;
    std::cout << 1 << simbol << 13 << simbol << 49 << std::endl;
    //строки чисел с символом
    //4
    std::cout << 17<< "  " << 14 << "  " << 567 << std::endl;
    //вывод строки чисел с двумя пробелами между числами
    //5
    double x;
    double y;
    std::cout << "Enter a" << std::endl;
    double a;
    std::cin >> a;
    x=12*a*a + 7*a - 12;
    y=3*x*x*x + 4*x*x - 11*x + 1;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    //формулы
    //6
    double p;
    std::cout << "Enter the mass" << std::endl;
    double m;
    std::cin >> m;
    std::cout << "Enter the amount" << std::endl;
    double v;
    std::cin >> v;
    p= m / v;
    std::cout << p << std::endl;
    return 0;
}
