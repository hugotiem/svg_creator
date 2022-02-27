//
// Created by Hugo Tiem on 27/02/2022.
//

#ifndef SVG_CREATOR_SEGMENT_H
#define SVG_CREATOR_SEGMENT_H

#include "iostream"
#include <string>

using namespace std;

class Segment {
    int x1, y1, x2, y2;
    string color;

public:

    Segment(string color, int x1,int y1,int x2,int y2) : color(color), x1(x1), x2(x2), y1(y1), y2(y2) {};

    static Segment buildSegment(string (*getColor)(char color)) {
        int x1, y1, x2, y2;
        char color;
        cout << "points et couleur de votre segment: (x y) \nx1 y1: ";
        cin >> x1 >> y1;

        cout << "x2 y2: ";
        cin >> x2 >> y2;

        cout << "and color: (rouge: r, orange: o, vert: g, jaune: y, violet: p, others: noir) ";
        cin >> color;

        Segment seg = Segment(getColor(color), x1, y1, x2, y2);
        return seg;
    }

    string svgContent() const {
        return "<svg width=\"800\" height=\"800\" xmlns=\"http://www.w3.org/2000/svg\">"
               "<line x1=\""+ to_string(x1) + "\" y1=\""+ to_string(y1) +"\" x2=\""+ to_string(x2) + "\" y2=\""+ to_string(y2) +"\" fill='"+color+"' />"
                                                                                                                    "</svg>\n";
    }

    string getSavedContent() {
        return "type cercle\n center x " + to_string(x) + "\n center y " + to_string(y) + "\n radius "+ to_string(r) + "\ncolor " + color;
    }
};


#endif //SVG_CREATOR_SEGMENT_H
