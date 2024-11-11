#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture texture_mira;
Sprite mira;

int main() {
	texture_mira.loadFromFile("crosshair.png");
	mira.setTexture(texture_mira);

	mira.setOrigin((float)texture_mira.getSize().x / 2, (float)texture_mira.getSize().y / 2);

	mira.setPosition(400, 400);

	RenderWindow Ventana(VideoMode(800, 800, 32), "Unidad 4 Crosshair");
	while (Ventana.isOpen()){
		Event evt;

		while (Ventana.pollEvent(evt)){
			switch (evt.type){

			case Event::Closed:
				Ventana.close();
				break;
			}
		}

		Ventana.clear();
		Ventana.draw(mira);
		Ventana.display();
	}
	return 0;
}
