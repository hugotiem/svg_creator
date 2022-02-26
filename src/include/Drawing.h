//
// Created by Hugo Tiem on 24/02/2022.
//

#ifndef SVG_CREATOR_DRAWING_H
#define SVG_CREATOR_DRAWING_H


#include <vector>
#include "../Shape.cpp"
#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
class Drawing {
private:
    T& shape;



public:
    Drawing(T& shape): shape(shape) {};

    void save() {
        string title;
        cout << "Titre de votre dessin: ";
        cin >> title;

        ofstream myfile;
        string path= title+".txt";
        myfile.open (path);

        if(myfile.is_open()) {
            myfile << shape.getSaveContent();
        }

        myfile.close();
    }

    T& open(char const *title) {
        ifstream file;
        string data;
        file.open(title);
        if(file.is_open()) {
            while(file) {

            }
            file >> data;
            cout << data << endl;

        }
        T& t = shape.fromTxt();
        return t;
    }

};


#endif //SVG_CREATOR_DRAWING_H
