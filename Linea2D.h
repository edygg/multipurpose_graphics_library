#ifndef LINEA2D_H
#define LINEA2D_H
//Clase padre Figura2D
#include "Figura2D.h"
//Clase Punto2D necesaria para dibujar
//lineas continuas
#include "Punto2D.h"
//Librería núcleo de OpenGL
#include <GL/gl.h>

/*************************************************
 *              Clase Hija Linea2D               *
 *  La clase Linea2D posee como atributos un     *
 *  punto inicial y un punto final que brindan   *
 *  los límites de una línea. Utiliza un         *
 *  algoritmo sencillo de dibujo de líneas. A    *
 *  futuro, pienso cambiarlo por el algoritmo    *
 *  de Bresenham.                                *
 *************************************************/
class Linea2D : public Figura2D {
	Punto2D* pinicial; //Punto inicial de la línea
	Punto2D* pfinal;   //Punto final de la línea

	//Función necesaria para redondear números decimales.
	//Recuerde que no puede representar coordenadas no
	//enteras en una matriz de pixeles
	inline int round (const float value) { return static_cast<int>(value + 0.5); }
public:
	//Constructor que recibe dos puntos como parámetros
	Linea2D (Punto2D, Punto2D);
	//Constructor que recibe cuantro enteros 
	//Coordenada en X inicial, coordenada en Y
	//inicial, coordenada en X final, coordenada en Y
	//final.
	Linea2D (int = 0, int = 0, int = 1, int = 1);
	//Constructor de copia
	Linea2D (const Linea2D&);
	//Destructor
	~Linea2D();
	//Método dibujar heredado de Figura2D
	virtual void dibujar();
};

#endif
