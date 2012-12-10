#include "Poligono2D.h"
//Constructor de polígono
Poligono2D::Poligono2D() {
}
//Constructor de copia
Poligono2D::Poligono2D(const Poligono2D& pol) {
	//Copia cada uno de los puntos del vector del otro polígono
	for (int i = 0; i < pol.puntos.size(); i++) {
		this->puntos.push_back(Punto2D(pol.puntos[i].getX(), pol.puntos[i].getY()));
	}
}

Poligono2D::~Poligono2D() {
	
}

bool Poligono2D::agregarPunto(const int x, const int y) {
	

	if (puntos.size() == 0) {
		puntos.push_back(Punto2D(x, y));
		return true;
	} else {
		Punto2D tmp;
		tmp = puntos[puntos.size() - 1];
		Punto2D neo(x, y);

		if (tmp < neo) {
			puntos.push_back(Punto2D(x, y));
			return true;
		} 
	}

	return false;
}

void Poligono2D::dibujar() {
	glBegin(GL_POLYGON);
		for (int i = 0; i < puntos.size(); i++) {
			glVertex2i(puntos[i].getX(), puntos[i].getY());
		}
	glEnd();
	glFlush();
}

