//
// Created by Hugo Tiem on 23/02/2022.
//

#ifndef SVG_CREATOR_RECTANGLE_H
#define SVG_CREATOR_RECTANGLE_H


#include "Shape.h"

using namespace std;

class Rectangle {

private:
    char color;
    int d_x;
    int d_y;

public:
    Rectangle(char color, int x, int y): color(color), d_x(x), d_y(y) {};

    int getX() const {
        return d_x;
    }

    int getY() const {
        return d_y;
    }

    char getColor() const {
        return color;
    }

    void draw() const {
        for(int i = 0; i < getX(); i++) {
            for(int j = 0; j < getY(); j++) {
                if(i == 0 or i == getX()-1) {
                    cout << " " << getColor() << " ";
                } else if (j == 0 or j == getY() - 1) {
                    cout << " " << getColor() << " ";
                } else {
                    cout << "   ";
                }
            }
            cout << endl;
        }
    };
};


#endif //SVG_CREATOR_RECTANGLE_H
