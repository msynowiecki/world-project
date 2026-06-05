#include <cmath>
#include "Position.h"


Position::Position(int x, int y) {
	setX(x);
	setY(y);
}

int Position::getX() const { return this->x; }
void Position::setX(int x) {
	if (x >= 0)
		this->x = x;
	else
		this->x = 0;
}

int Position::getY() const { return this->y; }
void Position::setY(int y) {
	if (y >= 0)
		this->y = y;
	else
		this->y = 0;
}

string Position::toString() const {
	return "(" + to_string(getX()) + ", " + to_string(getY()) + ")";
}

double Position::distance(Position position) const {
	double distanceX = (double)this->getX() - (double)position.getX();
	double distanceY = (double)this->getY() - (double)position.getY();
	return sqrt( (distanceX * distanceX) + (distanceY * distanceY) );
}

void Position::move(int distanceX, int distanceY) {
	setX(getX() + distanceX);
	setY(getY() + distanceY);
}