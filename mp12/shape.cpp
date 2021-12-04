#include "shape.hpp"



//Base class
//Please implement Shape's member functions
//constructor, getName()
//
//Base class' constructor should be called in derived classes'
//constructor to initizlize Shape's private variable

string Shape::getName(){
	return name_;
}

Shape::Shape(string name){
	name_ = name;
}



//Rectangle
//Please implement the member functions of Rectangle:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here

Rectangle::Rectangle(double width, double length):Shape("Rectangle"){
	length_ = length;
	width_ = width;
}

double Rectangle::getArea()const{
	return length_ * width_;
}

double Rectangle::getVolume()const{
	return 0;
}

Rectangle Rectangle::operator + (const Rectangle& rect){
	Rectangle r = Rectangle(0.0, 0.0);
	r.length_ = length_ + rect.length_;
	r.width_ = width_ + rect.width_;
	return r;
}

Rectangle Rectangle::operator - (const Rectangle& rect){
	Rectangle r = Rectangle(0.0, 0.0);
	r.length_ = length_ - rect.length_;
	r.width_ = width_ - rect.width_;
	return r;
}


double Rectangle::getWidth()const{return width_;}
double Rectangle::getLength()const{return length_;}


//Circle
//Please implement the member functions of Circle:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here

Circle::Circle(double radius):Shape("Circle"){
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
	r.radius_ = radius_ + circ.radius_;
	return r;
}

Circle Circle::operator - (const Circle& circ){
	Circle r = Circle(0.0);
	r.radius_ = max(0.0, radius_ - circ.radius_);
	return r;
}

double Circle::getRadius()const{return radius_;}

//Sphere
//Please implement the member functions of Sphere:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here

Sphere::Sphere(double radius):Shape("Sphere"){
	radius_ = radius;
}

double Sphere::getArea()const{
	return 4 * radius_ * radius_ * M_PI;
}

double Sphere::getVolume()const{
	return (4.0/3.0) * radius_ * radius_ * M_PI;
}

Sphere Sphere::operator + (const Sphere& sphere){
	Sphere r = Sphere(0.0);
	r.radius_ = radius_ + sphere.radius_;
	return r;
}


Sphere Sphere::operator - (const Sphere& sphere){
	Sphere r = Sphere(0.0);
	r.radius_ = max(0.0, radius_ - sphere.radius_);
	return r;
}

double Sphere::getRadius()const{return radius_;}

//Rectprism
//Please implement the member functions of RectPrism:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here

RectPrism::RectPrism(double width, double length, double height):Shape("RectPrism"){
  length_ = length;
  width_ = width;
  height_ = height;
}

double RectPrism::getArea()const{
	return 2 * ( (length_ * width_) + (length_ * height_) + (width_ * height_) );
}

double RectPrism::getVolume()const{
  return length_ * width_ * height_;
}

RectPrism RectPrism::operator + (const RectPrism& rctpsm){
  RectPrism r = RectPrism(0.0, 0.0, 0.0);
  r.length_ = length_ + rctpsm.length_;
  r.width_ = width_ + rctpsm.width_;
  r.height_ = height_ + rctpsm.height_;
  return r;
}

RectPrism RectPrism::operator - (const RectPrism& rctpsm){
  RectPrism r = RectPrism(0.0, 0.0, 0.0);
  r.length_ = max(0.0, length_ - rctpsm.length_);
  r.width_ = max(0.0, width_ - rctpsm.width_);
  r.height_ = max(0.0, height_ - rctpsm.height_);
  return r;
}

double RectPrism::getWidth()const{return width_;}
double RectPrism::getHeight()const{return height_;}
double RectPrism::getLength()const{return length_;}


 
// Read shapes from test.txt and initialize the objects
// Return a vector of pointers that points to the objects 
vector<Shape*> CreateShapes(char* file_name){
	//@@Insert your code here

	int i, size;
	double value1, value2, value3;
	string name;
	vector<Shape *> v;

	ifstream ifs(file_name, std::ifstream::in);
	ifs>>size;

	for(i = 0; i < size; i++){
		Shape *object;
		ifs>>name;
		if(name == "Rectangle"){
			ifs >> value1 >> value2;
			object = new Rectangle(value1, value2);
		}
		else if(name == "Circle"){
			ifs >> value1;
			object = new Circle(value1);
		}
		else if(name == "Sphere"){
			ifs >> value1;
			object = new Sphere(value1);
		}
		else if(name == "RectPrism"){
			ifs >> value1 >> value2 >> value3;
			object = new RectPrism(value1, value2, value3);
		}

		v.push_back(object);
	}
	
	return v;
	//return vector<Shape*>(0, NULL); // please remeber to modify this line to return the correct value
}

// call getArea() of each object 
// return the max area
double MaxArea(vector<Shape*> shapes){
	double max_area = 0;
	//@@Insert your code here

	int i;
	for(i = 0; i < shapes.size(); i++){
		if(max_area <= shapes[i]->getArea()){
			max_area = shapes[i]->getArea();
		}
	}
	
	return max_area;
}


// call getVolume() of each object 
// return the max volume
double MaxVolume(vector<Shape*> shapes){
	double max_volume = 0;
	//@@Insert your code here

	int i;
	for(i = 0; i < shapes.size(); i++){
		if(max_volume <= shapes[i]->getVolume()){
			max_volume = shapes[i]->getVolume();
		}
	}

	
	return max_volume;
}

/*g++ main.cpp shape.cpp -o mp12
max area = 301.719
max volume = 238.924
g++ -g -c shape.cpp -o shape.o
g++ -g -c verify.cpp -o verify.o
g++ -g verify.o shape.o check.a -o verify_mp12
 

 ------------------- Begin Verifying MP12 ---------------------
Rectangle::operator - incorrect 
Sphere::getVolume() incorrect 
MaxVolume() or Constructors are incorrect
getName() 6/6
Rectangle: 12/16
Circle: 16/16
Sphere: 12/16
RectPrism: 16/16
MaxArea(): 10/10
MaxVolume(): 0/10
CreateShape() 10/10
Your total Socre for MP12: 82/100
-------------------- End Verifying MP12 ----------------------
*/
