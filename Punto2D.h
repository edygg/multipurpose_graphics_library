#ifndef PUNTO2D_H
#define PUNTO2D_H
#include "Figura2D.h"
#include <GL/gl.h>

class Punto2D : public Figura2D {
	int cx, cy;
public:
	Punto2D(int = 0, int = 0);
	Punto2D(const Punto2D&);
	virtual ~Punto2D();
	virtual void dibujar();
	int getX() const;
	int getY() const;
	bool operator==(const Punto2D&) const;
	bool operator<(const Punto2D&) const;
	bool operator>(const Punto2D&) const;
};

#endif
