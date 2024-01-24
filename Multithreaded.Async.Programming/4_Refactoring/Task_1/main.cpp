#include <iostream>
#include"shape.h"

int main() {
    Liniya l{ {1,1},{12,12} };
    l.transform_scaleX(-11);
    Shape sh = l.transform_scaleY(-11);;
    Cylinder c{ {4,4,0,5,6} };
    c.transform_scaleX(11);
    sh = c.transform_scaleY(11);
    return 0;
};