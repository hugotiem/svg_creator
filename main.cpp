#ifdef __APPLE__
#include <GLUT/glut.h>
#include <iostream>
#else
#include <GL/glut.h>
#endif

#include "src/include/Graphics.h"
#include "src/Rectangle.cpp"
#include "src/SvgParser.cpp"
#include "src/Drawing.cpp"
#include <typeinfo>


using namespace std;

double* parseColor(double red, double green, double blue) {
    double* color = new double[3];
    color[0] = red;
    color[1] = green;
    color[2] = blue;
}

double* getColorRGB(char c) {
    switch (c) {
        case 'r':
            return parseColor(RED);
        case 'g':
            return parseColor(GREEN);
        case 'y':
            return parseColor(YELLOW);
        case 'b':
            return parseColor(BLUE);
        case 'p':
            return parseColor(PURPLE);
        default:
            return parseColor(BLACK);
    }
}

string getColor(char c) {
    switch (c) {
        case 'r':
            return "red";
        case 'g':
            return "green";
        case 'y':
            return "yellow";
        case 'b':
            return "blue";
        case 'p':
            return "purple";
        default:
            return "black";
    }
}

void drawScene(void) {
    int x, y;
    char c;
    cout << "Choissez des dimensions pour votre forme: \nx: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
    cout << "Choisissez une couleur: ";
    cin >> c;

    string color = getColor(c);

    Rectangle* rectangle = new Rectangle(color, x, y);

    Drawing<Rectangle> drawing = Drawing<Rectangle>(*rectangle);

    Rectangle rec = drawing.open("test.txt");

    SvgParser<Rectangle> parser = SvgParser<Rectangle>(*rectangle);


    parser.exportToSvg();

    clearWindow();
    setColor(RED);
    drawFilledBox(300,300,400,400);
    //rectangle->draw();
    glEnd();
    glutSwapBuffers();
    /*
    setColor(YELLOW);
    drawFilledTriangle(200,125,100,375,200,375);
    setColor(BLACK);
    drawLine(200,200,400,400);
    setColor(RED);
    drawFilledCircle(100,100,100);
    setColor(MAGENTA);
    drawFilledBox(300,300,400,400);
    */
}

int main(int argc, char ** argv) {
    graphicsSetup(argc, argv, 800, 800);
    glutDisplayFunc(drawScene);
    glutMainLoop();
}
