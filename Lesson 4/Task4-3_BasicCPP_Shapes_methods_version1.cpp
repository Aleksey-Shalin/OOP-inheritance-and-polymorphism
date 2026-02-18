// Задача 3. Фигуры.Методы
// В этом задании вы добавите в вашу иерархию классов больше функциональности.
// Теперь ваши фигуры должны уметь немного больше :выводить информацию о себе; проверять правильность своих данных.

#include <iostream>
#include <string>

// базовый класс Фигура
class Figure {
protected:         // установлен уровень доступа protected, т.к. эти поля доступны во всех классах-наследниках (Triangle, Quadrilateral) и не доступен из внешнего кода (main)
    std::string name;
    int sides_count;

public:
    Figure() {       // конструктор без параметров инициализирует поля объекта
        name = "Фигура"; 
        sides_count = 0;
    }

    // виртуальный метод для вывода сторон
    virtual void output_sides() const {
        // у базовой фигуры не выводится на экран
    }

    // виртуальный метод для вывода углов
    virtual void output_angles() const {
        // у базовой фигуры не выводится на экран
    }

    // Виртуальный метод проверки правильности
    virtual bool is_correct() const {
        return true; // базовая фигура всегда правильная
    }

    // Метод вывода информации
    void print_info() const {
        std::cout << name << ":" << std::endl;

        if (is_correct())
            std::cout << "Правильная" << std::endl;
        else
            std::cout << "Неправильная" << std::endl;

        std::cout << "Количество сторон: " << sides_count << std::endl;

        output_sides();
        output_angles();

        std::cout << std::endl;
    }

    virtual ~Figure() {} // виртуальный деструктор для гарантии, что будет вызван правильный деструктор для данного типа объекта
};

// О треугольниках
class Triangle : public Figure {    // класс Triangle наследует все свойства и методы от Figure
protected:       // установлен уровень доступа protected, т.к. эти поля нужны классам-наследникам (RightTriangle, IsoscelesTriangle и т.д.):
    int a, b, c;   //  длины сторое
    int A, B, C;   // величины углов

public:
    Triangle(int a, int b, int c, int A, int B, int C) {  // заголовок конструктора, название совпадает с названием класса Triangle

        // указатель this на текущий объект используется для решения проблемы одинаковых имён у параметров конструктора и полей класса
        this->name = "Треугольник";  // указатель на поле name из базового класса Figure, в которое записывается строка "Треугольник"
        this->sides_count = 3; // указатель на поле sides_count из базового класса. Здесь стоит 3, т.к. у треугольника всегда 3 стороны
        this->a = a; // в поле a записывается значение параметра a
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    void output_sides() const override {    // вывод сторон на консоль, метод ничего не меняет в объекте (const), override переопределяет виртуальный метод из базового класса во избежание ошибок и опечаток
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
    }

    void output_angles() const override {   // вывод углов на консоль, аналогично прошлому методу
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    }

    bool is_correct() const override {   // метод is_correct() для проверки, является ли треугольник "правильным
        return (sides_count == 3) && (A + B + C == 180);
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B, int C)
        : Triangle(a, b, c, A, B, C) {
        name = "Прямоугольный треугольник";
    }

    bool is_correct() const override {
        return Triangle::is_correct() && (C == 90);
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int c, int A, int B, int C)
        : Triangle(a, b, c, A, B, C) {
        name = "Равнобедренный треугольник";
    }

    bool is_correct() const override {
        return Triangle::is_correct() && (a == c) && (A == C);
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a, int b, int c, int A, int B, int C)
        : Triangle(a, b, c, A, B, C) {
        name = "Равносторонний треугольник";
    }

    bool is_correct() const override {
        return Triangle::is_correct() && (a == b) && (b == c) &&
            (A == 60) && (B == 60) && (C == 60);
    }
};

// О четырёхугольниках

class Quadrilateral : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) {
        this->name = "Четырёхугольник";
        this->sides_count = 4;
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }

    void output_sides() const override {
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
    }

    void output_angles() const override {
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }

    bool is_correct() const override {
        return (sides_count == 4) && (A + B + C + D == 360);
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(int a, int b, int c, int d, int A, int B, int C, int D)
        : Quadrilateral(a, b, c, d, A, B, C, D) {
        name = "Прямоугольник";
    }

    bool is_correct() const override {
        return Quadrilateral::is_correct() &&
            (a == c) && (b == d) &&
            (A == 90) && (B == 90) && (C == 90) && (D == 90);
    }
};

class Square : public Quadrilateral {
public:
    Square(int a, int b, int c, int d, int A, int B, int C, int D)
        : Quadrilateral(a, b, c, d, A, B, C, D) {
        name = "Квадрат";
    }

    bool is_correct() const override {
        return Quadrilateral::is_correct() &&
            (a == b) && (b == c) && (c == d) &&
            (A == 90) && (B == 90) && (C == 90) && (D == 90);
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D)
        : Quadrilateral(a, b, c, d, A, B, C, D) {
        name = "Параллелограмм";
    }

    bool is_correct() const override {
        return Quadrilateral::is_correct() &&
            (a == c) && (b == d) &&
            (A == C) && (B == D);
    }
};

class Rhombus : public Quadrilateral {
public:
    Rhombus(int a, int b, int c, int d, int A, int B, int C, int D)
        : Quadrilateral(a, b, c, d, A, B, C, D) {
        name = "Ромб";
    }

    bool is_correct() const override {
        return Quadrilateral::is_correct() &&
            (a == b) && (b == c) && (c == d) &&
            (A == C) && (B == D);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    // создание массива указателей на базовый класс
    Figure* figures[11];

    // создание фигур через массивы
    figures[0] = new Figure();
    figures[1] = new Triangle(10, 20, 30, 50, 60, 70);
    figures[2] = new RightTriangle(10, 20, 30, 50, 60, 90);
    figures[3] = new RightTriangle(10, 20, 30, 50, 40, 90);
    figures[4] = new IsoscelesTriangle(10, 20, 10, 50, 60, 50);
    figures[5] = new EquilateralTriangle(30, 30, 30, 60, 60, 60);
    figures[6] = new Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    figures[7] = new Rectangle(10, 20, 10, 20, 90, 90, 90, 90);
    figures[8] = new Square(20, 20, 20, 20, 90, 90, 90, 90);
    figures[9] = new Parallelogram(20, 30, 20, 30, 30, 40, 30, 40);
    figures[10] = new Rhombus(30, 30, 30, 30, 30, 40, 30, 40);

    // вывод информации о фигурах
    for (int i = 0; i < 11; i++) {
        figures[i]->print_info();
    }

    // очистка памяти
    for (int i = 0; i < 11; i++) {
        delete figures[i];
    }

    return 0;
}