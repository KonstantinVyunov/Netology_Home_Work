#include <iostream>
#include <string>
using namespace std;

class GenericError : public exception {
private:
	const char* error = "Reason: generic error.";
public:
	const char* what() const override { return error; }
};

class TriangleError : public GenericError {
private:
	const char* error = "sum of angles is not 180 degree.";
public:
	const char* what() const override { return error; }
};

class RightTriangleError : public GenericError {
private:
	const char* error = "the angle C is not 90 degree.";
public:
	const char* what() const override { return error; }
};

class IsoscelesTriangleError : public GenericError {
private:
	const char* error = "sides a and c or angles A and C are not equal respectively.";
public:
	const char* what() const override { return error; }
};

class EquilateralTriangleError : public GenericError {
private:
	const char* error = "sides a, b, and c or angles A, B, and C are not equal respectively.";
public:
	const char* what() const override { return error; }
};

class QuadrangleError : public GenericError {
private:
	const char* error = "sum of angles is not 360 degree.";
public:
	const char* what() const override { return error; }
};

class RectangleError : public GenericError {
private:
	const char* error = "sides a, c and b, d are not equal respectively or angles A, B, C, D are not 90 degree.";
public:
	const char* what() const override { return error; }
};

class SquareError : public GenericError {
private:
	const char* error = "sides a, c, b, d are not equal or angles A, B, C, D are not 90 degree.";
public:
	const char* what() const override { return error; }
};

class ParallelogramError : public GenericError {
private:
	const char* error = "sides a, c and b, d are not equal respectively or angles A, C and B, D are not equal respectively.";
public:
	const char* what() const override { return error; }
};

class RhombusError : public GenericError {
private:
	const char* error = "sides a, b, c, d are not equal or angles A, C and B, D are not equal respectively.";
public:
	const char* what() const override { return error; }
};

class Figure { // ÔÈÃÓÐÀ
private:
	string figure_name = "Figure";
	int num_sides = 0, num_angles = 0;
public:
	Figure() = default;

	const void setFigureName(string name) { this->figure_name = name; }
	string getFigureName() const { return this->figure_name; }
	const void setNumSides(int num_sides) { this->num_sides = num_sides; }
	int getNumSides() const { return this->num_sides; }
	const void setNumAngles(int num_angles) { this->num_angles = num_angles; }
	int getNumAngles() const { return this->num_angles; }

	virtual void printSides() const { cout << num_sides; }
	virtual void printAngles() const { cout << num_angles; }

	~Figure() = default;
};

class Triangle : public Figure { // ÒÐÅÓÃÎËÜÍÈÊ
private:
	int length_a{ 0 }, length_b{ 0 }, length_c{ 0 };
	int angle_A{ 0 }, angle_B{ 0 }, angle_C{ 0 };
public:
	Triangle (
		int length_a, int length_b, int length_c,
		int angle_A, int angle_B, int angle_C)
	{
		setFigureName("Triangle");
		setNumSides(3);
		setNumAngles(3);
		setLengthA(length_a);
		setLengthB(length_b);
		setLengthC(length_c);
		setAngleA(angle_A);
		setAngleB(angle_B);
		setAngleC(angle_C);
		if ((angle_A + angle_B + angle_C) != 180) {
			cout << getFigureName()
				 << " (sides " << ' ' << getNumSides() << " - " << getLengthA() << ", " << getLengthB() << ", " << getLengthC() << "; "
				 << "angles " << getNumAngles() << " - " << getAngleA() << ", " << getAngleB() << ", " << getAngleC() << ") is NOT created. ";
			throw TriangleError();
		}
	}
	int getLengthA() const {return this->length_a;}
	int getLengthB() const {return this->length_b;}
	int getLengthC() const {return this->length_c;}
	int getAngleA() const {return this->angle_A;}
	int getAngleB() const {return this->angle_B;}
	int getAngleC() const {return this->angle_C;}
	const void setLengthA(int length_a_) {this->length_a = length_a_;}
	const void setLengthB(int length_b_) {this->length_b = length_b_;}
	const void setLengthC(int length_c_) {this->length_c = length_c_;}
	const void setAngleA(int angle_A_) {this->angle_A = angle_A_;}
	const void setAngleB(int angle_B_) {this->angle_B = angle_B_;}
	const void setAngleC(int angle_C_) {this->angle_C = angle_C_;}

