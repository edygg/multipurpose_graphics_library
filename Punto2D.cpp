#include "Punto2D.h"

Punto2D::Punto2D(int x, int y) : cx(x), cy(y) {}

Punto2D::Punto2D(const Punto2D& value) {
	this->cx = value.cx;
	this->cy = value.cy;	
}

Punto2D::~Punto2D() {}

void Punto2D::dibujar() {
	glBegin(GL_POINTS);
		glVertex2i(cx, cy);
	glEnd();
	glFlush();	
}

int Punto2D::getX() const {
	return cx;	
}

int Punto2D::getY() const {
	return cy;	
}

bool Punto2D::operator==(const Punto2D& val) const {
	if (this->cx == val.cx && this->cy == val.cy)
		return true;

	return false;
}


bool Punto2D::operator<(const Punto2D& val) const {
	if (this->cx < val.cx || this->cy <= val.cy)
		return true;

	return false;
}

bool Punto2D::operator>(const Punto2D& val) const {
	if (this->cx > val.cx || this->cy >= val.cy)
		return true;

	return false;
}

