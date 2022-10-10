/* 
 Title: TMA4Question1.cpp
 Description: Geometry class heirarchy
 Date: Feb. 14 2020
 Author: Braiden Little
 Version: 1.0
 Copyright: 2020 Braiden Little
 Based on Integer.cpp and IOstreamOperatorOverloading.cpp by Bruce Eckel, Chapter 15
*/

/*
 DOCUMENTATION

 Program Purpose:

    a. Start with a Point class to hold x and y values of a point.
    Overload the << operator to print point values, and the + and – 
    operators to add and subtract point coordinates (Hint: keep x and y separate in the calculation).

    b. Create a pure abstract base class Shape, which will form the
    basis of your shapes. The Shape class will contain abstract functions 
    to calculate area and circumference of the shape, plus provide the 
    coordinates (Points) of a rectangle that encloses the shape (a bounding box). 
    These will be overloaded by the derived classes. Create a display() function 
    that will display the name of the class, and all stored information about 
    the class (including area, circumference, and bounding box).

    c. Build the hierarchy by creating the Shape classes Circle, Square, and Triangle.
     For these derived classes, create default constructors, and constructors whose 
     arguments can initialize the shapes appropriately using the correct number of 
     Point objects (i.e., Circle requires a Point center and a radius, Square requires
     four Point vertices, while Triangle requires three Point vertices).

    d. In main(), create one instance each of the following: Circle (10, -5) with a radius of 23;
     Square (5, -5)(-10,7)(4,23)(-6,12); and Triangle(0,0)(10,10)(-15,15). 
     Display the information from each object.

 Compile: (assuming mingw compiler and opened command prompt): g++ -o TMA4Question1 TMA4Question1.cpp
 Or use the included makefile.

 Execution: (in a Command Prompt window): TMA4Question1.exe (or just TMA4Question1)

 Classes: Point: Used to retain coordinates for points in a shape. 
 				Contains overloaded operators <<,+,and - for calculations and display.
 		  Shape(pure abstract): basis for the Circle, Square, and Triangle classes
 		  Cricle : public Shape: Contains 1 point object as the center of a circle,
 		  						and a radius
								Contains functions for displaying information,
								calculating area, and calculating circumference.
 		  Square : public Shape: Contains 4 point objects to form a square.
								Contains functions for displaying information
								and calculating the area of a square
 		  Triangle : public Shape: Contains 3 point objects to form a triangle.
								Contains functions for displaying information
								and calculating the area of a triangle.

 Variables: x(int), y(int): To record the x and y coordinates in a point object.
 			Circle(radius(int)): To save the radius of the Circle object.
 			shapeArea(double): To save the area of the shape object.
 			shapeCircumference: To save the circumference of a Circle object.
*/

/*
 TEST PLAN

 	Normal Case 1: Circle at point (10,-5) with a radius of 23,
 				   Square with four points (5, -5)(-10,7)(4,23)(-6,12),
				   Triangle with three points (0,0)(10,10)(-15,15).
				   Then display the information of each object.

		Expected Output: All numbers shown are rounded to the nearest whole number
						 or first decimal place in the case of halway points i.e. 10.5.

						 Circle center at point:
						 X coordinate: 10
						 Y coordinate: -5
						 Circle radius: 23
						 Circle area: 1662 cm squared.
						 Circle circumference: 145 centimeters.

						 Point 1 of the square:
						 X coordinate: 5
						 Y coordinate: -5
						 Point 2 of the square:
						 X coordinate: -10
						 Y coordinate: 7
						 Point 3 of the square:
						 X coordinate: 4
						 Y coordinate: 23
						 Point 4 of the square:
						 X coordinate: -6
						 Y coordinate: 12
						 Area of the square: 58.5 cm squared.

						 Point 1 of the triangle:
						 X coordinate: 0
						 Y coordinate: 0
						 Point 2 of the triangle:
						 X coordinate: 10
						 Y coordinate: 10
						 Point 3 of the triangle:
						 X coordinate: -15
						 Y coordinate: 15
						 Area of the triangle: 150 cm squared.

		Actual Output: As expected. (confirmed with calculator)

	Limiting Case 1: Circle at point (-50, 5) with radius of 10.

		Expected Output: terminate called after throwing an instance of 'std::invalid_argument'
 						 what():  Boundries of the circle are outside the square boundry for shapes.

 		Actual Output: As expected.

 	Limiting Case 2: Square with points (-10,-10),(40,-10),(40,30),(-10,30)

 		Expected Output: terminate called after throwing an instance of 'std::invalid_argument'
  						 what():  Boundries of the square are outside the square boundry for shapes.

  		Actual Output: As expected.

  	Limiting Case 3: Triangle with points (0,-40),(15,0),(-10,20)

  		Expected Output: terminate called after throwing an instance of 'std::invalid_argument'
  						 what():  Boundries of the triangle are outside the square boundry for shapes.

  		Actual Output: As expected.
*/

#include <cmath>
#include <iostream>
#include "TMA4Question1.h"
using namespace std;

Circle::Circle(int x, int y, int newradius) {
	//Check if the circle will fit inside the boundries for shapes.
	if (x - newradius < bound1->getx() || x - newradius < bound4->getx() ||
        x + newradius > bound2->getx() || x + newradius > bound3->getx() ||
	    y - newradius < bound1->gety() || y - newradius < bound2->gety() ||
	    y + newradius > bound3->gety() || y + newradius > bound4->gety() )
			throw invalid_argument("Boundries of the circle are outside the square boundry for shapes.");
	center = new Point(x, y);
	radius = newradius;
}

