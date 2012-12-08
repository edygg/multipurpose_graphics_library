#include "Linea2D.h"
#include <cmath>
using namespace std;

Linea2D::Linea2D(Punto2D ini, Punto2D fin) {
	pinicial = new Punto2D(ini.getX(), ini.getY());
	pfinal = new Punto2D(fin.getX(), fin.getY());
}

Linea2D::Linea2D(int x1, int y1, int x2, int y2) {
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
	int dx = pfinal->getX() - pinicial->getX();
	int dy = pfinal->getY() - pinicial->getY();
	int steps;

	float increX , increY, x = pinicial->getX(), y = pinicial->getY();
	
	if (fabs(dx) > fabs(dy)) {
		steps = fabs(dx);	
	} else {
		steps = fabs(dy);	
	}

	increX = static_cast<float>(dx) / static_cast<float>(steps);
	increY = static_cast<float>(dy) / static_cast<float>(steps);

	for (int k = 0; k < steps; k++) {
		x += increX;
		y += increY;
		Punto2D tmp(round(x), round(y));
		tmp.dibujar();	
	}
		
}

