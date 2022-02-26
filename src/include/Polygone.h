//
// Created by Hugo Tiem on 23/02/2022.
//

#ifndef SVG_CREATOR_POLYGONE_H
#define SVG_CREATOR_POLYGONE_H


#include "Shape.h"

using namespace std;

class Polygone {
private:
    int d_x;
    int d_y;
    char color;

public:
    int getX() const {
        return d_x;
    }

    int getY() const {
        return d_y;
    }

    char getColor() const {
        return color;
    }
};


#endif //SVG_CREATOR_POLYGONE_H
