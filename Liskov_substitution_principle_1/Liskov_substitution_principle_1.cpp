#include <iostream>
#include <memory>

// ������� ���� Shape
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

// �����������
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

// �������
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

// ������� ��� ��������� �����
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
��������� �������� LSP
���������� �������:

������:
���������� �������� �����, ��� ������ ������� ���� Rectangle � ������ Square.

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
        height = w; // ������� �������� ������ ���
    }
    void setHeight(double h) override {
        width = h;
        height = h; // ������� �������� ������ ���
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

    printArea(rect);    // ���������: Area = 20
    printArea(square);  // ����������: Area = 16, � �� 20
    return 0;
}
*/