#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture texture_rojo;
Texture texture_azul;
Sprite puntoRojo;
Sprite puntoAzul;

int main() {
	texture_rojo.loadFromFile("rcircle.png");
	texture_azul.loadFromFile("rcircleb.png");

	puntoRojo.setTexture(texture_rojo);
	puntoAzul.setTexture(texture_azul);

	RenderWindow Ventana(VideoMode(800, 800, 32), "Unidad 4 Splats");
	while (Ventana.isOpen()){
		Event evt;

		while (Ventana.pollEvent(evt)){
			switch (evt.type){

			case Event::Closed:
				Ventana.close();
				break;

			case Event::MouseButtonPressed:
				if (evt.mouseButton.button == Mouse::Left){
					puntoRojo.setPosition(evt.mouseButton.x - 64, evt.mouseButton.y - 64);
					Ventana.draw(puntoRojo);
				}if (evt.mouseButton.button == Mouse::Right){
					puntoAzul.setPosition(evt.mouseButton.x - 64, evt.mouseButton.y - 64);
					Ventana.draw(puntoAzul);
				}
			}
		}
		Ventana.display();
	}
	return 0;
}
