#ifndef POLIGONO2D_H
#define POLIGONO2D_H
//Clase padre Figura2D
#include "Figura2D.h"
//Clase Punto2D necesaria para representar los puntos
//de los vértices de un polígono
#include "Punto2D.h"
//Clase Vector para almacenar los puntos del polígono
#include <vector>
using namespace std;

/**************************************************
 *              Clase Hija Poligono2D             *
 *  La clase Poligono2D posee como atributo un    *
 *  vector de puntos. Los puntos deben ser        *
 *  almacenados para que esten dibujados en       *
 *  contra de las manecillas del reloj. Caso      *
 *  contrario las funciones de OpenGL no podrán   *
 *  graficar el punto en la pantalla. Esta clase  *
 *  Utiliza la clase Punto2D solo para almacenar  *
 *  las coordenadas de los vértices que la        *
 *  conforman. Tiene su propia función de OpenGL  *
 *  así como Punto2D, por lo tanto no depende del *
 *  método dibujar de ésta.                       *
 **************************************************/
class Poligono2D : public Figura2D {
	//Almacena los puntos de los vértices del polígono
	vector<Punto2D> puntos;
public:
	//Constructor de polígono
	Poligono2D();
	//Constructor de copia
	Poligono2D(const Poligono2D&);
	//Destructor
	~Poligono2D();
	//Método de dibujar heredado de Figura2D
	void dibujar();
	//Agrega puntos al vector, recibe dos parámetros la
	//coordenada en X y la coordenada en Y del vértice 
	bool agregarPunto(const int, const int);
};

#endif