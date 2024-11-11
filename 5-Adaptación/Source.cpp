#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

float minX = 100;
float minY = 100;
float maxX = 1000;
float maxY = 1000;

int main() {
    RenderWindow Ventana(VideoMode(800, 800, 32), "Unidad 4 Adaptación");
    while (Ventana.isOpen()){
        Event evt;

        while (Ventana.pollEvent(evt)){
            switch (evt.type){

            case Event::Closed:
                Ventana.close();
                break;

            case Event::Resized:
                float nuevaX = evt.size.width;
                float nuevaY = evt.size.height;

                if (nuevaX < minX) nuevaX = minX;
                if (nuevaX > maxX) nuevaX = maxX;
                if (nuevaY < minY) nuevaY = minY;
                if (nuevaY > maxY) nuevaY = maxY;

                Ventana.setSize(Vector2u(nuevaX, nuevaY));
                break;
            }
        }
        Ventana.clear();
        Ventana.display();
    }
    return 0;
}