	void printSides() const override {
		cout << getNumSides() << " - " << getLengthA() << ", " << getLengthB() << ", " << getLengthC();
	}
	void printAngles() const override {
		cout << getNumAngles() << " - " << getAngleA() << ", " << getAngleB() << ", " << getAngleC();
	}
	~Triangle() = default;
};

class RightTriangle : public Triangle { // ÏÐßÌÎÓÃÎËÜÍÛÉ ÒÐÅÓÃÎËÜÍÈÊ
public:
	RightTriangle (
		int length_a, int length_b, int length_c,
		int angle_A, int angle_B, int angle_C)
		: Triangle(
			length_a,  length_b,  length_c,
			angle_A,  angle_B,  angle_C)
	{
		setFigureName("RightTriangle");
		if (angle_C != 90) {
			cout << getFigureName()
				 << " (sides " << getLengthA() << ", " << getLengthB() << ", " << getLengthC() << "; "
				 << "angles " << getAngleA() << ", " << getAngleB() << ", " << getAngleC() << ") is NOT created. ";
			throw RightTriangleError();
		}
	}
	~RightTriangle() = default;
};

class IsoscelesTriangle : public Triangle { // ÐÀÂÍÎÁÅÄÐÅÍÍÛÉ ÒÐÅÓÃÎËÜÍÈÊ
public:
	IsoscelesTriangle(
		int length_a, int length_b, int length_c,
		int angle_A, int angle_B, int angle_C)
		: Triangle(
			length_a, length_b, length_c,
			angle_A, angle_B, angle_C)
	{
		setFigureName("IsoscelesTriangle");
		if (!((getAngleA() == getAngleC()) && (getLengthA() == getLengthC()))) {
			cout << getFigureName()
				<< " (sides " << getLengthA() << ", " << getLengthB() << ", " << getLengthC() << "; "
				<< "angles " << getAngleA() << ", " << getAngleB() << ", " << getAngleC() << ") is NOT created. ";
			throw IsoscelesTriangleError();
		}
	}
	~IsoscelesTriangle() = default;
};

class EquilateralTriangle : public IsoscelesTriangle { // ÐÀÂÍÎÑÒÎÐÎÍÍÈÉ ÒÐÅÓÃÎËÜÍÈÊ
public:
	EquilateralTriangle(
		int length_a, int length_b, int length_c,
		int angle_A, int angle_B, int angle_C)
		: IsoscelesTriangle(
			length_a, length_b, length_c,
			angle_A, angle_B, angle_C)
	{
		setFigureName("EquilateralTriangle");
		if (!(((getAngleA() == getAngleB()) && (getAngleA() == getAngleC())) &&
			((getLengthA() == getLengthB()) && (getLengthA() == getLengthC())))) {
			cout << getFigureName()
				<< " (sides " << getLengthA() << ", " << getLengthB() << ", " << getLengthC() << "; "
				<< "angles " << getAngleA() << ", " << getAngleB() << ", " << getAngleC() << ") is NOT created. ";
			throw EquilateralTriangleError();
		}
	}
	~EquilateralTriangle() = default;
};

class Quadrangle : public Figure { // ×ÅÒÛÐ¨ÕÓÃÎËÜÍÈÊ
private:
	int length_a{ 0 }, length_b{ 0 }, length_c{ 0 }, length_d{ 0 };
	int angle_A{ 0 }, angle_B{ 0 }, angle_C{ 0 }, angle_D{ 0 };
public:
	Quadrangle(
		int length_a, int length_b, int length_c, int length_d,
		int angle_A, int angle_B, int angle_C, int angle_D)
	{
		setFigureName("Quadrangle");
		setNumSides(4);
		setNumAngles(4);
		setLengthA(length_a);
		setLengthB(length_b);
		setLengthC(length_c);
		setLengthD(length_d);
		setAngleA(angle_A);
		setAngleB(angle_B);
		setAngleC(angle_C);
		setAngleD(angle_D);
		if ((getAngleA() + getAngleB() + getAngleC() + getAngleD()) != 360) {
			cout << getFigureName()
				<< " (sides " << getNumSides() << " - " << getLengthA() << ", " << getLengthB()
				<< ", " << getLengthC() << ", " << getLengthD() << "; "
				<< "angles " << getNumAngles() << " - " << getAngleA() << ", " << getAngleB()
				<< ", " << getAngleC() << ", " << getAngleD() << ") is NOT created. ";
			throw QuadrangleError();
		}
	}
	int getLengthA() const {return this->length_a;}
	int getLengthB() const {return this->length_b;}
	int getLengthC() const {return this->length_c;}
	int getLengthD() const {return this->length_d;}
	int getAngleA()  const {return this->angle_A;}
	int getAngleB()  const {return this->angle_B;}
	int getAngleC()  const {return this->angle_C;}
	int getAngleD()  const {return this->angle_D;}
	const void setLengthA(int length_a_) { this->length_a = length_a_; }
	const void setLengthB(int length_b_) { this->length_b = length_b_; }
	const void setLengthC(int length_c_) { this->length_c = length_c_; }
	const void setLengthD(int length_d_) { this->length_d = length_d_; }
	const void setAngleA(int angle_A_) { this->angle_A = angle_A_; }
	const void setAngleB(int angle_B_) { this->angle_B = angle_B_; }
	const void setAngleC(int angle_C_) { this->angle_C = angle_C_; }
	const void setAngleD(int angle_D_) { this->angle_D = angle_D_; }

