//
// Created by Hugo Tiem on 24/02/2022.
//

#ifndef SVG_CREATOR_DRAWING_H
#define SVG_CREATOR_DRAWING_H


#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

template<typename T>
class Drawing {
private:
    T& shape;



public:
    Drawing<T>(T& shape): shape(shape) {};

    void save(string title) {


        ofstream myfile;
        string path= title+".txt";
        myfile.open (path);

        if(myfile.is_open()) {
            myfile << shape.getSavedContent();
        }

        myfile.close();
    }

    T& open(char const *title) {
        ifstream infile(title);;
        string line;
        string key;
        string value;
        map<string, string> m1;
        typedef pair <string, string> Int_Pair;

        while (std::getline(infile, line))
        {
            std::istringstream iss(line);

            iss >> key >> value; // error

            m1.insert(Int_Pair(key, value));

        }
        T& t = shape.fromTxt(m1);
        return t;
    }

};


#endif //SVG_CREATOR_DRAWING_H
