#include <iostream>
//using namespace std; <--- redundant

struct Point { // point -> Point
	double m_x;
	double m_y;
	Point(double x, double y) {
		m_x = x;
		m_y = y; // y ---> m_y 
	}
}; // added ';'

void print_point(const Point& point_object) {
	std::cout << "x:" << point_object.m_x << ", y: "
		<< point_object.m_y << std::endl;
}

// duplication removed
//void print_point(const point& point_object) {
//	std::cout << "x:" << point_object.m_x << ", y: "
//		<< point_object.m_y << std::endl;
//}

int main() { // Main() ---> main()
	//'int i' moved to the 'for' cycle
	for (int i = 0; i < 5; i++) { // i ---> int i, deleted ';'
		Point my_point(i, 2 * i);
		print_point(my_point);
	}
	return 0;
}