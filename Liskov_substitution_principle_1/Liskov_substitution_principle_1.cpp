#include <iostream>
#include <memory>

// Базовий клас Shape
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

// Прямокутник
class Rectangle : public Shape {
protected:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    void setWidth(double w) { width = w; }
    void setHeight(double h) { height = h; }
    double area() const override {
        return width * height;
    }
};

// Квадрат
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    void setSide(double s) { side = s; }
    double area() const override {
        return side * side;
    }
};

// Функція для виведення площі
void printArea(const Shape& shape) {
    std::cout << "Area: " << shape.area() << std::endl;
}

int main() {
    Rectangle rect(4, 5);
    Square square(4);

    printArea(rect);    // Area = 20
    printArea(square);  // Area = 16
    return 0;
}

/*
Порушення принципу LSP
Розглянемо приклад:

Задача:
Реалізувати ієрархію фігур, яка містить базовий клас Rectangle і підклас Square.

#include <iostream>

class Rectangle {
protected:
    double width, height;
public:
    void setWidth(double w) { width = w; }
    void setHeight(double h) { height = h; }
    virtual double area() const { return width * height; }
};

class Square : public Rectangle {
public:
    void setWidth(double w) override {
        width = w;
        height = w; // Сторони квадрата завжди рівні
    }
    void setHeight(double h) override {
        width = h;
        height = h; // Сторони квадрата завжди рівні
    }
};

void printArea(Rectangle& rect) {
    rect.setWidth(4);
    rect.setHeight(5);
    std::cout << "Area: " << rect.area() << std::endl;
}

int main() {
    Rectangle rect;
    Square square;

    printArea(rect);    // Очікувано: Area = 20
    printArea(square);  // Несподівано: Area = 16, а не 20
    return 0;
}
*/