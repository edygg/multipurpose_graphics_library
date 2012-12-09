#include "Grafico2D.h"

Grafico2D::Grafico2D(const char* nom, const char* eti, const float dat[], unsigned int cant) {	
	this->nombre = new GLubyte[strlen(nom)];
	this->nombreLen = strlen(nom);
	for (int i = 0; i < strlen(nom); i++) {
		nombre[i] = nom[i]; 
	}

	this->etiquetas = new GLubyte[strlen(eti)];
	this->etiquetasLen = strlen(eti);
	for (int i = 0; i < strlen(eti); i++) {
		etiquetas[i] = eti[i];
	}

	this->datos = new GLfloat[cant];
	this->datosLen = cant;
	for (int i = 0; i < cant; i++) {
		datos[i] = dat[i];
	}

	this->delimitador = 3;
}

Grafico2D::Grafico2D(const Grafico2D&) {}

Grafico2D::~Grafico2D() {
	delete nombre;
	delete etiquetas;
	delete datos;
}

void Grafico2D::setDelimitador(unsigned int d) {
	this->delimitador = d;
}

void Grafico2D::dibujar() {
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2i(-40, 400);

	for (GLuint i = 0; i < nombreLen; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, nombre[i]);
	}

	GLint xRaster = -270;

	for (GLuint i = 0; i < etiquetasLen; i++) {
		if (i % delimitador == 0) {
			glRasterPos2i(xRaster, 0);
			xRaster += 50;
		}

		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, etiquetas[i]);
	}


	xRaster = -260;

	for (GLuint i = 0; i < datosLen - 1; i++) {
		Punto2D Ptmp1(xRaster, datos[i]);
		Punto2D Ptmp2(xRaster + 50, datos[i + 1]);
		Linea2D Ltmp(Ptmp1, Ptmp2);
		glColor3f(0.0, 0.3, 1.0);
		Ltmp.dibujar();
		glColor3f(1.0, 0.3, 0.0);
		Circulo2D Ctmp(Ptmp1, 4);
		Ctmp.dibujar();

		if (i == datosLen - 2) {
			Circulo2D Ctmp2(Ptmp2, 4);
			Ctmp2.dibujar();
		}

		xRaster += 50;
	}
}