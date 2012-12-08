#ifndef POLIGONO2D_H
#define POLIGONO2D_H
#include "Figura2D.h"
#include "Punto2D.h"
#include <vector>
using namespace std;

class Poligono2D : public Figura2D {
	vector<Punto2D> puntos;
public:
	Poligono2D();
	Poligono2D(const Poligono2D&);
	~Poligono2D();
	void dibujar();
	bool agregarPunto(const int, const int);
	bool eliminarPunto(const Punto2D);
};

#endif