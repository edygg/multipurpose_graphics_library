#include "Punto2D.h"
//Constructor predeterminado de punto
//Valor predeterminado (0, 0)
Punto2D::Punto2D(int x, int y) : cx(x), cy(y) {}

//Constructor de copia
Punto2D::Punto2D(const Punto2D& value) {
	this->cx = value.cx;
	this->cy = value.cy;	
}

//Destructor
Punto2D::~Punto2D() {}

/****************************************************
 *      Especialización del método dibujar          *
 *  Cambia el modo de OpenGL a dibujo de puntos     *
 *  en pantalla.                                    *
 ****************************************************/
void Punto2D::dibujar() {
	glBegin(GL_POINTS);
		glVertex2i(cx, cy);
	glEnd();
	glFlush();	
}

//Retorna el valor de X almacenado 
int Punto2D::getX() const {
	return cx;	
}

//Retorna el valor de Y almacenado
int Punto2D::getY() const {
	return cy;	
}

//Compara si dos puntos son iguales por medio 
//del valor X y Y de ambos puntos
bool Punto2D::operator==(const Punto2D& val) const {
	//Si los valores de X y Y de ambos puntos son
	//iguales retorna true, caso contrario retorna
	//false
	if (this->cx == val.cx && this->cy == val.cy)
		return true;

	return false;
}

//Compara si un punto es menor que otro
bool Punto2D::operator<(const Punto2D& val) const {
	if (this->cx < val.cx || this->cy <= val.cy)
		return true;

	return false;
}

//Compara si un punto es mayor que otro
bool Punto2D::operator>(const Punto2D& val) const {
	if (this->cx > val.cx || this->cy >= val.cy)
		return true;

	return false;
}

