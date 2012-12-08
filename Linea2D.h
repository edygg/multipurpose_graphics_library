#ifndef LINEA2D_H
#define LINEA2D_H
#include "Figura2D.h"
#include "Punto2D.h"
#include <GL/gl.h>

class Linea2D : public Figura2D {
	Punto2D* pinicial; 
	Punto2D* pfinal;
	inline int round (const float value) { return static_cast<int>(value + 0.5); }
public:
	Linea2D (Punto2D, Punto2D);
	Linea2D (int = 0, int = 0, int = 1, int = 1);
	Linea2D (const Linea2D&);
	~Linea2D();
	virtual void dibujar();
};

#endif
