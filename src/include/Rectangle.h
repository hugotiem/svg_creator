//
// Created by Hugo Tiem on 23/02/2022.
//

#ifndef SVG_CREATOR_RECTANGLE_H
#define SVG_CREATOR_RECTANGLE_H


#include "Shape.h"
#include "Graphics.h"
#include <fstream>

using namespace std;

class Rectangle {

private:
    string color;
    int d_x;
    int d_y;

public:
    Rectangle(string color, int x, int y): color(color), d_x(x), d_y(y) {};

    int getX() const {
        return d_x;
    }

    int getY() const {
        return d_y;
    }

    string getColor() const {
        return color;
    }

    void draw() const {

    };

    string svgContent() const {
        return "<svg width=\"800\" height=\"800\" xmlns=\"http://www.w3.org/2000/svg\">"
               "<rect x=\"0\" y=\"0\" width=\""+ to_string(d_x) + "\" height=\""+ to_string(d_y) +"\" fill='"+color+"' />"
                                                                                                           "</svg>\n";
    }

    string getSaveContent() {
        return "width " + to_string(d_x) + "\nheight " + to_string(d_y) + "\ncolor " + color;
    }

    Rectangle& fromTxt () {
        return *new Rectangle("red", 600, 700);
    }
};


#endif //SVG_CREATOR_RECTANGLE_H
