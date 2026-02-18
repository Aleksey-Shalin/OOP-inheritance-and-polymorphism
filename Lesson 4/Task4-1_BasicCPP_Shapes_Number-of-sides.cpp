// Задача 1. Фигуры. Количество сторон
// В этом задании вы построите первую простую иерархию классов для заданной предметной области.
// Задача: спроектировать и реализовать классы, описывающие предметную область.

#include <iostream>

// Основной класс Figure
class Figure {
private:     // полная инкапсуляция, выбран вариант с private, чтобы классы-наследники могли обращаться к членам основного класс только через геттер
    int number_of_sides;

public:
    // конструктор для передачи количества сторон
    Figure(int sides) {
        number_of_sides = sides;
    }

    // метод для получения количества сторон
    int count_figure_sides() {  // единственный способ для внешнего кода узнать количество сторон
        return number_of_sides;
    }
};

// класс для отображения данных о треугольнике
class Triangle : public Figure {    // Triangle наследуется от класса Figure c типом наследования public - все public поля Figure становятся public в Triangle
public:
    Triangle() : Figure(3) {  // вызов конструктора базового класса Figure с аргументом 3
    }

    void output_count_sides() { 
        std::cout << "Треугольник: " << count_figure_sides() << std::endl;  // вызов метода базового класса для получения количества сторон
    }
};

// класс для отображения данных о четырёхугольнике (те же данные, что и Triangle, но с другим значенияем)
class Quadrilateral : public Figure {
public:
    Quadrilateral() : Figure(4) {
    }

    void output_count_sides() {
        std::cout << "Четырёхугольник: " << count_figure_sides() << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    // создание объектов
    Figure indefinite(0);
    Triangle triangle;
    Quadrilateral quadrilateral;

    // вывод информации в консоль
    std::cout << "Количество сторон:" << std::endl;
    std::cout << "Фигура: " << indefinite.count_figure_sides() << std::endl;
    triangle.output_count_sides();
    quadrilateral.output_count_sides();

    return 0;
}