//
// Created by Hugo Tiem on 26/02/2022.
//

#ifndef SVG_CREATOR_SVGPARSER_H
#define SVG_CREATOR_SVGPARSER_H

#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
class SvgParser {

    T& shape;

public:
    SvgParser(T& shape): shape(shape) {
        cout << shape.getX() << endl;
    };

    void exportToSvg() {
        string svgTitle;
        cout << "Titre du fichier svg: ";
        cin >> svgTitle;

        ofstream myfile;
        string path= svgTitle+".svg";
        myfile.open (path);

        if(myfile.is_open()) {
            myfile << shape.svgContent();
        } else {
            cerr << "Creating/Opening file ERROR" << endl;
        }

        myfile.close();
    }
};


#endif //SVG_CREATOR_SVGPARSER_H
