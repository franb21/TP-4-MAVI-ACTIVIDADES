#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture texture_rojo;
Sprite puntorojo1;
Sprite puntorojo2;
Sprite puntorojo3;
Sprite puntorojo4;

bool mover1 = false;
bool mover2 = false;
bool mover3 = false;
bool mover4 = false;

int main() {
	texture_rojo.loadFromFile("rcircle.png");

	puntorojo1.setTexture(texture_rojo);
	puntorojo2.setTexture(texture_rojo);
	puntorojo3.setTexture(texture_rojo);
	puntorojo4.setTexture(texture_rojo);

	puntorojo1.setPosition(64, 64);
	puntorojo2.setPosition(800 - 64, 64);
	puntorojo3.setPosition(64, 600 - 64);
	puntorojo4.setPosition(800 - 64, 600 - 64);

    puntorojo1.setOrigin((float)texture_rojo.getSize().x / 2, (float)texture_rojo.getSize().y / 2);
    puntorojo2.setOrigin((float)texture_rojo.getSize().x / 2, (float)texture_rojo.getSize().y / 2);
    puntorojo3.setOrigin((float)texture_rojo.getSize().x / 2, (float)texture_rojo.getSize().y / 2);
    puntorojo4.setOrigin((float)texture_rojo.getSize().x / 2, (float)texture_rojo.getSize().y / 2);

	RenderWindow Ventana(VideoMode(800, 600, 32), "Unidad 4 Drag");
	while (Ventana.isOpen()){
		Event evt;

		while (Ventana.pollEvent(evt)){
			switch (evt.type) {

			case Event::Closed:
                Ventana.close();
				break;

            case Event::MouseButtonPressed:
                if (evt.mouseButton.button == Mouse::Left){

                    if (evt.mouseButton.x >= puntorojo1.getPosition().x - 64 && evt.mouseButton.x <= puntorojo1.getPosition().x + 64 &&
                        evt.mouseButton.y >= puntorojo1.getPosition().y - 64 && evt.mouseButton.y <= puntorojo1.getPosition().y + 64){
                        mover1 = true;
                    }
                    else if (evt.mouseButton.x >= puntorojo2.getPosition().x - 64 && evt.mouseButton.x <= puntorojo2.getPosition().x + 64 &&
                            evt.mouseButton.y >= puntorojo2.getPosition().y - 64 && evt.mouseButton.y <= puntorojo2.getPosition().y + 64){
                        mover2 = true;
                    }
                    else if (evt.mouseButton.x >= puntorojo3.getPosition().x - 64 && evt.mouseButton.x <= puntorojo3.getPosition().x + 64 &&
                            evt.mouseButton.y >= puntorojo3.getPosition().y - 64 && evt.mouseButton.y <= puntorojo3.getPosition().y + 64){
                        mover3 = true;
                    }
                    else if (evt.mouseButton.x >= puntorojo4.getPosition().x - 64 && evt.mouseButton.x <= puntorojo4.getPosition().x + 64 &&
                            evt.mouseButton.y >= puntorojo4.getPosition().y - 64 && evt.mouseButton.y <= puntorojo4.getPosition().y + 64){
                        mover4 = true;
                    }
                }
                break;

            case Event::MouseButtonReleased:
                mover1 = false;
                mover2 = false;
                mover3 = false;
                mover4 = false;
                break;

            case Event::MouseMoved:
                if (mover1){
                    puntorojo1.setPosition(evt.mouseMove.x, evt.mouseMove.y);
                }
                if (mover2){
                    puntorojo2.setPosition(evt.mouseMove.x, evt.mouseMove.y);
                }
                if (mover3){
                    puntorojo3.setPosition(evt.mouseMove.x, evt.mouseMove.y);
                }
                if (mover4){
                    puntorojo4.setPosition(evt.mouseMove.x, evt.mouseMove.y);
                }
                break;
			}
		}
        Ventana.clear();
        Ventana.draw(puntorojo1);
        Ventana.draw(puntorojo2);
        Ventana.draw(puntorojo3);
        Ventana.draw(puntorojo4);
        Ventana.display();
	}
	return 0;
}