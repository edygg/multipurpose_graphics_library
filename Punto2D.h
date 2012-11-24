#ifndef PUNTO2D_H
#define PUNTO2D_H
#include "Figura2D.h"
#include <Gl/gl.h>

class Punto2D : public Figura2D {
	unsigned int x, y;
public:
	Punto2D(unsigned int, unsigned int);
	Punto2D(const Punto2D&);
	virtual ~Punto2D();
	virtual dibujar();
	unsigned int getX() const;
	unsigned int getY() const;
};

#endif
