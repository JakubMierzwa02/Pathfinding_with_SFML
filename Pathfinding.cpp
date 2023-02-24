#include "Pathfinding.h"

// Initializer functions
void Pathfinding::initVariables()
{
	this->block.setSize(sf::Vector2f(this->gridSize, this->gridSize));
}

void Pathfinding::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1024, 1024), "Pathfinding");
	this->window->setFramerateLimit(60);
}

void Pathfinding::loadMaze()
{
	std::string s;
	this->in.open("map.txt");

	for (size_t i = 0; i < this->N; i++)
	{
		this->in >> s;
		for (size_t j = 0; j < this->N; j++)
		{
			if (s[j] == '#')
				this->Maze[i][j] = -1;
			else
				this->Maze[i][j] = 0;
		}
	}

	this->in.close();
}

Pathfinding::Pathfinding()
{
	this->initVariables();
	this->initWindow();
	this->loadMaze();
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

void Pathfinding::updateMaze()
{
	float pos_x = 0;
	float pos_y = 0;

	for (int i = 0; i < this->N; i++)
	{
		for (int j = 0; j < this->N; j++)
		{
			if (this->Maze[i][j] == -1)
				this->block.setFillColor(sf::Color::Black);
			else
				this->block.setFillColor(sf::Color::White);

			this->block.setPosition(pos_x, pos_y);
			this->blocks.push_back(this->block);
			pos_x += this->gridSize;
		}
		pos_y += this->gridSize;
		pos_x = 0;
	}
}

void Pathfinding::update()
{
	this->pollEvents();
	this->updateMaze();
}

void Pathfinding::renderMaze()
{
	for (size_t i = 0; i < this->blocks.size(); i++)
		this->window->draw(this->blocks[i]);
}

void Pathfinding::render()
{
	this->window->clear();

	// Render stuff
	this->renderMaze();

	this->window->display();
}

void Pathfinding::run()
{
	// Main loop
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}
