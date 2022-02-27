//
// Created by Hugo Tiem on 23/02/2022.
//

#ifndef SVG_CREATOR_POLYGONE_H
#define SVG_CREATOR_POLYGONE_H

#include "vector"
#include "string"

using namespace std;

class Polygone {
private:
    vector<int> d_x;
    vector<int> d_y;
    string color;

public:

    Polygone(vector<int> x, vector<int> y, string color): color(color), d_x(x), d_y(y) {};

    vector<int> getX() const {
        return d_x;
    }

    vector<int> getY() const {
        return d_y;
    }

    string getColor() const {
        return color;
    }

    static Polygone buildPolygone(string(*getColor)(char color)) {
        char stop;
        vector<int> v_x;
        vector<int> v_y;
        while (stop != 'q') {
            int x, y;
            cout << "ajouter un point au polyhone: ";
            cin >> x >> y;
            v_x.push_back(x);
            v_y.push_back(y);
            cout << "'q' pour quitter, autre pour ajouter un point: ";
            cin >> stop;
        }
        char color;

        cout << "couleur du polyhone: (rouge: r, orange: o, vert: g, jaune: y, violet: p, others: noir) ";
        cin >> color;

        Polygone p = Polygone(v_x, v_y, getColor(color));
        return p;
    }

};


#endif //SVG_CREATOR_POLYGONE_H
