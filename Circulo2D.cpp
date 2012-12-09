#include "Circulo2D.h"

//Constructor que recibe dos parámetros un punto
//que representa el centro del círculo y el valor 
//que representa el radio del circulo
Circulo2D::Circulo2D(Punto2D centro, unsigned int radio) {
	this->coordCentro = new Punto2D(centro.getX(), centro.getY());
	this->radio = radio;
}

//Constructor que recibe tres parámetros: 
//los primeros dos representan las coordenadas en 
//X y Y del punto central del círulo, el tercero 
//representa el valor del rádio del círculo
Circulo2D::Circulo2D(int x, int y, unsigned int r) {
	this->coordCentro = new Punto2D(x, y);
	this->radio	= r;
}

//Constructor de copia
Circulo2D::Circulo2D(const Circulo2D& circulo) {
	//Crea una copia del punto central
	this->coordCentro = new Punto2D(circulo.coordCentro->getX(), circulo.coordCentro->getY());
	//Crea una copia del valor del radio
	this->radio = circulo.radio;
}

//Destructor
Circulo2D::~Circulo2D() {
	//Elimina el apuntador del punto central del círculo
	delete coordCentro;
}

/****************************************************
 *      Especialización del método dibujar          *
 *  Utiliza un algoritmo que dibuja un punto        *
 *  comenzando por el punto que sería el intercepto *
 *  en X luego, va en pasos de 0.5 grados en        *
 *  contra de las manecillas del reloj hasta llegar *
 *  al mismo punto.                                 *
 ****************************************************/
void Circulo2D::dibujar() {
	//Coordenadas del punto que sería en intercepto en X
	double x = coordCentro->getX(), y = coordCentro->getY();
	//Angulo Theta
	double theta = 0;
	
	//Utilizando las ecuaciones x = x del centro + radio * cos(theta)
	//y = y del centro + radio * sin(theta), se genera el dibujo del
	//círculo
	while (theta <= 360.0) {
		//Se crea un punto temporal con las coordenadas calculadas 
		//mediante las ecuaciones anteriores
		Punto2D tmp1(round(x + radio * cos(toRadians(theta))), round(y + radio * sin(toRadians(theta))));
		//se imprime el punto en pantalla
		tmp1.dibujar();
		//Se suma 0.5 grados al ángulo
		theta += 0.5;
	}


}
