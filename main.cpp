#ifdef __APPLE__
#include <GLUT/glut.h>
#include <iostream>
#else
#include <GL/glut.h>
#endif

#include "src/include/Graphics.h"
#include "src/Rectangle.cpp"
#include "src/Circle.cpp"
#include "src/Segment.cpp"
#include "src/Polygone.cpp"
#include "src/SvgParser.cpp"
#include "src/Drawing.cpp"
#include <typeinfo>


using namespace std;

double* parseColor(double red, double green, double blue) {
    double* color = new double[3];
    color[0] = red;
    color[1] = green;
    color[2] = blue;
    return color;
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

template<typename T>
void save(vector<T> v) {
    string title;
    cout << "Titre de votre dessin: ";
    cin >> title;
    for (auto it = v.begin(); it != v.end(); it++) {
        Drawing<T> d = Drawing<T>(*it);
        d.save(title);
    }
}

template<typename T>
void toSvg(vector<T> v) {
    string svgTitle;
    cout << "Titre du fichier svg: ";
    cin >> svgTitle;
    for (auto it = v.begin(); it != v.end(); it++) {
        SvgParser<T> parser = SvgParser<T>(*it);
        parser.exportToSvg(svgTitle);
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

    cout << rec.getColor() << endl;

    cout << "sauvegarde rectangle overt!" << endl;

    SvgParser<Rectangle> parser = SvgParser<Rectangle>(*rectangle);

    cout << "parser instancié!" << endl;


   // parser.exportToSvg();

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

    string action;
    while (action != "import" and action != "new") {
        cout << "Hello, veuillez entrer le nom de l'action: (import: importer un dessin, new: creér un nouveau dessin)" << endl;
        cin >> action;
    }

    if(action == "import") {

        Rectangle* rectangle = new Rectangle("color", 0, 0);
        Drawing<Rectangle> drawing = Drawing<Rectangle>(*rectangle);
        char *title;
        cout << "nom du dessin à importer (format .txt): ";
        cin >> title;
        Rectangle rec = drawing.open(title);
    } else {
        bool stop;
        vector<Rectangle> recs;
        vector<Segment> segs;
        vector<Circle> circs;
        vector<Polygone> pols;
        while (!stop) {
            char shapeChar;
            while(shapeChar != 'c' and shapeChar != 'o' and shapeChar != 'p' and shapeChar != 's' and shapeChar != 'r') {
                cout << "que voulez vous dessiner ? (carré: c, polygone: p, segment: s, rectangle: r, circle: o)" << endl;
                cin >> shapeChar;
            }
            switch (shapeChar) {
                case 'r': {
                    Rectangle rec = Rectangle::buildRectangle(getColor);
                    recs.push_back(rec);
                    break;
                }
                case 'c': {
                    Rectangle square = Rectangle::buildRectangle(getColor, true);
                    recs.push_back(square);
                    break;
                }
                case 's': {
                    Segment seg = Segment::buildSegment(getColor);
                    segs.push_back(seg);
                    break;
                }
                case 'o': {
                    Circle c = Circle::buildCircle(getColor);
                    circs.push_back(c);
                    break;
                }
                case 'p': {
                    Polygone p = Polygone::buildPolygone(getColor);
                    pols.push_back(p);
                    break;
                }
                default:
                    break;
            }
            char rep;
            cout << "voulez vous dessiner une autre forme ? y/n ";
            cin >> rep;
            if(rep != 'y') {
                stop = true;
            } else {
                char save;
                cout << "voulez vous sauvegarder votre dessin ?(y/n) ";
                cin >> save;
                if(save == 'y') {
                    ::save<Rectangle>(recs);
                    ::save<Circle>(circs);
                    ::save<Polygone>(pols);
                    ::save<Segment>(segs);
                }
            }
            shapeChar = NULL;
        }
    }



    graphicsSetup(argc, argv, 800, 800);
    glutDisplayFunc(drawScene);
    glutMainLoop();
}
