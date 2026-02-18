// Задача 2. Фигуры. Стороны и углы
// В этом задании вы усложните иерархию классов для усложнённой предметной области.
// У вас появляется информация о длине сторон и углах ваших фигур, а также несколько более конкретных фигур.

#include <iostream>
#include <string>


// базовый класс Фигуры
class Figure {
protected:     // выбран вариаент с protected, поэтому поле name доступно классу Figure, классам-наследникам (Triangle, Square), но недоступен во внешнем коде
    std::string name;

public:
    Figure(std::string n) : name(n) {}  // конструктор принимает параметр - строку n, поле name инициализируется значением n

    void print_info() {
        std::cout << name << ":" << std::endl;
    }
};

// класс треугольника
class Triangle : public Figure {
private:     // Эти данные должны быть доступны только внутри класса Triangle, внешний код не должен напрямую менять стороны и углы
    double a, b, c;  // длины сторон
    double A, B, C;  // величины углов

public:
    Triangle(double side_a, double side_b, double side_c, 
        double angle_a, double angle_b, double angle_c)
        : Figure("Треугольник"),     // вызов конструктора базового класса
        a(side_a), b(side_b), c(side_c),   // инициализация сторон
        A(angle_a), B(angle_b), C(angle_c)  // инициализация углов
    { 
        // в теле конструктора пусто, т.к. всё делается в списке инициализации
    }

    void print_info() {
        Figure::print_info();
        std::cout << "Стороны: " << a << ", " << b << ", " << c << std::endl;
        std::cout << "Углы: " << A << ", " << B << ", " << C << std::endl;
        std::cout << std::endl;
    }
};

// класс прямоугольного треугольника
class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c, double A, double B)
        : Triangle(a, b, c, A, B, 90) {
        name = "Прямоугольный треугольник";
    }
};

// класс равнобедренного треугольника
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double A, double B)
        : Triangle(a, b, a, A, B, A) {
        name = "Равнобедренный треугольник";
    }
};

// класс равностороннего треугольника
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side)
        : Triangle(side, side, side, 60, 60, 60) {
        name = "Равносторонний треугольник";
    }
};

// класс четырёхугольника
class Quadrilateral : public Figure {
private:
    double a, b, c, d;   // длины сторон
    double A, B, C, D;   // величины углов

public:
    Quadrilateral(double side_a, double side_b, double side_c, double side_d,
        double angle_a, double angle_b, double angle_c, double angle_d)
        : Figure("Четырёхугольник"), a(side_a), b(side_b), c(side_c), d(side_d),
        A(angle_a), B(angle_b), C(angle_c), D(angle_d) {
    }

    void print_info() {
        Figure::print_info();
        std::cout << "Стороны: " << a << ", " << b << ", " << c << ", " << d << std::endl;
        std::cout << "Углы: " << A << ", " << B << ", " << C << ", " << D << std::endl;
        std::cout << std::endl;
    }
};

// класс прямоугольника
class Rectangle : public Quadrilateral {
public:
    Rectangle(double w, double h)
        : Quadrilateral(w, h, w, h, 90, 90, 90, 90) {
        name = "Прямоугольник";
    }
};

// класс квадрата
class Square : public Quadrilateral {
public:
    Square(double side)
        : Quadrilateral(side, side, side, side, 90, 90, 90, 90) {
        name = "Квадрат";
    }
};

// класс параллелограмма
class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {
        name = "Параллелограмм";
    }
};

// класс ромба
class Rhombus : public Quadrilateral {
public:
    Rhombus(double side, double A, double B)
        : Quadrilateral(side, side, side, side, A, B, A, B) {
        name = "Ромб";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    // Создание фигур
    Triangle trian(10, 20, 30, 50, 60, 70);
    trian.print_info();

    RightTriangle right_tri(3, 4, 5, 30, 60);
    right_tri.print_info();

    IsoscelesTriangle isosc_tri(10, 15, 50, 80);
    isosc_tri.print_info();

    EquilateralTriangle equil_tri(20);
    equil_tri.print_info();

    Quadrilateral quadri(10, 20, 30, 40, 50, 60, 70, 80);
    quadri.print_info();

    Rectangle rect(10, 20);
    rect.print_info();

    Square sq(15);
    sq.print_info();

    Parallelogram paral(10, 20, 30, 150);
    paral.print_info();

    Rhombus rhomb(15, 30, 150);
    rhomb.print_info();

    return 0;
}