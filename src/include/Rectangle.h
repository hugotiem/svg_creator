//
// Created by Hugo Tiem on 23/02/2022.
//

#ifndef SVG_CREATOR_RECTANGLE_H
#define SVG_CREATOR_RECTANGLE_H

#include "Graphics.h"
#include <fstream>
#include <map>

using namespace std;

class Rectangle {

private:
    string color;
    int d_x;
    int d_y;

public:
    Rectangle(string color, int x, int y): color(color), d_x(x), d_y(y) {};
    Rectangle(): d_x(0), d_y(0), color("") {};

    int getX() const {
        return d_x;
    }

    int getY() const {
        return d_y;
    }

    static Rectangle buildRectangle( string (*function)(char color), bool square=false) {
        int x, y;
        char color;
        cout << "Dimensions et couleur de votre rectangle:\nx: ";
        cin >> x;
        if(square) {
            y = x;
        } else {
            cout << "and y: ";
            cin >> y;
        }
        cout << "and color: (rouge: r, orange: o, vert: g, jaune: y, violet: p, others: noir) ";
        cin >> color;
        Rectangle rec = Rectangle(function(color), x, y);
        return rec;
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

    string getSavedContent() {
        return "type rectangle\nwidth " + to_string(d_x) + "\nheight " + to_string(d_y) + "\ncolor " + color;
    }

    Rectangle& fromTxt (map<string, string> m) {
        string c = m.at("color");
        int x = stoi(m.at("width"));
        int y = stoi(m.at("height"));
        return *new Rectangle(c, x, y);
    }
};


#endif //SVG_CREATOR_RECTANGLE_H
