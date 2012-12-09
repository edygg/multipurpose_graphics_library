#ifndef CIRCULO2D_H
#define CIRCULO2D_H
//Constante Pi
#define PI 3.141592654
//Clase Padre Figura2D
#include "Figura2D.h"
//Clase Punto2D necesaria para dibujar
//un círculo
#include "Punto2D.h"
//Librería matemática de C++ necesaria 
//por sus funciones de seno y coseno.
#include <cmath>
using namespace std;

/*************************************************
 *              Clase Padre Figura2D             *
 *  Todas las clases heredan de ésta. Posee un   *
 *  método dibujar para que cada clase hija      *
 *  sobreescriba y especialice ese método        *
 *************************************************/
class Circulo2D : public Figura2D {
	//Punto que representa el centro del círculo
	Punto2D* coordCentro;

	//Radio del círculo
	unsigned int radio;

	//Función necesaria para redondear números decimales.
	//Recuerde que no puede representar coordenadas no
	//enteras en una matriz de pixeles
	inline int round (const float value) { return static_cast<int>(value + 0.5); }

	//Convierte un ángulo de grados a radianes
	inline double toRadians(const float grades) { return static_cast<double>(grades * (PI / 180.0)); }
public:
	//Constructor que recibe dos parámetros un punto
	//que representa el centro del círculo y el valor 
	//que representa el radio del circulo
	Circulo2D(Punto2D, unsigned int);

	//Constructor que recibe tres parámetros: 
	//los primeros dos representan las coordenadas en 
	//X y Y del punto central del círulo, el tercero 
	//representa el valor del rádio del círculo
	Circulo2D(int = 0, int = 0, unsigned int = 10);

	//Constructor de copia
	Circulo2D(const Circulo2D&);

	//Método dibujar heredado de la clase Figura2D
	void dibujar();
	
	//Destructor
	~Circulo2D();
};

#endif