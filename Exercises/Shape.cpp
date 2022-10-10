#include <iostream>

using namespace std;

class Shape {
public:
    Shape() { draw();}
    virtual void draw() = 0;
    virtual ~Shape() { cout << "~Shape()" << endl; }
};

class Circle : public Shape {
public:
    void draw() const { cout << "Circle::draw()" << endl; }
    ~Circle() { cout << "~Circle()" << endl; }
};

class Square : public Shape {
public:
    void draw() const { cout << "Square::draw()" << endl; }
    ~Square() { cout << "~Square()" << endl; }
};

class Triangle : public Shape {
public:
    void draw() const { cout << "Triangle::draw()" << endl; }
    ~Triangle() { cout << "~Triangle()" << endl; }
};

int main() {
    Shape shape;
}