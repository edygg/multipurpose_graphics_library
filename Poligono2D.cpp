#include "Poligono2D.h"
//Constructor de polígono
Poligono2D::Poligono2D() {
}
//Constructor de copia
Poligono2D::Poligono2D(const Poligono2D& pol) {
	//Copia cada uno de los puntos del vector del otro polígono
	for (int i = 0; i < pol.puntos.size(); i++) {
		this->puntos.push_back(Punto2D(pol.puntos[i].getX(), pol.puntos[i].getY()));
	}
}

//Destructor
Poligono2D::~Poligono2D() {
	
}

//Agrega un punto al vector puntos
bool Poligono2D::agregarPunto(const int x, const int y) {
	
	//No compara que el punto esté en contra de las manecillas del reloj
	if (puntos.size() == 0) {
		puntos.push_back(Punto2D(x, y));
		return true;
	} else { 
		//Crea un punto temporal
		Punto2D tmp;
		tmp = puntos[puntos.size() - 1];
		//Crea un punto con las coordenas que vienen como parámetros
		Punto2D neo(x, y);

		//Compara que el punto está dibujado en contra de las manecillas del reloj
		if (tmp < neo) {
			puntos.push_back(Punto2D(x, y));
			return true;
		} 
	}

	return false;
}

//Método dibujar sobreescrito de la clase Figura2D
void Poligono2D::dibujar() {
	glBegin(GL_POLYGON); //Activa el modo de polígonos de OpenGL
		for (int i = 0; i < puntos.size(); i++) { //Comienza a dibujar vértice a vértice
			glVertex2i(puntos[i].getX(), puntos[i].getY());
		}
	glEnd(); //Termina la ejecución del dibujo de vértices
	glFlush();
}

