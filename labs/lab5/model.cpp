#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model(int w, int h) {
	ended = false;
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
	
	eat = false;
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

// Return true if the front of the snake has the same coordinate as the food
bool Model::eating() {
    return eat;
}

void Model::end() {
    ended = true;
}

// Move foward
void Model::crawl(Model * model) {
    // Coordinate front = snake.front();
	Coordinate front = snake.peek_front();
			// make snake not be allowed
			// to hit itself?

		switch(direction) 
		{
		case UP: front.y--; break;
		case DOWN: front.y++; break;
		case LEFT: front.x--; break;
		case RIGHT: front.x++; break;
		}
    // TODO: Colliding with the perimeter of the screen should set direction to DEAD
    // When DEAD, the snake slowly shrinks down to nothing
    
    if (direction != DEAD) {
        snake.push_front(front);
    }
	//reset eat first
	eat = false;
	
	//tell if it hits itself and if so, kill it
	Node<Coordinate> * it = model->snake.begin();
	it = it->next;
	while (it != model->snake.end())
	{
		if((front.x == it->data.x) && (front.y == it->data.y))
		{
			end();
			go(DEAD);
		}
		it = it->next;
		
	}
	
	if(front.x < 0 || front.y < 0 || front.x > 39 || front.y > 39)
	{
		//hit the wall
		end();
		go(DEAD);
	}
	
	//eat food
	if(food.x == front.x && food.y == front.y)
	{
		//eat the food, don't take back off, we want to grow
		//play sound effect
		eat = true;	
		//replace food
		food.x = rand() % width;
		food.y = rand() % height;
	}
	else
	{
		if (direction != DEAD)
		{
			snake.pop_back();
		}
		else
		{
			snake.pop_front();
		}
	}
    // TODO: Colliding with food grows the snake (so don't pop_back in that case)
    // TODO: Also, colliding with food should cause us to place the food somewhere
    // else, but not anywhere on the snake.
}
