#ifndef LINEA2D_H
#define LINEA2D_H
#include "Figura2D.h"
#include "Punto2D.h"
#include <GL/gl>

class Linea2D : public Figura2D {
	Punto2D* pinicial, pfinal;
	inline int round (const float value) { return static_cast<int>(value + 0.5) };
public:
	Linea2D (Punto2D, Punto2D);
	Linea2D (unsigned int = 0, unsigned int = 0, unsigned int = 1, unsigned int = 1);
	Linea2D (const Linea2D&);
	~Linea2D();
	virtual void dibujar();
};

#endif
