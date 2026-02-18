#include <iostream>
#include <string>
#include <cmath>

// базовый класс Фигура
class Figure {
protected:
    std::string name;
    int sides_count;

public:
    Figure() {
        name = "Фигура";
        sides_count = 0;
    }

    virtual bool check() {
        return sides_count == 0;
    }

    virtual void print_info() {
        std::cout << name << ":" << std::endl;
        if (check()) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << sides_count << std::endl;
    }

    virtual ~Figure() {}
};

// Класс Треугольник
class Triangle : public Figure {
protected:
    double a, b, c;  // стороны
    double A, B, C;  // углы

public:
    Triangle(double a, double b, double c, double A, double B, double C) {
        name = "Треугольник";
        sides_count = 3;
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    bool check() override {
        // Проверяем, что сумма углов равна 180
        double sum_angles = A + B + C;
        return (sides_count == 3) && (sum_angles == 180);
    }

    void print_info() override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    }
};

// Прямоугольный треугольник
class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c, double A, double B)
        : Triangle(a, b, c, A, B, 90) {
        name = "Прямоугольный треугольник";
    }

    bool check() override {
        // Проверяем условия треугольника + угол C = 90
        return Triangle::check() && (C == 90);
    }
};

// Равнобедренный треугольник
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double c, double A, double B, double C)
        : Triangle(a, b, c, A, B, C) {
        name = "Равнобедренный треугольник";
    }

    bool check() override {
        // Проверка условий треугольника + стороны a и c равны, углы A и C равны
        return Triangle::check() && (a == c) && (A == C);
    }
};

// Равносторонний треугольник
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side)
        : Triangle(side, side, side, 60, 60, 60) {
        name = "Равносторонний треугольник";
    }

    bool check() override {
        // Проверяем условия треугольника + все стороны равны, все углы равны 60
        return Triangle::check() && (a == b) && (b == c) && (A == 60) && (B == 60) && (C == 60);
    }
};

// Класс Четырехугольник
class Quadrilateral : public Figure {
protected:
    double a, b, c, d;  // стороны
    double A, B, C, D;  // углы

public:
    Quadrilateral(double a, double b, double c, double d,
        double A, double B, double C, double D) {
        name = "Четырёхугольник";
        sides_count = 4;
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }

    bool check() override {
        // Проверка, что сумма углов равна 360
        double sum_angles = A + B + C + D;
        return (sides_count == 4) && (sum_angles == 360);
    }

    void print_info() override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }
};

// Прямоугольник
class Rectangle : public Quadrilateral {
public:
    Rectangle(double a, double b)
        : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {
        name = "Прямоугольник";
    }

    bool check() override {
        // Проверка условий четырехугольника + противоположные стороны равны и все углы 90
        return Quadrilateral::check() && (a == c) && (b == d) &&
            (A == 90) && (B == 90) && (C == 90) && (D == 90);
    }
};

// Квадрат
class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {
        name = "Квадрат";
    }

    bool check() override {
        // Проверка условий прямоугольника + все стороны равны
        return Rectangle::check() && (a == b);
    }
};

// Параллелограмм
class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {
        name = "Параллелограмм";
    }

    bool check() override {
        // Проверка условий четырехугольника + противоположные стороны и углы равны
        return Quadrilateral::check() && (a == c) && (b == d) && (A == C) && (B == D);
    }
};

// Ромб
class Rhomb : public Parallelogram {
public:
    Rhomb(double side, double A, double B)
        : Parallelogram(side, side, A, B) {
        name = "Ромб";
    }

    bool check() override {
        // Проверяем условия параллелограмма + все стороны равны
        return Parallelogram::check() && (a == b);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    // Создаем объекты всех фигур
    Figure figure;
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle rightTriangle1(10, 20, 30, 50, 60);  // неправильный
    RightTriangle rightTriangle2(10, 20, 30, 50, 40);  // правильный
    IsoscelesTriangle isoscelesTriangle(10, 20, 10, 50, 60, 50);  // неправильный
    EquilateralTriangle equilateralTriangle(30);  // правильный
    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);  // неправильный
    Rhomb rhomb(30, 30, 40);  // неправильный

    // вывод информацию о каждой фигуре
    std::cout << "Фигура:" << std::endl;
    figure.print_info();
    std::cout << std::endl;

    std::cout << "Треугольник:" << std::endl;
    triangle.print_info();
    std::cout << std::endl;

    std::cout << "Прямоугольный треугольник (неправильный):" << std::endl;
    rightTriangle1.print_info();
    std::cout << std::endl;

    std::cout << "Прямоугольный треугольник (правильный):" << std::endl;
    rightTriangle2.print_info();
    std::cout << std::endl;

    std::cout << "Равнобедренный треугольник:" << std::endl;
    isoscelesTriangle.print_info();
    std::cout << std::endl;

    std::cout << "Равносторонний треугольник:" << std::endl;
    equilateralTriangle.print_info();
    std::cout << std::endl;

    std::cout << "Четырёхугольник:" << std::endl;
    quadrilateral.print_info();
    std::cout << std::endl;

    std::cout << "Прямоугольник:" << std::endl;
    rectangle.print_info();
    std::cout << std::endl;

    std::cout << "Квадрат:" << std::endl;
    square.print_info();
    std::cout << std::endl;

    std::cout << "Параллелограмм:" << std::endl;
    parallelogram.print_info();
    std::cout << std::endl;

    std::cout << "Ромб:" << std::endl;
    rhomb.print_info();
    std::cout << std::endl;

    return 0;
}