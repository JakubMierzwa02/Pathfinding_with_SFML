#include "Pathfinding.h"

// Initializer functions
void Pathfinding::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1024, 1024), "Pathfinding");
	this->window->setFramerateLimit(60);
}

Pathfinding::Pathfinding()
{
	this->initWindow();
}

Pathfinding::~Pathfinding()
{
	delete this->window;
}

void Pathfinding::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}
}

void Pathfinding::update()
{
	this->pollEvents();
}

void Pathfinding::render()
{
	this->window->clear();

	// Render stuff

	this->window->display();
}

void Pathfinding::run()
{
	// Game loop
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}
