//Task: Design and realize classes that describ the subject area.

#include <iostream>
#include <string>

class Figure {
private:
    std::string figure_name;
    int sides_num = 0;
    int corners_num = 0;
protected:
    Figure(std::string figure_name_, int sides_num_) : figure_name(figure_name_), sides_num(sides_num_) {}

    void setFigureName(const std::string &name) {
        this->figure_name = name;
        return;
    }
    std::string getFigureName() const {
        return this->figure_name;
    }
    void setFigureSides(int sides_num) {
        this->sides_num = sides_num;
        return;
    }
    int getFigureSides() const {
        return this->sides_num;
    }
    bool isFigureCorrect() {
        return (sides_num ? false : true);
    }
public:
    Figure() : Figure("Figure", 0) {}

    virtual void printFigureInfo() {
        std::cout << "Name: " << figure_name << std::endl;
        std::cout << "Correctness: " << std::boolalpha << isFigureCorrect() << std::endl;
        std::cout << "Side numbers: " << sides_num << std::endl;
    }
};
// треугольник
class Triangle : public Figure {
private:
    int length_a{ 0 }, length_b{ 0 }, length_c{ 0 };
    int angl_A{ 0 }, angl_B{ 0 }, angl_C{ 0 };
protected:
    Triangle(
        std::string figure_name, int sides_num,
        int length_a_, int length_b_, int length_c_,
        int angl_A_, int angl_B_, int angl_C_)
    :   length_a(length_a_), length_b(length_b_), length_c(length_c_),
        angl_A(angl_A_), angl_B(angl_B_), angl_C(angl_C_)
    {
        setFigureName(figure_name);
        setFigureSides(sides_num);
    }
    bool isTrianleCorrect() const {
        return (getFigureSides() == 3) && ((get_angle_A() + get_angle_B() + get_angle_C()) == 180) ? true : false;
    }
public:
    Triangle(
        int length_a, int length_b, int length_c,
        int angl_A, int angl_B, int angl_C)
    : Triangle(
        "Triangle", 3,
        length_a, length_b, length_c,
        angl_A, angl_B, angl_C)
    {}

