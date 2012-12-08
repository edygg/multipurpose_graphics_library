#ifndef CIRCULO2D_H
#define CIRCULO2D_H
#define PI 3.141592654
#include "Figura2D.h"
#include "Punto2D.h"
#include <cmath>
using namespace std;

class Circulo2D : public Figura2D {
	Punto2D* coordCentro;
	unsigned int radio;
	inline int round (const float value) { return static_cast<int>(value + 0.5); }
	inline double toRadians(const float grades) { return static_cast<double>(grades * (PI / 180.0)); }
public:
	Circulo2D(Punto2D, unsigned int);
	Circulo2D(unsigned int = 0, unsigned int = 0, unsigned int = 10);
	Circulo2D(const Circulo2D&);
	void dibujar();
	~Circulo2D();
};

#endif