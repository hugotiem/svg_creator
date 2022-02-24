#include <iostream>
#include "src/Rectangle.cpp"

int main() {
    Rectangle *rectangle = new Rectangle("v", 4, 3);
    rectangle->draw();
    return 0;
}