    int get_length_a() const {
        return this->length_a;
    }
    int get_length_b() const {
        return this->length_b;
    }
    int get_length_c() const {
        return this->length_c;
    }
    int get_angle_A() const {
        return this->angl_A;
    }
    int get_angle_B() const {
        return this->angl_B;
    }
    int get_angle_C() const {
        return this->angl_C;
    }
    void printFigureInfo() override {
        std::cout << "Name: " << getFigureName() << std::endl;
        std::cout << "Correctness: " << std::boolalpha << isTrianleCorrect() << std::endl;
        std::cout << "Side numbers: " << getFigureSides() << std::endl;
        std::cout << "Sides: " << get_length_a() << ", " << get_length_b() << ", " << get_length_c() << std::endl;
        std::cout << "Angles: " << get_angle_A() << ", " << get_angle_B() << ", " << get_angle_C() << std::endl;
    }
};
// прямоугольный треугольник
class RightTriangle : public Triangle {
protected:
    bool isRightTriangleCorrect() {
        if (isTrianleCorrect() && (get_angle_C() == 90)) {
            return true;
        } else {
            return false;
        }
    }
    void printFigureInfo() override {
        std::cout << "Name: " << getFigureName() << std::endl;
        std::cout << "Correctness: " << std::boolalpha << isRightTriangleCorrect() << std::endl;
        std::cout << "Side numbers: " << getFigureSides() << std::endl;
        std::cout << "Sides: " << get_length_a() << ", " << get_length_b() << ", " << get_length_c() << std::endl;
        std::cout << "Angles: " << get_angle_A() << ", " << get_angle_B() << ", " << get_angle_C() << std::endl;
    }
public:
    RightTriangle(
        int length_a, int length_b, int length_c,
        int angl_a, int angl_b, int angl_c)
    : Triangle(
        "Right triangle", 3,
        length_a, length_b, length_c,
        angl_a, angl_b, angl_c)
    {}
};
// равнобедренный треугольник
class IsoscelesTriangle : public Triangle {
protected:
    IsoscelesTriangle(
        std::string figure_name, int sides_num,
        int length_a, int length_b, int length_c,
        int angl_a, int angl_b, int angl_c)
    : Triangle(
        figure_name, sides_num,
        length_a, length_b, length_c,
        angl_a, angl_b, angl_c)
    {}
    bool isIsoscelesTriangleCorrect() {
        if (isTrianleCorrect() && (get_length_a() == get_length_c()) && (get_angle_A() == get_angle_C())) {
            return true;
        } else {
            return false;
        }
    }
    void printFigureInfo() override {
        std::cout << "Name: " << getFigureName() << std::endl;
        std::cout << "Correctness: " << std::boolalpha << isIsoscelesTriangleCorrect() << std::endl;
        std::cout << "Side numbers: " << getFigureSides() << std::endl;
        std::cout << "Sides: " << get_length_a() << ", " << get_length_b() << ", " << get_length_c() << std::endl;
        std::cout << "Angles: " << get_angle_A() << ", " << get_angle_B() << ", " << get_angle_C() << std::endl;
    }
public:
    IsoscelesTriangle(
        int length_a, int length_b, int length_c,
        int angl_a, int angl_b, int angl_c)
    : IsoscelesTriangle(
        "Isosceles triangle", 3,
        length_a, length_b, length_c,
        angl_a, angl_b, angl_c)
    {}
};
// равносторонний треугольник
class EquilateralTriangle : public IsoscelesTriangle {
protected:
    EquilateralTriangle(
        std::string figure_name, int sides_num,
        int length_a, int length_b, int length_c,
        int angl_a, int angl_b, int angl_c)
    : IsoscelesTriangle(
        figure_name, sides_num,
        length_a, length_b, length_c,
        angl_a, angl_b, angl_c)
    {}
    bool isEquilateralTriangleCorrect() {
        if (isTrianleCorrect() &&
           ((get_length_a() == get_length_b()) && (get_length_a() == get_length_c())) &&
           ((get_angle_A() == 60) && (get_angle_B() == 60) && (get_angle_C() == 60))) {
            return true;
        } else {
            return false;
        }
    }
    void printFigureInfo() override {
        std::cout << "Name: " << getFigureName() << std::endl;
        std::cout << "Correctness: " << std::boolalpha << isEquilateralTriangleCorrect() << std::endl;
        std::cout << "Side numbers: " << getFigureSides() << std::endl;
        std::cout << "Sides: " << get_length_a() << ", " << get_length_b() << ", " << get_length_c() << std::endl;
        std::cout << "Angles: " << get_angle_A() << ", " << get_angle_B() << ", " << get_angle_C() << std::endl;
    }
public:
    EquilateralTriangle(
        int length_a, int length_b, int length_c,
        int angl_a, int angl_b, int angl_c)
    : EquilateralTriangle(
        "Equilateral triangle", 3,
        length_a, length_b, length_c,
        angl_a, angl_b, angl_c)
    {}
};
// четырёхугольник
class Quadrangle : public Figure {
private:
    int length_a{ 0 }, length_b{ 0 }, length_c{ 0 }, length_d{ 0 };
    int angl_A{ 0 }, angl_B{ 0 }, angl_C{ 0 }, angl_D{ 0 };
protected:
    Quadrangle(
        std::string figure_name, int sides_num,
        int length_a_, int length_b_, int length_c_, int length_d_,
        int angl_A_, int angl_B_, int angl_C_, int angl_D_)
    :   length_a(length_a_), length_b(length_b_), length_c(length_c_), length_d(length_d_),
        angl_A(angl_A_), angl_B(angl_B_), angl_C(angl_C_), angl_D(angl_D_)
    {
        setFigureName(figure_name);
        setFigureSides(sides_num);
    }
    bool isQuadrangleCorrect() const {
        return (getFigureSides() == 4 && (get_angle_A() + get_angle_B() + get_angle_C() + get_angle_D()) == 360) ? true : false;
    }
public:
    Quadrangle(
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
    : Quadrangle(
        "Quadrangle", 4,
        length_a, length_b, length_c, length_d,
        angl_A, angl_B, angl_C, angl_D)
    {}

    int get_length_a() const {
        return this->length_a;
    }
    int get_length_b() const {
        return this->length_b;
    }
    int get_length_c() const {
        return this->length_c;
    }
    int get_length_d() const {
        return this->length_d;
    }
    int get_angle_A() const {
        return this->angl_A;
    }
    int get_angle_B() const {
        return this->angl_B;
    }
    int get_angle_C() const {
        return this->angl_C;
    }
    int get_angle_D() const {
        return this->angl_D;
    }
    void printFigureInfo() override {
        std::cout << "Name: " << getFigureName() << std::endl;
        std::cout << "Correctness: " << std::boolalpha << isQuadrangleCorrect() << std::endl;
        std::cout << "Side numbers: " << getFigureSides() << std::endl;
        std::cout << "Sides: " << get_length_a() << ", " << get_length_b() << ", " << get_length_c() << ", " << get_length_d() << std::endl;
        std::cout << "Angles: " << get_angle_A() << ", " << get_angle_B() << ", " << get_angle_C() << ", " << get_angle_D() << std::endl;
    }
};
// параллелограмм
class Parallelogram : public Quadrangle {
protected:
    Parallelogram(
        std::string figure_name, int sides_num,
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
    : Quadrangle(
        figure_name, sides_num,
        length_a, length_b, length_c, length_d,
        angl_A, angl_B, angl_C, angl_D)
    {}
    bool isParallelogramCorrect() {
        if (isQuadrangleCorrect() &&
           ((get_length_a() == get_length_c()) && (get_length_b() == get_length_d())) &&
           ((get_angle_A() == get_angle_C()) && (get_angle_B() == get_angle_D()))) {
            return true;
        } else {
            return false;
        }
    }
    void printFigureInfo() override {
        std::cout << "Name: " << getFigureName() << std::endl;
        std::cout << "Correctness: " << std::boolalpha << isParallelogramCorrect() << std::endl;
        std::cout << "Side numbers: " << getFigureSides() << std::endl;
        std::cout << "Sides: " << get_length_a() << ", " << get_length_b() << ", " << get_length_c() << ", " << get_length_d() << std::endl;
        std::cout << "Angles: " << get_angle_A() << ", " << get_angle_B() << ", " << get_angle_C() << ", " << get_angle_D() << std::endl;
    }
public:
    Parallelogram(
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
    : Parallelogram(
        "Parallelogram", 4,
        length_a, length_b, length_c, length_d,
        angl_A, angl_B, angl_C, angl_D)
    {}
};
// прямоугольник
class Rectangle : public Parallelogram {
protected:
    Rectangle(
        std::string figure_name, int sides_num,
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
    : Parallelogram(
        figure_name, sides_num,
        length_a, length_b, length_c, length_d,
        angl_A, angl_B, angl_C, angl_D)
    {}
    bool isRectangleCorrect() {
        if (isQuadrangleCorrect() &&
           ((get_length_a() == get_length_c()) && (get_length_b() == get_length_d())) &&
           ((get_angle_A() == 90 && get_angle_C() == 90 && get_angle_B() == 90 && get_angle_D() == 90))) {
            return true;
        } else {
            return false;
        }
    }
    void printFigureInfo() override {
        std::cout << "Name: " << getFigureName() << std::endl;
        std::cout << "Correctness: " << std::boolalpha << isRectangleCorrect() << std::endl;
        std::cout << "Side numbers: " << getFigureSides() << std::endl;
        std::cout << "Sides: " << get_length_a() << ", " << get_length_b() << ", " << get_length_c() << ", " << get_length_d() << std::endl;
        std::cout << "Angles: " << get_angle_A() << ", " << get_angle_B() << ", " << get_angle_C() << ", " << get_angle_D() << std::endl;
    }
public:
    Rectangle(
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
    : Rectangle(
        "Rectangle", 4,
        length_a, length_b, length_c, length_d,
        angl_A, angl_B, angl_C, angl_D)
    {}
};
// квадрат
class Square : public Quadrangle {
protected:
    Square(
        std::string figure_name, int sides_num,
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
    : Quadrangle(
        figure_name, sides_num,
        length_a, length_b, length_c, length_d,
        angl_A, angl_B, angl_C, angl_D)
    {}
    bool isSquareCorrect() {
        if (isQuadrangleCorrect() &&
            ((get_length_a() == get_length_c()) && (get_length_b() == get_length_d()) && (get_length_a() == get_length_b())) &&
            ((get_angle_A() == 90 && get_angle_C() == 90 && get_angle_B() == 90 && get_angle_D() == 90))) {
            return true;
        } else {
            return false;
        }
    }
    void printFigureInfo() override {
        std::cout << "Name: " << getFigureName() << std::endl;
        std::cout << "Correctness: " << std::boolalpha << isSquareCorrect() << std::endl;
        std::cout << "Side numbers: " << getFigureSides() << std::endl;
        std::cout << "Sides: " << get_length_a() << ", " << get_length_b() << ", " << get_length_c() << ", " << get_length_d() << std::endl;
        std::cout << "Angles: " << get_angle_A() << ", " << get_angle_B() << ", " << get_angle_C() << ", " << get_angle_D() << std::endl;
    }
public:
    Square(
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
    : Square(
        "Square", 4,
        length_a, length_b, length_c, length_d,
        angl_A, angl_B, angl_C, angl_D)
    {}
};
// ромб
class Rhombus : public Square {
protected:
    Rhombus(
        std::string figure_name, int sides_num,
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
    : Square(
        figure_name, sides_num,
        length_a, length_b, length_c, length_d,
        angl_A, angl_B, angl_C, angl_D)
    {}
    bool isRhombusCorrect() {
        if (isQuadrangleCorrect() &&
            (get_length_a() == get_length_c()) && (get_length_b() == get_length_d()) && (get_length_a() == get_length_b()) &&
            (get_angle_A() == get_angle_C()) && (get_angle_B() == get_angle_D())) {
            return true;
        } else {
            return false;
        }
    }
    void printFigureInfo() override {
        std::cout << "Name: " << getFigureName() << std::endl;
        std::cout << "Correctness: " << std::boolalpha << isRhombusCorrect() << std::endl;
        std::cout << "Side numbers: " << getFigureSides() << std::endl;
        std::cout << "Sides: " << get_length_a() << ", " << get_length_b() << ", " << get_length_c() << ", " << get_length_d() << std::endl;
        std::cout << "Angles: " << get_angle_A() << ", " << get_angle_B() << ", " << get_angle_C() << ", " << get_angle_D() << std::endl;
    }
public:
    Rhombus(
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
    : Rhombus(
        "Rhombus", 4,
        length_a, length_b, length_c, length_d,
        angl_A, angl_B, angl_C, angl_D)
    {}
};

void printFigureInfo(Figure* figure) {
    figure->printFigureInfo();
    return;
}

int main(int argc, char** argv) {
    Figure figure_{};
    Triangle triangle_{ 10, 20, 30, 50, 60, 70 };
    RightTriangle right_triangle_{ 11, 21, 31, 40, 50, 90 };
    IsoscelesTriangle isosceles_triangle_{ 11, 22, 11, 70, 40, 70 };
    EquilateralTriangle equilateral_triangle_{ 14, 14, 14, 60, 60, 60 };
    Quadrangle quadrangle_{ 16, 26, 16, 26, 90, 90, 90, 90 };
    Parallelogram parallelogram_{ 15, 25, 15, 25, 60, 120, 60, 120 };
    Rectangle rectangle_{ 35, 45, 35, 45, 90, 90, 90, 90 };
    Square square_{ 55, 55, 55, 55, 90, 90, 90, 90 };
    Rhombus rhombus_{ 55, 55, 55, 55, 70, 110, 70, 110 };

    printFigureInfo(&figure_);
    std::cout << std::endl;
    printFigureInfo(&triangle_);
    std::cout << std::endl;
    printFigureInfo(&right_triangle_);
    std::cout << std::endl;
    printFigureInfo(&isosceles_triangle_);
    std::cout << std::endl;
    printFigureInfo(&equilateral_triangle_);
    std::cout << std::endl;
    printFigureInfo(&quadrangle_);
    std::cout << std::endl;
    printFigureInfo(&parallelogram_);
    std::cout << std::endl;
    printFigureInfo(&rectangle_);
    std::cout << std::endl;
    printFigureInfo(&square_);
    std::cout << std::endl;
    printFigureInfo(&rhombus_);

    return 0;
}