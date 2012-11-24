#include "Punto2D.h"

Punto2D::Punto2D(unsigned int x, unsigned int y) : cx(x), cy(y) {}

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

unsigned int Punto2D::getX() const {
	return cx;	
}

unsigned int Punto2D::getY() const {
	return cy;	
}