	void printSides() const override {
		cout << getNumSides() << " - " << getLengthA() << ", " << getLengthB() << ", "
			 << getLengthC() << ", " << getLengthD();
	}
	void printAngles() const override {
		cout << getNumAngles()<< " - " << getAngleA() << ", " << getAngleB() << ", "
			 << getAngleC() << ", " << getAngleD();
	}
	~Quadrangle() = default;
};

class Parallelogram : public Quadrangle { // ÏÀÐÀËËÅËÎÃÐÀÌÌ
public:
	Parallelogram(
		int length_a, int length_b, int length_c, int length_d,
		int angle_A, int angle_B, int angle_C, int angle_D)
		: Quadrangle(
			length_a, length_b, length_c, length_d,
			angle_A, angle_B, angle_C, angle_D)
	{
		setFigureName("Parallelogram");
		if (!((getLengthA() == getLengthC() && getLengthB() == getLengthD())
			&& (getAngleA() == getAngleC() && getAngleB() == getAngleD()))) {//ñòîðîíû a,c è b,d ïîïàðíî ðàâíû, óãëû A,C è B,D ïîïàðíî ðàâíû
			cout << getFigureName()
				<< " (sides " << getNumSides() << " - " << getLengthA() << ", " << getLengthB()
				<< ", " << getLengthC() << ", " << getLengthD() << "; "
				<< "angles " << getNumAngles() << " - " << getAngleA() << ", " << getAngleB()
				<< ", " << getAngleC() << ", " << getAngleD() << ") is NOT created. ";
			throw ParallelogramError();
		}
	}
	~Parallelogram() = default;
};

class Rhombus : public Parallelogram { //ÐÎÌÁ
public:
	Rhombus(
		int length_a, int length_b, int length_c, int length_d,
		int angle_A, int angle_B, int angle_C, int angle_D)
		: Parallelogram(
			length_a, length_b, length_c, length_d,
			angle_A, angle_B, angle_C, angle_D)
	{
		setFigureName("Rhombus");
		if (!((getLengthA() == getLengthB() && getLengthC() == getLengthD() && getLengthA() == getLengthC())
			&& ((getAngleA() == getAngleC()) && (getAngleB() == getAngleD())))) {//âñå ñòîðîíû ðàâíû, óãëû A,C è B,D ïîïàðíî ðàâíû
			cout << getFigureName()
				<< " (sides " << getNumSides() << " - " << ' ' << getLengthA() << ", " << getLengthB()
				<< ", " << getLengthC() << ", " << getLengthD() << "; "
				<< "angles " << getNumAngles() << " - " << ' ' << getAngleA() << ", " << getAngleB()
				<< ", " << getAngleC() << ", " << getAngleD() << ") is NOT created. ";
			throw RhombusError();
		}
	}

	~Rhombus() = default;
};

class Rectangle : public Parallelogram { // ÏÐßÌÎÓÃÎËÜÍÈÊ
public:
	Rectangle(
		int length_a, int length_b, int length_c, int length_d,
		int angle_A, int angle_B, int angle_C, int angle_D)
		: Parallelogram(
			length_a, length_b, length_c, length_d,
			angle_A, angle_B, angle_C, angle_D)
	{
		setFigureName("Rectangle");
		if ((getLengthA() != getLengthC() || getLengthB() != getLengthD()) ||
			getAngleA() != 90 || getAngleB() != 90 || getAngleC() != 90 || getAngleD() != 90) {
			cout << getFigureName()
				<< " (sides " << getNumSides() << " - " << getLengthA() << ", " << getLengthB()
				<< ", " << getLengthC() << ", " << getLengthD() << "; "
				<< "angles " << getNumAngles() << " - " << getAngleA() << ", " << getAngleB()
				<< ", " << getAngleC() << ", " << getAngleD() << ") is NOT created. ";
			throw RectangleError();
		}
	}
	~Rectangle() = default;
};

