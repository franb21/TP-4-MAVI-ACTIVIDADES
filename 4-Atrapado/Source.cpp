#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture texture_cuad;
Texture texture_circulo;
Sprite cuadrado;
Sprite circulo;

float escalaX;
float escalaY;
float posX = 400;
float posY = 400;
bool cambio = false;

int main() {
	texture_cuad.loadFromFile("cuad_yellow.png");
	texture_circulo.loadFromFile("rcircleg.png");

	cuadrado.setTexture(texture_cuad);
	circulo.setTexture(texture_circulo);

	escalaX = 100 / (float)texture_cuad.getSize().x;
	escalaY = 100 / (float)texture_cuad.getSize().y;
	cuadrado.setScale(escalaX, escalaY);

	escalaX = 100 / (float)texture_circulo.getSize().x;
	escalaY = 100 / (float)texture_circulo.getSize().y;
	circulo.setScale(escalaX, escalaY);

	cuadrado.setOrigin((float)texture_cuad.getSize().x / 2, (float)texture_cuad.getSize().y / 2);
	circulo.setOrigin((float)texture_circulo.getSize().x / 2, (float)texture_circulo.getSize().y / 2);

	cuadrado.setPosition(400, 400);
	circulo.setPosition(400, 400);

	RenderWindow Ventana(VideoMode(800, 800, 32), "Unidad 4 Atapado");
	while (Ventana.isOpen()){
		Event evt;

		while (Ventana.pollEvent(evt)){
			switch (evt.type){

			case Event::Closed:
				Ventana.close();
				break;

			case Event::KeyPressed:
				if (evt.key.code == Keyboard::Space){
					if (cambio == false) {
						cambio = true;
					}
					else
						cambio = false;
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Up) == true && posY >= 0 + 50){
				posY -= 20;
			}
			if (Keyboard::isKeyPressed(Keyboard::Right) == true && posX <= 800 - 50){
				posX += 20;
			}
			if (Keyboard::isKeyPressed(Keyboard::Down) == true && posY <= 800 - 50){
				posY += 20;
			}
			if (Keyboard::isKeyPressed(Keyboard::Left) == true && posX >= 0 + 50){
				posX -= 20;
			}
			if (cambio == true){
				circulo.setPosition(posX, posY);
			}
			else
				cuadrado.setPosition(posX, posY);
		}
		Ventana.clear();

		if (cambio == true){
			Ventana.draw(circulo);

		} else 
			Ventana.draw(cuadrado);

		Ventana.display();
	}
	return 0;
}
