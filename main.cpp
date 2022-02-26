/*#include <iostream>
#include "src/Rectangle.cpp"
#include "src/include/Circle.h"

using namespace std;

int main() {
    char stop;
    while(stop != 'q') {
        int x, y, r;
        char color;
        char shape;
        cout << "Hello, quelle forme voulez vous dessiner ? ";
        cin >> shape;
        if(shape == 'c') {
            cout << "Veuillez selectionner le rayon de votre cercle :\nx:";
            cin >> r;
        } else {
            cout << "Veuillez selectionner les dimensions de votre forme :\nx:";
            cin >> x;
            cout << " and y:";
            cin >> y;
        }
        cout << "Selectionnez une couleur (v=vert, r=rouge, b=bleu, o=orange:";
        cin >> color;

        if(shape == 'c'){
            auto *draw = new Circle(r, color);
            draw->draw();
        } else if(shape == 'r') {
            auto *draw =  new Rectangle(color, x, y);
            draw->draw();
        }


        cout << "presse q pour quitter et une autre touche pour continuer";
        cin >> stop;
    }

    return 0;
}*/

#ifdef __APPLE__
#include <GLUT/glut.h>
#include <iostream>
#else
#include <GL/glut.h>
#endif

#include "Graphics.h"

void drawScene(void) {
    clearWindow();
    setColor(YELLOW);
    drawFilledTriangle(200,125,100,375,200,375);
    setColor(BLACK);
    drawLine(200,200,400,400);
    setColor(RED);
    drawFilledCircle(100,100,100);
    setColor(MAGENTA);
    drawFilledBox(300,300,400,400);
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char ** argv) {
    graphicsSetup(argc, argv);
    glutDisplayFunc(drawScene);
    glutMainLoop();
}
