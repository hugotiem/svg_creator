//
// Created by Hugo Tiem on 23/02/2022.
//

#ifndef SVG_CREATOR_SHAPE_H
#define SVG_CREATOR_SHAPE_H


#include <string>

template<typename T> class Shape {
private:
    std::string tagName;

public:
    template <typename U> friend class Shape;

    template <typename U>
        Shape(const Shape<U> &s): {};
};


#endif //SVG_CREATOR_SHAPE_H
