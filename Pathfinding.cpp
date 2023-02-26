#include "Pathfinding.h"

void Pathfinding::initVariables()
{
	// Logic
	this->selecting = 1;
	this->changes = 1;

	// Components
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
	this->in.open("Resources/map.txt");
	if (!this->in.is_open())
	{
		std::cerr << "Could not load file \"map.txt\"";
	}

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

bool Pathfinding::path(int _row, int _col, int x)
{
	// Function recursively searches for a possible path
	this->Maze[_row][_col] = x;
	if (_row == 0 || _row == this->N - 1 || _col == 0 || _col == this->N - 1)
		return true;

	if (this->Maze[_row - 1][_col] == 0 && this->path(_row - 1, _col, x + 1))
		return true;
	if (this->Maze[_row + 1][_col] == 0 && this->path(_row + 1, _col, x + 1))
		return true;
	if (this->Maze[_row][_col - 1] == 0 && this->path(_row, _col - 1, x + 1))
		return true;
	if (this->Maze[_row][_col + 1] == 0 && this->path(_row, _col + 1, x + 1))
		return true;

	return false;
}

void Pathfinding::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}
}

void Pathfinding::updateMousePositions()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Pathfinding::updateSelecting()
{
	// Selecting logic
	for (int i = 0; i < this->blocks.size() && selecting; i++)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->blocks[i].getGlobalBounds().contains(this->mousePosView)
			&& this->Maze[i / 32][i % 32] == 0)
		{
			this->row = i / 32;
			this->col = i % 32;
			this->Maze[this->row][this->col] = -2;
			this->selecting = 0;
			this->changes = 1;

			if (path(this->row, this->col, 1))
				std::cout << "Path found";
			else
				std::cout << "Path not found";
		}
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
			else if (this->Maze[i][j] == -2)
				this->block.setFillColor(sf::Color::Red);
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
	this->updateMousePositions();
	this->updateSelecting();

	if (this->changes)
	{
		this->updateMaze();
	}
	this->changes = 0;
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