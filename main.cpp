#include <SFML\Graphics.hpp>
#include <iostream>
#include "player.h"
#include "platform.h"

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Sokoban",sf::Style::Close | sf::Style::Titlebar); //stworzenie okna gry
	//sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f)); //konstruktor gracza (X/Y)
	//player.setFillColor(sf::Color::Yellow); //wype�nienie kolorem
	
	sf::Texture playerTexture;
	playerTexture.loadFromFile("duzotuxow.png");
	


	player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 100.0f);
	float deltaTime = 0.0f;
	sf::Clock clock;
	
	platform platform1(nullptr, sf::Vector2f(400.0f, 2000.0f), sf::Vector2f(500.0f, 200.0f));

	platform platform2(nullptr, sf::Vector2f(200.0f, 150.0f), sf::Vector2f(300.0f, 0.0f));

	/*sf::Vector2u textureSize =playerTexture.getSize();
	textureSize.x /= 3;
	textureSize.y /= 9;
	
	player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 8, textureSize.x, textureSize.y)); */

	while (window.isOpen()) //gameloop
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type) //zamkni�cie okna
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		
		player.Update(deltaTime);

		platform1.Getcollider().CheckCollider(player.GetCollider(), 0.0f);
		platform2.Getcollider().CheckCollider(player.GetCollider(), 1.0f);

		window.clear(sf::Color(150,150,150)); //czyszczenie bufora
		player.Draw(window); //rysowanie gracza
		platform1.Draw(window);
		platform2.Draw(window);
		window.display();
	}

	return 0;
}