#include <iostream>
#include <cmath>

#include <SFML/Graphics.hpp>

int main()
{
	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML test");
	sf::Color backgroundColor(0, 0, 0);

	float randX = (float)(rand() % 10) / 15.0f;
	float randY = (float)(rand() % 10) / 15.0f;

	sf::Vector2f circleDir(randX, randY);
	sf::Color circleCol(rand() % 256, rand() % 256, rand() % 256);

	sf::CircleShape circle(100.0f);
	circle.setPosition(sf::Vector2f((window.getSize().x / 2.0f) - 100.0f, (window.getSize().y / 2.0f) - 100.0f));
	circle.setFillColor(circleCol);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(backgroundColor);

		// Collision detection
		if (circle.getPosition().x < 0
			|| circle.getPosition().x >(window.getSize().x - circle.getRadius() * 2))
		{
			circleCol.r = rand() % 256;
			circleCol.g = rand() % 256;
			circleCol.b = rand() % 256;

			circleDir.x *= -1.0f;

			int avgCol = abs(255 - ((circleCol.r + circleCol.g + circleCol.b) / 3));
			backgroundColor.r = avgCol;
			backgroundColor.g = avgCol;
			backgroundColor.b = avgCol;

			circle.setFillColor(circleCol);
		}

		if (circle.getPosition().y < 0
			|| circle.getPosition().y >(window.getSize().y - circle.getRadius() * 2))
		{
			circleCol.r = rand() % 256;
			circleCol.g = rand() % 256;
			circleCol.b = rand() % 256;

			circleDir.y *= -1.0f;

			int avgCol = abs(255 - ((circleCol.r + circleCol.g + circleCol.b) / 3));
			backgroundColor.r = avgCol;
			backgroundColor.g = avgCol;
			backgroundColor.b = avgCol;

			circle.setFillColor(circleCol);
		}

		circle.move(circleDir);
		window.draw(circle);

		window.display();
	}

	return 0;
}