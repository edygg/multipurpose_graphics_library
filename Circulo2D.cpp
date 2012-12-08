#include "Circulo2D.h"

Circulo2D::Circulo2D(Punto2D centro, unsigned int radio) {
	this->coordCentro = new Punto2D(centro.getX(), centro.getY());
	this->radio = radio;
}

Circulo2D::Circulo2D(unsigned int x, unsigned int y, unsigned int r) {
	this->coordCentro = new Punto2D(x, y);
	this->radio	= r;
}

Circulo2D::Circulo2D(const Circulo2D& circulo) {
	this->coordCentro = new Punto2D(circulo.coordCentro->getX(), circulo.coordCentro->getY());
	this->radio = circulo.radio;
}

Circulo2D::~Circulo2D() {
	delete coordCentro;
}

void Circulo2D::dibujar() {
	double x = coordCentro->getX(), y = coordCentro->getY();
	double theta = 0;
	
	while (theta <= 360.0) {
		Punto2D tmp1(round(x + radio * cos(toRadians(theta))), round(y + radio * sin(toRadians(theta))));
		tmp1.dibujar();
		theta += 0.5;
	}


}
