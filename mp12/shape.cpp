#include "shape.hpp"



//Base class
//Please implement Shape's member functions
//constructor, getName()
//
//Base class' constructor should be called in derived classes'
//constructor to initizlize Shape's private variable 

string Shape::getName(){
	return name;
}

Shape::Shape(string name){
	name_ = name;
}



//Rectangle
//Please implement the member functions of Rectangle:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here

Rectangle::Rectangle(double width, double length):Shape("Rectangle"){
	width_ = width;
	length_ = length;
}

double Rectangle::getArea()const{
	return length_ width_;
}

double Rectangle::getVolume()const{
	return 0;
}

Rectangle Rectangle::operator + (const Rectangle& rect){
	Rectangle r = Rectangle(0.0, 0.0);
	r.width_ = width + rec.width_;
	r.length_ = length + rec.length_;
	return r;
}

Rectangle Rectangle::operator - (const Rectangle& rect){
	Rectangle c = Rectangle(0.0, 0.0);
	r.width_ = width - rec.width_;
	r.length_ = length - rec.length_;
	return r;
}


double Rectangle::getWidth()const{return width_;}
double Rectangle::getLength()const{return length_;}


//Circle
//Please implement the member functions of Circle:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here

Circle:Circle(double radius):Shape("Circle"){
	radius_ = radius;
}

double Circle::getArea()const{
	return radius_ * radius_ * M_PI;
}

double Circle::getVolume()const{
	return 0;
}

Circle Circle::operator + (const Circle& circ){
	Circle r = Circle(0.0);
	r.radius_ = max(0.0, radius_ - circ.radius_);
	return r;
}

double Circle::getRadius()const{return radius_;}

//Sphere
//Please implement the member functions of Sphere:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here



double Sphere::getRadius()const{return radius_;}

//Rectprism
//Please implement the member functions of RectPrism:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here


double RectPrism::getWidth()const{return width_;}
double RectPrism::getHeight()const{return height_;}
double RectPrism::getLength()const{return length_;}


 
// Read shapes from test.txt and initialize the objects
// Return a vector of pointers that points to the objects 
vector<Shape*> CreateShapes(char* file_name){
	//@@Insert your code here
	return vector<Shape*>(0, NULL); // please remeber to modify this line to return the correct value
}

// call getArea() of each object 
// return the max area
double MaxArea(vector<Shape*> shapes){
	double max_area = 0;
	//@@Insert your code here
	
	return max_area;
}


// call getVolume() of each object 
// return the max volume
double MaxVolume(vector<Shape*> shapes){
	double max_volume = 0;
	//@@Insert your code here

	
	return max_volume;
}

