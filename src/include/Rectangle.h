//
// Created by Hugo Tiem on 23/02/2022.
//

#ifndef SVG_CREATOR_RECTANGLE_H
#define SVG_CREATOR_RECTANGLE_H


#include "Shape.h"

using namespace std;

class Rectangle {

private:
    string color;
    int d_x;
    int d_y;

public:
    Rectangle(string color, int x, int y): color(color), d_x(x), d_y(y) {};

    int getX() {
        return d_x;
    }

    int getY() {
        return d_y;
    }

    string getColor() {
        return color;
    }

    void draw();
};


#endif //SVG_CREATOR_RECTANGLE_H