void Circle::display() {
	cout << "Circle center at point: \n" << *center
		 << "Circle radius: " << radius << "\n"
		 << "Circle area: " << area() << " cm squared. \n" 
		 << "Circle circumference: " << circumference()
		 << " centimeters. \n" << endl;
}

Square::Square(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	//Check if the square will fit inside the boundries for shapes.
	if (//Checking first point
		x1 < bound1->getx() || y1 < bound1->gety() ||
		x1 > bound2->getx() || y1 < bound2->gety() ||
		x1 > bound3->getx() || y1 > bound3->gety() ||
		x1 < bound4->getx() || y1 > bound4->gety() ||
		//Checking second point
		x2 < bound1->getx() || y2 < bound1->gety() ||
		x2 > bound2->getx() || y2 < bound2->gety() ||
		x2 > bound3->getx() || y2 > bound3->gety() ||
		x2 < bound4->getx() || y2 > bound4->gety() ||
		//Checking third point
		x3 < bound1->getx() || y3 < bound1->gety() ||
		x3 > bound2->getx() || y3 < bound2->gety() ||
		x3 > bound3->getx() || y3 > bound3->gety() ||
		x3 < bound4->getx() || y3 > bound4->gety() ||
		//Checking fourth point
		x4 < bound1->getx() || y4 < bound1->gety() ||
		x4 > bound2->getx() || y4 < bound2->gety() ||
		x4 > bound3->getx() || y4 > bound3->gety() ||
		x4 < bound4->getx() || y4 > bound4->gety() )
			throw invalid_argument("Boundries of the square are outside the square boundry for shapes.");
	p1 = new Point(x1, y1);
	p2 = new Point(x2, y2);
	p3 = new Point(x3, y3);
	p4 = new Point(x4, y4);
}

/*Uses the formula for the area of a polygon
	
	|(x1y2 - y1x2) + (x2y3 - y2x3) + (x3y4 - y3x4) + (x4y1 - y4x1)|
	|-------------------------------------------------------------|
	|							   2							  |
*/
double Square::area() {
	shapeArea = round(abs( ( (p1->getx() * p2->gety()) - (p1->gety() * p2->getx() ) ) 
		   + ( (p2->getx() * p3->gety()) - (p2->gety() * p3->getx() ) )
		   + ( (p3->getx() * p4->gety()) - (p3->gety() * p4->getx() ) )
		   + ( (p4->getx() * p1->gety()) - (p4->gety() * p1->getx() ) ) ) ) / 2;
	return shapeArea;
}

void Square::display() {
	cout << "Point 1 of the square: \n" << *p1
		 << "Point 2 of the square: \n" << *p2
		 << "Point 3 of the square: \n" << *p3
		 << "Point 4 of the square: \n" << *p4
		 << "Area of the square: " << area()
		 << " cm squared. \n" << endl;
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
	//Check if the triangle will fit inside the boundries for shapes.
	if (//Checking first point
		x1 < bound1->getx() || y1 < bound1->gety() ||
		x1 > bound2->getx() || y1 < bound2->gety() ||
		x1 > bound3->getx() || y1 > bound3->gety() ||
		x1 < bound4->getx() || y1 > bound4->gety() ||
		//Checking second point
		x2 < bound1->getx() || y2 < bound1->gety() ||
		x2 > bound2->getx() || y2 < bound2->gety() ||
		x2 > bound3->getx() || y2 > bound3->gety() ||
		x2 < bound4->getx() || y2 > bound4->gety() ||
		//Checking third point
		x3 < bound1->getx() || y3 < bound1->gety() ||
		x3 > bound2->getx() || y3 < bound2->gety() ||
		x3 > bound3->getx() || y3 > bound3->gety() ||
		x3 < bound4->getx() || y3 > bound4->gety() )
			throw invalid_argument("Boundries of the triangle are outside the square boundry for shapes.");
	p1 = new Point(x1, y1);
	p2 = new Point(x2, y2);
	p3 = new Point(x3, y3);
}

/*Uses the formula for the area of a polygon
	
	|(x1y2 - y1x2) + (x2y3 - y2x3) + (x3y1 - y3x1)|
	|---------------------------------------------|
	|					   2					  |
*/
double Triangle::area() {
	shapeArea = round(abs( ( (p1->getx() * p2->gety()) - (p1->gety() * p2->getx() ) ) 
		   + ( (p2->getx() * p3->gety()) - (p2->gety() * p3->getx() ) )
		   + ( (p3->getx() * p1->gety()) - (p3->gety() * p1->getx() ) ) ) ) / 2;
	return shapeArea;	
}

void Triangle::display() {
	cout << "Point 1 of the triangle: \n" << *p1
		 << "Point 2 of the triangle: \n" << *p2
		 << "Point 3 of the triangle: \n" << *p3
		 << "Area of the triangle: " << area()
		 << " cm squared. \n " << endl;	
}

int main(int argc, char const *argv[]) {
	cout << "\nAll numbers shown are rounded to the nearest "
		 << "whole number \nor first decimal place in the case "
		 << "of halfway points i.e. 10.5. \n" << endl;
	Circle* circle = new Circle(10, -5, 23);
	Square* square = new Square(5, -5, -10, 7, 4, 23, -6, 12);
	Triangle* triangle = new Triangle(0, 0, 10, 10, -15, 15);
	circle->display();
	square->display();
	triangle->display();
	delete circle, square, triangle;
}