#include "Punto2D.h"
#include "Linea2D.h"
#include "Circulo2D.h"
#include "Poligono2D.h"
#include "Grafico2D.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <cstring>
using namespace std;

GLuint reg;

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	reg = glGenLists(1);
	
	glNewList(reg, GL_COMPILE);
		/*
		glColor3f(0.2, 0.3, 0.5);
		Linea2D tmp(-200, -200, 200, 200);
		tmp.dibujar();
		Circulo2D c(-100, -100, 50);
		c.dibujar();
		Poligono2D poli;
		poli.agregarPunto(1, 0);
		poli.agregarPunto(100, 0);
		poli.agregarPunto(100, 100);
		poli.agregarPunto(1, 100);
		poli.dibujar();
		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2i(50, -100);
		*/
		float dat[] = {300, 342, 324, 310, 262, 185, 190, 196, 217, 240, 312, 438};
		Grafico2D g("Prueba 1", "JanFebMarAbrMayJunJulAgoSepOctNovDic", dat, 12);
		g.dibujar();
	glEndList();
}

void winReshapeFcn(int newWidth, int newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-1 * (newWidth / 2), newWidth / 2, -1 * (newHeight / 4), 3 * newHeight / 4);
}

void genDibujo(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glCallList(reg);
	glFlush();	
}

int main(int argc, char* argv[]) {
	const int width = 670, height = 600;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(width, height);
	glutCreateWindow("Prueba 1");
	init();
	glutDisplayFunc(genDibujo);
	glutReshapeFunc(winReshapeFcn);
	glutMainLoop();

	return 0;	
}
