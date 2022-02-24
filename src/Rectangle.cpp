//
// Created by Hugo Tiem on 23/02/2022.
//

#include <iostream>
#include "include/Rectangle.h"

using namespace std;

void Rectangle::draw() {
    for(int i = 0; i < getX(); i++) {
        for(int j = 0; j < getY(); j++) {
            if(i == 0 || i == getX()-1) {
                cout << getColor()[0];
            } else if (j == 0 || getY() - 1) {
                cout << getColor()[0];
            }
        }
    }

}