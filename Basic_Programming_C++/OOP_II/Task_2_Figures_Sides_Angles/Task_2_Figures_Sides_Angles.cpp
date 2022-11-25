//Task: Design and realize classes that describ the subject area.

#include <iostream>

using namespace std;

class Figure {
private:
    std::string figure_name;
    unsigned int length_a{ 0 }, length_b{ 0 }, length_c{ 0 }, length_d{ 0 };
    unsigned int angl_A{ 0 }, angl_B{ 0 }, angl_C{ 0 }, angl_D{ 0 };
protected:
    Figure(std::string figure_name,
        int length_a, int length_b, int length_c,
        int angl_A, int angl_B, int angl_C)
    {
        this->figure_name = figure_name;
        this->length_a = length_a;
        this->length_b = length_b;
        this->length_c = length_c;
        this->angl_A = angl_A;
        this->angl_B = angl_B;
        this->angl_C = angl_C;
    }
    Figure(std::string figure_name,
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
    {
        this->figure_name = figure_name;
        this->length_a = length_a;
        this->length_b = length_b;
        this->length_c = length_c;
        this->length_d = length_d;
        this->angl_A = angl_A;
        this->angl_B = angl_B;
        this->angl_C = angl_C;
        this->angl_D = angl_D;
    }
public:
    std::string get_figure_name() const {
        return this->figure_name;
    }
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
};
// треугольник
class Triangle : public Figure {
protected:
    Triangle(
        std::string figure_name,
        int length_a, int length_b, int length_c,
        int angl_A, int angl_B, int angl_C)
        : Figure(
            figure_name,
            length_a, length_b, length_c,
            angl_A, angl_B, angl_C) {}
public:
    Triangle(
        int length_a, int length_b, int length_c,
        int angl_A, int angl_B, int angl_C)
        : Figure(
            "Triangle",
            length_a, length_b, length_c,
            angl_A, angl_B, angl_C) {}
};
// прямоугольный треугольник
class RightTriangle : public Triangle {
protected:
    RightTriangle(
        std::string figure_name,
        int length_a, int length_b, int length_c,
        int angl_A, int angl_B, int angl_C)
        : Triangle(
            figure_name,
            length_a, length_b, length_c,
            angl_A, angl_B, angl_C) {}
public:
    RightTriangle(
        int length_a, int length_b, int length_c,
        int angl_A, int angl_B, int angl_C)
        : RightTriangle(
            "RightTriangle",
            length_a, length_b, length_c,
            angl_A, angl_B, angl_C) {}
};
// равнобедренный треугольник
class IsoscelesTriangle : public Triangle {
protected:
    IsoscelesTriangle(
        std::string figure_name,
        int length_a, int length_b, int length_c,
        int angl_A, int angl_B, int angl_C)
        : Triangle(
            figure_name, length_a, length_b,
            length_c, angl_A, angl_B, angl_C) {}
public:
    IsoscelesTriangle(
        int length_a, int length_b, int length_c,
        int angl_A, int angl_B, int angl_C)
        : IsoscelesTriangle(
            "Isoscelestriangle",
            length_a, length_b, length_c,
            angl_A, angl_B, angl_C) {}
};
// равносторонний треугольник
class EquilateralTriangle : public IsoscelesTriangle {
protected:
    EquilateralTriangle(
        std::string figure_name,
        int length_a, int length_b, int length_c,
        int angl_A, int angl_B, int angl_C)
        : IsoscelesTriangle(
            figure_name,
            length_a, length_b, length_c,
            angl_A, angl_B, angl_C) {}
public:
    EquilateralTriangle(
        int length_a, int length_b, int length_c,
        int angl_A, int angl_B, int angl_C)
        : EquilateralTriangle(
            "Equilateraltriangle",
            length_a, length_b, length_c,
            angl_A, angl_B, angl_C) {}
};
// четырёхугольник
class Quadrangle : public Figure {
protected:
    Quadrangle(
        std::string figure_name,
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
        : Figure(
            figure_name,
            length_a, length_b, length_c, length_d,
            angl_A, angl_B, angl_C, angl_D) {}
public:
    Quadrangle(
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
        : Figure(
            "Quadrangle",
            length_a, length_b, length_c, length_d,
            angl_A, angl_B, angl_C, angl_D) {};
};
// параллелограмм
class Parallelogram : public Quadrangle {
protected:
    Parallelogram(
        std::string figure_name,
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
        : Quadrangle(
            figure_name,
            length_a, length_b, length_c, length_d,
            angl_A, angl_B, angl_C, angl_D) {}
public:
    Parallelogram(
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
        : Parallelogram(
            "Parallelogram",
            length_a, length_b, length_c, length_d,
            angl_A, angl_B, angl_C, angl_D) {}
};
// прямоугольник
class Rectangle : public Parallelogram {
protected:
    Rectangle(
        std::string figure_name,
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
        : Parallelogram(
            figure_name,
            length_a, length_b, length_c, length_d,
            angl_A, angl_B, angl_C, angl_D) {}
public:
    Rectangle(
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
        : Rectangle(
            "Rectangle",
            length_a, length_b, length_c, length_d,
            angl_A, angl_B, angl_C, angl_D) {}
};
// квадрат
class Square : public Quadrangle {
protected:
    Square(
        std::string figure_name,
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
        : Quadrangle(figure_name,
            length_a, length_b, length_c, length_d,
            angl_A, angl_B, angl_C, angl_D) {}
public:
    Square(
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
        : Square(
            "Square",
            length_a, length_b, length_c, length_d,
            angl_A, angl_B, angl_C, angl_D) {}
};
// ромб
class Rhombus : public Square {
protected:
    Rhombus(
        std::string figure_name,
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
        : Square(
            figure_name,
            length_a, length_b, length_c, length_d,
            angl_A, angl_B, angl_C, angl_D) {}
public:
    Rhombus(
        int length_a, int length_b, int length_c, int length_d,
        int angl_A, int angl_B, int angl_C, int angl_D)
        : Rhombus(
            "Rhombus",
            length_a, length_b, length_c, length_d,
            angl_A, angl_B, angl_C, angl_D) {}
};

void print_figure_info(Figure* figure) {
    if (figure->get_angle_D() > 0) {
        std::cout << figure->get_figure_name() << ':' << std::endl;
        std::cout << "Sides: "
            << "a = " << figure->get_length_a()
            << ", b = " << figure->get_length_b()
            << ", c = " << figure->get_length_c()
            << ", d = " << figure->get_length_d() << std::endl;
        std::cout << "Angles: "
            << "A = " << figure->get_angle_A()
            << ", B = " << figure->get_angle_B()
            << ", C = " << figure->get_angle_C()
            << ", D = " << figure->get_angle_D() << std::endl;
    }
    else {
        std::cout << figure->get_figure_name() << ':' << std::endl;
        std::cout << "Sides: "
            << "a = " << figure->get_length_a()
            << ", b = " << figure->get_length_b()
            << ", c = " << figure->get_length_c() << std::endl;
        std::cout << "Angles: "
            << "A = " << figure->get_angle_A()
            << ", B = " << figure->get_angle_B()
            << ", C = " << figure->get_angle_C() << std::endl;
    }
    return;
}

int main(int argc, char** argv) {
    Triangle triangle_{ 10, 20, 30, 50, 60, 70 };
    RightTriangle right_triangle_{ 11, 21, 31, 51, 61, 91 };
    IsoscelesTriangle isosceles_triangle_{ 12, 22, 12, 52, 62, 52 };
    EquilateralTriangle equilateral_triangle_{ 14, 14, 14, 54, 54, 54 };
    Parallelogram parallelogram_{ 15, 25, 15, 25, 55, 65, 55, 65 };
    Rectangle rectangle_{ 35, 45, 35, 45, 91, 91, 91, 91 };
    Square square_{ 55, 55, 55, 55, 91, 91, 91, 91 };
    Rhombus rhombus_{ 55, 55, 55, 55, 30, 60, 30, 60 };

    print_figure_info(&triangle_);
    std::cout << std::endl;
    print_figure_info(&right_triangle_);
    std::cout << std::endl;
    print_figure_info(&isosceles_triangle_);
    std::cout << std::endl;
    print_figure_info(&equilateral_triangle_);
    std::cout << std::endl;
    print_figure_info(&parallelogram_);
    std::cout << std::endl;
    print_figure_info(&rectangle_);
    std::cout << std::endl;
    print_figure_info(&square_);
    std::cout << std::endl;
    print_figure_info(&rhombus_);

    return 0;
}