class Square : public Rectangle { // ÊÂÀÄÐÀÒ
public:
	Square(
		int length_a, int length_b, int length_c, int length_d,
		int angle_A, int angle_B, int angle_C, int angle_D)
		: Rectangle(
			length_a, length_b, length_c, length_d,
			angle_A, angle_B, angle_C, angle_D)
	{
		setFigureName("Square");
		if (!((getLengthA() == getLengthB() || getLengthC() == getLengthD() || getLengthA() == getLengthC())
			|| (getAngleA() == getAngleB() || getAngleC() == getAngleD() || getAngleA() == getAngleC()))) {
			cout << getFigureName()
				<< " (sides " << getNumSides() << " - " << getLengthA() << ", " << getLengthB()
				<< ", " << getLengthC() << ", " << getLengthD() << "; "
				<< "angles " << getNumAngles() << " - " << getAngleA() << ", " << getAngleB()
				<< ", " << getAngleC() << ", " << getAngleD() << ") is NOT created. ";
			throw SquareError();
		}
	}
	~Square() = default;
};

void printInfo(Figure *figure) {
	cout << figure->getFigureName() << " (" << "sides ";
	figure->printSides();
	cout << "; " << "angles ";
	figure->printAngles();
	cout << ") was created.";
}

int main(int argc, char** argv) {
	try {
		Figure figure_{};
		printInfo(&figure_);
		std::cout << std::endl;
	}
	catch (const GenericError& error) {
		cerr << "Reason: " << error.what() << endl;
	}
	try {
		Triangle triangle_{10, 20, 30, 50, 60, 70};
		printInfo(&triangle_);
		std::cout << std::endl;
	} catch (const GenericError &error) {
		cerr << "Reason: " << error.what() << endl;
	}
	try {
		RightTriangle right_triangle_{ 10, 20, 30, 30, 60, 90 };
		printInfo(&right_triangle_);
		std::cout << std::endl;
	} catch (const GenericError& error) {
		cerr << "Reason: " << error.what() << endl;
	}
	try {
		IsoscelesTriangle isosceles_triangle_{ 10, 20, 10, 50, 80, 50 };
		printInfo(&isosceles_triangle_);
		std::cout << std::endl;
	} catch (const GenericError& error) {
		cerr << "Reason: " << error.what() << endl;
	}
	try {
		EquilateralTriangle equilateral_triangle_{ 30, 30, 30, 60, 60, 60 };
		printInfo(&equilateral_triangle_);
		std::cout << std::endl;
	} catch (const GenericError& error) {
		cerr << "Reason: " << error.what() << endl;
	}
	try {
		Quadrangle quadrangle_{10, 20, 30, 40, 100, 60, 120, 80};
		printInfo(&quadrangle_);
		std::cout << std::endl;
	}
	catch (const GenericError& error) {
		cerr << "Reason: " << error.what() << endl;
	}
	try {
		Rectangle rectangle_{ 10, 20, 10, 20, 90, 90, 90, 90 };
		printInfo(&rectangle_);
		std::cout << std::endl;
	}
	catch (const GenericError& error) {
		cerr << "Reason: " << error.what() << endl;
	}
	try {
		Square square_{ 20, 20, 20, 20, 90, 90, 90, 90 };
		printInfo(&square_);
		std::cout << std::endl;
	}
	catch (const GenericError& error) {
		cerr << "Reason: " << error.what() << endl;
	}
	try {
		Parallelogram parallelogram_{ 20, 30, 20, 30, 90, 90, 90, 90 };
		printInfo(&parallelogram_);
		std::cout << std::endl;
	}
	catch (const GenericError& error) {
		cerr << "Reason: " << error.what() << endl;
	}
	try {
		Rhombus rhombus_{ 30, 30, 30, 30, 90, 90, 90, 90 };
		printInfo(&rhombus_);
		std::cout << std::endl;
	}
	catch (const GenericError& error) {
		cerr << "Reason: " << error.what() << endl;
	}
	return 0;
}