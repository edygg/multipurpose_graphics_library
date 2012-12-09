#ifndef GRAFICO2D_H
#define GRAFICO2D_H
#include "Figura2D.h"
#include "Punto2D.h"
#include "Linea2D.h"
#include "Circulo2D.h"
#include <GL/glut.h>
#include <cstring>
using namespace std;

class Grafico2D : public Figura2D {
	GLubyte* nombre;
	GLuint nombreLen;
	GLubyte* etiquetas;
	GLuint etiquetasLen;
	GLfloat* datos;
	GLuint datosLen;
	unsigned int delimitador;
	Grafico2D(const Grafico2D&);
public:
	Grafico2D(const char*, const char*, const float[] , unsigned int);
	~Grafico2D();
	void setDelimitador(unsigned int);
	void dibujar();
};

#endif