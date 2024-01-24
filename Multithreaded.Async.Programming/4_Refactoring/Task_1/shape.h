#include<vector>
#include<cmath>

struct Data {
	Data(int x_ , int y_ , int z_ = 0, double R_ = 0, double H_ = 0) :x(x_), y(y_), z(z_), R(R_), H(H_) {}
	int x, y, z;
	double R, H;
};

class Shape {
protected:	
	void init(const std::initializer_list<Data>& vect, int size) {
		if (vect.size() != size)
			throw"error data";
		for (auto& data : vect) {
			vec.push_back(data);
		}
	}	
public:
	Shape() {}
	std::vector<Data>vec;
	double square = 0;
	double volume = 0;
	double height = 0;
	double radius = 0;

	Shape transform_shift(int x, int y, int z) {
		for (auto& coord : vec) {
			coord.x += x; coord.y += y; coord.z += z;
		}
		return *this;
	}

	Shape transform_scaleX(int x) {
		for (auto& coord : vec) {
			coord.x += x;
		}
		return *this;
	}

	Shape transform_scaleY(int y) {
		for (auto& coord : vec) {
			coord.y += y;
		}
		return *this;
	}

	Shape transform_scaleZ(int z) {
		for (auto& coord : vec) {
			coord.z += z;
		}
		return *this;
	}

	Shape transform_scale(int s) {
		if (s == 0)
			throw "division by 0";
		for (auto& coord : vec) {
			coord.x /= s; coord.y /= s; coord.z /= s;
		}
		return *this;
	}
};

class Liniya :public Shape {
public:
	Liniya() {}
	Liniya(const std::initializer_list<Data>& vect) {
		init(vect,2);
	}
};

class Pryamougolnic :public Shape {
protected:
	int A() { return vec[0].x - vec[1].x; }
	int B() { return vec[0].y - vec[1].y; }
public:
	Pryamougolnic() {}
	Pryamougolnic(const std::initializer_list<Data>& vect) {
		init(vect,4);
		square = A() * B();
	}

};

class Parallelepiped :public Pryamougolnic {
protected:
	int C() { return vec[0].z - vec[1].z; }
public:
	Parallelepiped() {}
	Parallelepiped(const std::initializer_list<Data>& vect) {		
		init(vect,8);
		square = 2 * A()* B() + 2 * A() * C() + 2 * B() * C();
		volume = A() * B() * C();
	}
};

class Krug :public Shape {
protected:
	void init_r_h() {
		radius = vec[0].R;
		height = vec[0].H;
	}
	double S() {
		return 3.1415 * vec[0].R * vec[0].R;
	}
public:
	Krug() {}
	Krug(const std::initializer_list<Data>& vect) {
		init(vect,1);
		init_r_h();
		square = S();
	}
};

class Cylinder :public Krug {	
public:
	Cylinder() {}
	Cylinder(const std::initializer_list<Data>& vect) {
		init(vect,1);
		init_r_h();
		square = S()+2*radius*height;
		volume = S() * height;
	}
};





































//#define _USE_MATH_DEFINES
//#include"shape.h"
//#include<cmath>
//Shape::Shape(int type_, std::vector<Data>& vec_) :type(type_), vec(vec_) {
//	int a, b, c;
//	if (type_ < circle) {
//		if (vec.size() < 2)
//			throw"error Data";
//		 a = abs(vec[0].x - vec[1].x);
//		 b = abs(vec[0].y - vec[1].y);
//		 c = abs(vec[0].z - vec[1].z);
//	}
//	switch (type)
//	{	
//	case sqr:
//		square = a * b;		
//		break;
//	case cube:
//		square = 2 * a * b + 2 * a * c + 2 * b * c;
//		volume = a * b * c;
//		break;
//	case circle:
//		radius = vec[0].R;
//		square = M_PI * vec[0].R * vec[0].R;		
//		break;
//	case cylinder:
//		radius = vec[0].R;
//		height = vec[0].H;
//		square = M_PI * vec[0].R * vec[0].R + 2 * vec[0].R * height;
//		volume = M_PI * vec[0].R * vec[0].R * height;
//		break;
//	default:
//		break;
//	};
//}
//
//Shape Shape::transform_shift(int x, int y, int z){
//	for (auto& coord : vec) {
//		coord.x += x; coord.y += y; coord.z += z; 
//	}
//	return *this;
//}
//
//Shape Shape::transform_scaleX(int x){
//	for (auto& coord : vec) {
//		coord.x += x;
//	}
//	return *this;
//}
//
//Shape Shape::transform_scaleY(int y){
//	for (auto& coord : vec) {
//		coord.y += y;
//	}
//	return *this;
//}
//
//Shape Shape::transform_scaleZ(int z){
//	for (auto& coord : vec) {
//		coord.z += z;
//	}
//	return *this;
//}
//
//Shape Shape::transform_scale(int s){
//	if (s == 0)
//		throw "division by 0";
//	for (auto& coord : vec) {
//		coord.x /= s; coord.y /= s; coord.z /= s;
//	}
//	return *this;
//}