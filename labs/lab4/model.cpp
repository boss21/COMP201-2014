#include "model.h"
#include <cstdlib>
#include <ctime>
// weee
using namespace std;

// Constructor initializes the object
Model::Model(int w, int h) {
    width = w;
    height = h;
	lastrow = -1;
	lastcolumn = -1;
	lastraw = -1;
	lastcal = -1;
    state = INIT;
    grid = new char*[h];
    visible = new char*[h];
    // For every row, create the array for that row
    for (int i = 0; i < height; i++) {
        grid[i] = new char[w];
        visible[i] = new char[w];
    }
   char letter = 'A';
	// Put stuff in in order
	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < width; j++) 
		{
			grid[i][j] = letter;
			visible [i][j] = '_';

			if ((j) % 2 == 1) {
				if (letter == 'Z') {
					letter = 'A';
				} else {
					letter++;
				}
			}
		}
	}
	srand(time(0));
	
	// Shuffle here
	/*
	int otheri, otherj;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) 
		{
			otheri = rand() % height;
			otherj = rand() % width;
			// Swap here
			letter = grid[i][j];
			grid[i][j] = grid[otheri][otherj];
			grid[otheri][otherj] = letter;
		}
	}
	*/
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
    for (int i = 0; i < height; i++) {
        delete grid[i];
        delete visible[i];
    }
    delete grid;
    delete visible;
}
// TODO: Is the row/column valid?
// That is, is the row within the height, and is the column within the width?
// Return whether it is or isn't.
bool Model::valid(int row, int column) {
    return (((row >= 0) && (row < height)) && ((column >= 0) && (column < width)));
}
bool Model::matched(int row, int column) {
    return true;
}
// TODO: Flip a cell
void Model::flip(int r, int c) {
    // If the row and column are not valid, break out and don't do anything
   if (!valid(r, c)) { return; }
	    if ((r == lastrow) && (c == lastcolumn)) { return; }
		if ((r == lastraw) && (c == lastcal)) { return; }
		switch (state)
		{
			case NO_MATCH:
			 visible[lastrow][lastcolumn] = '_';
			 visible[lastraw][lastcal] = '_';
			 lastrow = -1;
			 lastcolumn = -1;
			 lastraw = -1;
			 lastcal = -1;
			case INIT:
			visible[r][c] = grid[r][c];
			lastrow = r;
			lastcolumn = c;
			state = FIRST;
			break;
			case FIRST:
			visible[r][c] = grid[r][c];
			lastraw = r;
			lastcal = c;
			if (grid[lastrow][lastcolumn] != grid[lastraw][lastcal])
			{
				state = NO_MATCH;
			}
			else
			{
				state = INIT;
			}
			break;
		}
}
// If everything is visible, then it's game over
bool Model::gameOver() {
    // Assume the game is over
    bool isOver = true;
    // Loop through the grid and see if any element is not visible
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (visible[i][j] == '_') {
                isOver = false;
            }
        }
    }
    
    if (isOver) {
        // Set a nice game over message
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                visible[i][j] = '_';
            }
        }
        visible[2][3] = 'Y';
        visible[2][4] = 'O';
        visible[2][5] = 'U';
        visible[4][3] = 'W';
        visible[4][4] = 'I';
        visible[4][5] = 'N';
    }
    return isOver;
}
int Model::getWidth() {
    return width;
}
int Model::getHeight() {
    return height;
}
char Model::get(int row, int col) {
    return visible[row][col];
}
