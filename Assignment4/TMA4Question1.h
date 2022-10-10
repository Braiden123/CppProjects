/* 
 Title: TMA4Question1.h
 Description: Header file for TMA4Question3.cpp
 Date: Feb. 26 2020
 Author: Braiden Little
 Version: 1.0
 Copyright: 2020 Braiden Little
 Based on TPStash2.h and TStack2.h by Bruce Eckel, Chapter 16
*/

#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159

class Point {
	int x; //X coordinate
	int y; //Y coordinate
public:
	Point() : x(0), y(0) {}
	Point(int xcord, int ycord) : x(xcord), y(ycord) {}
	~Point() {}
	int getx() {return x;}
	int gety() {return y;}
	const Point operator+(const Point& right) const {
		return Point(x + right.x, y + right.y);
	}
	const Point operator-(const Point& right) const { 
		return Point(x - right.x, y - right.y);
	}	
	friend ostream& operator<<(ostream& out, const Point& p);
};

ostream& operator<<(ostream& out, const Point& p) {
	out << "X coordinate: " << p.x << "\n"
	    << "Y coordinate: " << p.y << endl;
	return out;
}

class Shape {
public:
	//Points for bounding box.
	Point* bound1 = new Point(-35, -35);
	Point* bound2 = new Point(35, -35);
	Point* bound3 = new Point(35, 35);
	Point* bound4 = new Point(-35, 35);
	virtual ~Shape();
	virtual double area() = 0;
	virtual void display() = 0;
};

Shape::~Shape() {}

class Circle : public Shape {
	Point* center;
	int radius;
	double shapeArea;
	double shapeCircumference;
public:
	Circle() {center = new Point(0, 0);};
	Circle(int x, int y, int newradius);
	~Circle() {delete center;}
	double area() {shapeArea = round(PI * (radius * radius)); return shapeArea;}
	double circumference() {shapeCircumference = round(2 * PI * radius); return shapeCircumference;}
	void display();
};

class Square : public Shape {
	Point* p1;
	Point* p2;
	Point* p3;
	Point* p4;
	double shapeArea;
public:
	Square() : p1(new Point(0, 0)), p2(new Point(0,1)), p3(new Point(1, 1)), p4(new Point(1, 0)) {}
	Square(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	~Square() {delete p1, p2, p3, p4;}
	double area();
	void display();
};

class Triangle : public Shape {
	Point* p1;
	Point* p2;
	Point* p3;
	double shapeArea;
public:
	Triangle() : p1(new Point(0, 0)), p2(new Point(0,1)), p3(new Point(1, 0)) {}
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
	~Triangle() {delete p1, p2, p3;}
	double area();
	void display();
};