//
// Created by Hugo Tiem on 23/02/2022.
//

#ifndef SVG_CREATOR_CIRCLE_H
#define SVG_CREATOR_CIRCLE_H


#include "Shape.h"
#include <iostream>
#include <math.h>

using namespace std;

class Circle {
private:
    int r;
    char color;

public:
    Circle(int r, char color): r(r), color(color) {};

    int getRayon() const {
        return r;
    }

    char getColor() const {
        return color;
    }

    int pth (int x,int y)  {
        return sqrt (pow(x,2)+pow(y,2));
    }

    void draw() {
        for (int y=r;y >= -r;y-=2)  {
            for (int x=-r;x <= r;x++)  {

                if ((int) pth(x,y)==r) cout << "*";
                else cout << " ";

            }
            cout << "\n";
        }
    }
};


#endif //SVG_CREATOR_CIRCLE_H
