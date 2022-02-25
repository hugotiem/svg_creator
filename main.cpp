#include <iostream>
#include "src/Rectangle.cpp"

using namespace std;

int main() {
    char stop;
    while(stop != 'q') {
        int x, y;
        char color;
        cout << "Hello, Veuillez selectionner les dimensions de votre dessin :\nx:";
        cin >> x;
        cout << " and y:";
        cin >> y;
        cout << "Selectionnez une couleur (v=vert, r=rouge, b=bleu, o=orange:";
        cin >> color;
        auto *rectangle = new Rectangle(color, x, y);
        rectangle->draw();

        cout << "presse q pour quitter et une autre touche pour continuer";
        cin >> stop;
    }

    return 0;
}
