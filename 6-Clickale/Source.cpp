#include <SFML/window.hpp>
#include<SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
using namespace std;
using namespace sf;

class naveEnemiga {
public:
    Texture texture_nave;
    Sprite spriteNave;
    float escalaX;
    float escalaY;
    float enemigoX;
    float enemigoY;

    naveEnemiga() {
        texture_nave.loadFromFile("et.png");
        spriteNave.setTexture(texture_nave);

        escalaX = 160 / (float)texture_nave.getSize().x;
        escalaY = 160 / (float)texture_nave.getSize().y;
        spriteNave.setScale(escalaX, escalaY);
        
        enemigoX = (float)(rand() % (800 - 160));
        enemigoY = (float)(rand() % (800 - 160));
        spriteNave.setPosition(enemigoX, enemigoY);
    }
    void moverNave(){
        enemigoX = (float)(rand() % (800 - 160));
        enemigoY = (float)(rand() % (800 - 160));
        spriteNave.setPosition(enemigoX, enemigoY);
    }
    bool estaVivo(int mouseX, int mouseY){
        return (mouseX >= enemigoX && mouseX <= enemigoX + 160 && mouseY >= enemigoY && mouseY <= enemigoY + 160);
    }
};

class Crosshair {
public:
    Texture texture_mira;
    Sprite spriteMira;
    float escalaX;
    float escalaY;

    Crosshair() {
        texture_mira.loadFromFile("crosshair.png");
        spriteMira.setTexture(texture_mira);

        escalaX = 60 / (float)texture_mira.getSize().x;
        escalaY = 60 / (float)texture_mira.getSize().y;
        spriteMira.setScale(escalaX, escalaY);

        spriteMira.setOrigin((float)texture_mira.getSize().x / 2, (float)texture_mira.getSize().y / 2);
    }
    void moverMira(int mouseX, int mouseY) {
        spriteMira.setPosition(mouseX, mouseY);
    }
};

int main() {
    RenderWindow Ventana(VideoMode(800, 800, 32), "Unidad 4 Clickale");
    srand(time(NULL));
    Ventana.setMouseCursorVisible(false);

    naveEnemiga nave;
    Crosshair mira;

    int enemigosDerrotados = 0;

    while (Ventana.isOpen()){
        Event evt;

        while (Ventana.pollEvent(evt)){

            switch (evt.type) {

            case Event::Closed:
                Ventana.close();
                break;

            case Event::MouseMoved:
                mira.moverMira(evt.mouseMove.x, evt.mouseMove.y);

            case Event::MouseButtonPressed:
                if (evt.mouseButton.button == Mouse::Left) {
                    if (nave.estaVivo(evt.mouseButton.x, evt.mouseButton.y)){
                        enemigosDerrotados++;
                        cout << "Enemigos derrotados: "<< enemigosDerrotados << endl;
                        if (enemigosDerrotados == 5) {
                            cout << "Derroste a todos los enemigos";
                            Ventana.close();
                        }
                        nave.moverNave();
                    }
                }
            }
        }
        Ventana.clear();
        Ventana.draw(nave.spriteNave);
        Ventana.draw(mira.spriteMira);
        Ventana.display();
    }
    return 0;
}  