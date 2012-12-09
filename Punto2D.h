#ifndef PUNTO2D_H
#define PUNTO2D_H
//Clase padre de Punto2D
#include "Figura2D.h"
//Librería núcleo de OpenGL
#include <GL/gl.h>

/*************************************************
 *              Clase Hija Punto2D               *
 *  La clase Punto2D posee como atributos las    *
 *  las coordenadas en X y Y de un punto en el   * 
 *  plano cartesiano. Es importante mencionar    *
 *  que la clase está diseñada para almacenar    *
 *  y representar coordenadas tanto positivas    *
 *  como negativas.                              *
 *************************************************/
class Punto2D : public Figura2D {
	int cx, //Coordenada en x del punto 
		cy; //Coordenada en y del punto
public:
	//Constructor predeterminado (0, 0)
	Punto2D(int = 0, int = 0);
	//Constructor de copia
	Punto2D(const Punto2D&);
	//Destructor de la clase Punto2D
	virtual ~Punto2D();
	//Se sobreescribe el método dibujar de la clase
	//Figura2D
	virtual void dibujar();
	//Accesores
	int getX() const;
	int getY() const;
	//Sobrecarga de operadores
	bool operator==(const Punto2D&) const;
	bool operator<(const Punto2D&) const;
	bool operator>(const Punto2D&) const;
};

#endif
