//
// Created by Hugo Tiem on 23/02/2022.
//

#ifndef SVG_CREATOR_CIRCLE_H
#define SVG_CREATOR_CIRCLE_H


#include <iostream>
#include <math.h>

using namespace std;

class Circle {
private:
    int x, y, r;
    string color;

public:
    Circle(int x, int y, int r, string color): x(x), y(y), r(r), color(color) {};

    int getRayon() const {
        return r;
    }

    string getColor() const {
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

    static Circle buildCircle(string(*getColor)(char color)) {
        int x, y, r;
        char color;
        cout << "centre, rayon et couleur de votre cercle: \nx: ";
        cin >> x;

        cout << "y: ";
        cin >> y;

        cout << "rayon: ";
        cin >> r;

        cout << "et couleur: (rouge: r, orange: o, vert: g, jaune: y, violet: p, others: noir) ";
        cin >> color;

        Circle c = Circle(x, y, r, getColor(color));
    }
};


#endif //SVG_CREATOR_CIRCLE_H
