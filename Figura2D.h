#ifndef FIGURA2D_H
#define FIGURA2D_H

/*************************************************
 *				Clase Padre Figura2D 			 *
 *	Todas las clases heredan de ésta. Posee un	 *
 *	método dibujar para que cada clase hija 	 *
 *	sobreescriba y especialice ese método		 *
 *************************************************/
class Figura2D {
public:
	//Método que será sobreescrito por cada una de
	//las clases hijas
	virtual void dibujar() = 0;
};

#endif
