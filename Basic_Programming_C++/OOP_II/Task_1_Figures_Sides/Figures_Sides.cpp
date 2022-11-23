//Task: Design and realize classes that describ the subject area.

#include <iostream>

using namespace std;

//SOLUTION with no private fields

//class Figure {
//protected:
//	int sides = 0;
//	string figure_name = "Figure";
//public:
//	Figure() = default;
//
//	int get_sides() const {
//		return this->sides;
//	}
//
//	string get_name() const {
//		return this->figure_name;
//	}
//};
//
//class Triangle : public Figure {
//public:
//	Triangle() {
//		this->sides = 3;
//		this->figure_name = "Triangle";
//	}
//};
//
//class Quadrangle : public Figure {
//public:
//	Quadrangle() {
//		this->sides = 4;
//		this->figure_name = "Quadrangle";
//	}
//};

class Figure {
	private:
			int sides = 0;
			string figure_name;
	protected:
			Figure(int sides, string name) {
				this->sides = sides;
				this->figure_name = name;
			};

	public:
			Figure() : Figure(0, "Figure") {};

			int get_sides() const {
				return this->sides;
			}

			string get_name() const {
				return this->figure_name;
			}

};

class Triangle : public Figure {
	public:
			Triangle() : Figure(3, "Triangle") {};
};

class Quadrangle : public Figure {
	public:
			Quadrangle() : Figure(4, "Quadrangle") {};
};

int main(int argc, char** argv) {
	Figure figure;
	Triangle triangle;
	Quadrangle quadrangle;

	cout << "SIDES NUMBER:" << endl;
	cout << figure.get_name() << ":\t\t" << figure.get_sides() << endl;
	cout << triangle.get_name() << ":\t" << triangle.get_sides() << endl;
	cout << quadrangle.get_name() << ":\t" << quadrangle.get_sides() << endl;

	return 0;
}