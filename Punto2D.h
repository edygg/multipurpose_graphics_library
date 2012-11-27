#ifndef PUNTO2D_H
#define PUNTO2D_H
#include "Figura2D.h"
#include <GL/gl.h>

class Punto2D : public Figura2D {
	unsigned int cx, cy;
public:
	Punto2D(unsigned int = 0, unsigned int = 0);
	Punto2D(const Punto2D&);
	virtual ~Punto2D();
	virtual void dibujar();
	unsigned int getX() const;
	unsigned int getY() const;
};

#endif
