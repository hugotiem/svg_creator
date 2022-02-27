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

    string svgContent() const {
        return "<svg width=\"800\" height=\"800\" xmlns=\"http://www.w3.org/2000/svg\">"
               "<circle cx=\""+ to_string(x) + "\" cy=\""+ to_string(y) +"\" r=\""+ to_string(r) +"\" fill='"+color+"' />"
                                                                                                                    "</svg>\n";
    }

    string getSavedContent() {
        return "type cercle\n center x " + to_string(x) + "\n center y " + to_string(y) + "\n radius "+ to_string(r) + "\ncolor " + color;
    }
};


#endif //SVG_CREATOR_CIRCLE_H
