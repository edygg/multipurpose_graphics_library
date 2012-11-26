#include "Punto2D.h"
#include <GL/glut.h>

GLuint reg;

void init(const int width, const int height) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	reg = glGenLists(1);
	
	glNewList(reg, GL_COMPILE);
		for (int i = 1; i < 200; i++ ) {
			Punto2D punto(i, i);
			punto.dibujar();
		}
	glEndList();

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, width, height, 0.0);	
}

void genDibujo(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glCallList(reg);
	glFlush();	
}

int main(int argc, char* argv[]) {
	const int width = 400, height = 400;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(width, height);
	glutCreateWindow("Prueba 1");
	init(width, height);
	glutDisplayFunc(genDibujo);
	glutMainLoop();

	return 0;	
}
