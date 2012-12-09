#include "Linea2D.h"
#include <cmath>
using namespace std;

//Constructor que recibe 2 puntos como parámetros
Linea2D::Linea2D(Punto2D ini, Punto2D fin) {
	//Inicializa el punto inicial de la línea
	pinicial = new Punto2D(ini.getX(), ini.getY());
	//Inicializa el punto final de la línea
	pfinal = new Punto2D(fin.getX(), fin.getY());
}

//Constructor de cuatro parámetros enteros
Linea2D::Linea2D(int x1, int y1, int x2, int y2) {
	//Inicializa el punto inicial de la línea
	pinicial = new Punto2D(x1, y1);
	//Inicializa el punto final de la línea
	pfinal = new Punto2D(x2, y2);	
}

//Constructor de copia de la línea
Linea2D::Linea2D(const Linea2D& line) {
	//Copia el punto inicial
	pinicial = new Punto2D(line.pinicial->getX(), line.pinicial->getY());
	//Copia el punto final
	pfinal = new Punto2D(line.pfinal->getX(), line.pfinal->getY());
}

//Destructor
Linea2D::~Linea2D() {
	//Elimina el apuntador al punto inicial
	delete pinicial;
	//Elimina el apuntador al punto final
	delete pfinal;	
}

/****************************************************
 *      Especialización del método dibujar          *
 *  Utiliza un algoritmo sencillo de dibujo de      *
 *  línea basado en la fórmula punto pendiente.     *
 *  Se vale deĺ método dibujar de la clase Punto2D  *
 *  para mostrar en pantalla punto a punto la       *
 *  línea en cuestión.                              *
 ****************************************************/
void Linea2D::dibujar() {
	//Cambio en X: Fórmula de la pendiente
	int dx = pfinal->getX() - pinicial->getX();
	//Cambio en Y: Fórmula de la pendiente
	int dy = pfinal->getY() - pinicial->getY();
	//Almacena la cantidad de pasos, o sea la cantidad
	//de puntos a dibujar para representar la línea
	int steps;

	float increX, //Incremento en X
	      increY, //Incremento en Y
	      x = pinicial->getX(), //Coodenadas que se dibujan
	      y = pinicial->getY();
	
	//Se asignan la mayor cantidad de pasos posibles
	if (fabs(dx) > fabs(dy)) {
		steps = fabs(dx);	
	} else {
		steps = fabs(dy);	
	}

	//Incrementos se calculan a partir de la cantidad de pasos
	//y la pendiente de la recta
	increX = static_cast<float>(dx) / static_cast<float>(steps);
	increY = static_cast<float>(dy) / static_cast<float>(steps);

	//Iteración para el dibujo
	for (int k = 0; k < steps; k++) {
		x += increX; //Se aumenta la coordenada en X
		y += increY; //Se aumenta la coordenada en Y
		Punto2D tmp(round(x), round(y)); //Crea un punto temporal
		tmp.dibujar();	//Dibuja el punto temporal en la pantalla
	}
		
}

