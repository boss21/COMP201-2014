#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model(int w, int h) {
    width = w;
    height = h;
    Coordinate head;
    Coordinate tail;
    direction = RIGHT;
    head.x = 1;
    head.y = 0;
    tail.x = 0;
    tail.y = 0;
    food.x = 5;
    food.y = 10;
    snake.push_front(head);
    snake.push_back(tail);
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
}

bool Model::gameOver() {
    return snake.empty() || snake.size() == width * height;
}

// Which way should the snake face?
void Model::go(Direction d) {
    direction = d;
}

// Move foward
void Model::crawl() {
	srand(time(NULL));
    Coordinate front = snake.front();
    switch(direction) {
    case UP: front.y--; break;
    case DOWN: front.y++; break;
    case LEFT: front.x--; break;
    case RIGHT: front.x++; break;
    }
    // TODO: Colliding with the perimeter of the screen should set direction to DEAD
    // When DEAD, the snake slowly shrinks down to nothing (DONE)
	
	//the game ends when the tail goes off the grid, how to fix this?
	// how to make the snake not be able to collide with itself, or it loses, also
    // how to shrink down to nothing before displaying death message?!?!?!??!
	if ((front.x > width) || (front.y > height) || (front.x < 0) || (front.y < 0))
	{
		direction = DEAD;
	}
    if (direction != DEAD) {
        snake.push_front(front); // creates new head and puts it in the front
    }

    // TODO: Colliding with food grows the snake (so don't pop_back in that case)
	 // TODO: Also, colliding with food should cause us to place the food somewhere
    // else, but not anywhere on the snake.
	if (front.x == food.x && front.y == food.y)
	{
		food.x = rand() % 40;
		food.y = rand() % 40;
		
	}
    else
	{
    snake.pop_back(); // removes one from back
	}
}
