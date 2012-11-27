#include "Linea2D.h"

Linea2D::Linea2D(Punto2D ini, Punto2D fin) {
	pinicial = new Punto2D(ini.getX(), ini.getY());
	pfinal = new Punto2D(fin.getX(), fin.getY());
}

Linea2D::Linea2D(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) {
	pinicial = new Punto2D(x1, y1);
	pfinal = new Punto2D(x2, y2);	
}

Linea2D::Linea2D(const Linea2D& line) {
	pinicial = new Punto2D(line.pinicial->getX(), line.pinicial->getY());
	pfinal = new Punto2D(line.pfinal->getX(), line.pfinal->getY());
}

Linea2D::~Linea2D() {
	delete pinicial;
	delete pfinal;	
}

void Linea2D::dibujar() {
		
}

