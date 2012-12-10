#include "Grafico2D.h"

//Constructor que recibe un const char* con el nombre
//otro const char* con las etiquetas juntas y sin espacios
//un const float[] que contiene una tupla de datos a graficar
//y un unsigned int con la cantidad de datos que contiene la tupla
Grafico2D::Grafico2D(const char* nom, const char* eti, const float dat[], unsigned int cant) {	
	//Se almacena el nombre
	this->nombre = new GLubyte[strlen(nom)];
	this->nombreLen = strlen(nom);
	for (int i = 0; i < strlen(nom); i++) {
		nombre[i] = nom[i]; 
	}

	//Se almacenan las etiquetas
	this->etiquetas = new GLubyte[strlen(eti)];
	this->etiquetasLen = strlen(eti);
	for (int i = 0; i < strlen(eti); i++) {
		etiquetas[i] = eti[i];
	}

	//Se almacenan los datos
	this->datos = new GLfloat[cant];
	this->datosLen = cant;
	for (int i = 0; i < cant; i++) {
		datos[i] = dat[i];
	}

	//Se establece el delimitador de etiquetas en 3 caracteres
	this->delimitador = 3;
}

//Constructor de copia privado
Grafico2D::Grafico2D(const Grafico2D& gra) {}

//Destructor
Grafico2D::~Grafico2D() {
	delete nombre;
	delete etiquetas;
	delete datos;
}

//Establece el deliminator de etiquetas en un nuevo valor
void Grafico2D::setDelimitador(unsigned int d) {
	this->delimitador = d;
}

/****************************************************
 *      Especialización del método dibujar          *
 *  Comienza por dibujar los títulos y etiquetas    *
 *  con funciones del manejador de ventanas GLUT de *
 *  OpenGL. Luego dibuja los datos en pantalla con  *
 *  una línea de la clase Linea2D. Los datos, por   *
 *  estándar de esta biblioteca se representan de   *
 *	0-450 pixeles en el eje Y positivo, de 0-(-150) *
 *  pixeles en el eje Y negativo, de 0-325 pixeles  *
 *  en el eje X positivo y de 0-(-325) pixeles en   *
 *  el eje X negativo. La altura de una linea es    *
 *  una representación del valor contenido en el    *
 *  arreglo. Además se dibuja un círculo de la      *
 *  clase Circulo2D para identificar en que punto   *
 *  de la gráfica está representado un valor.       *
 ****************************************************/
void Grafico2D::dibujar() {
	//Establece el color en Negro
	glColor3f(0.0, 0.0, 0.0);
	//Se mueve hasta la posicion especificada para 
	//imprimir el título
	glRasterPos2i(-40, 400);

	//Imprime el título caracter por caracter con una 
	//letra Helvetica de 18 puntos
	for (GLuint i = 0; i < nombreLen; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, nombre[i]);
	}

	//Modifica xRaster para comenzar a imprimir las etiquetas
	//desde la parte izquierda de la pantalla
	GLint xRaster = -270;

	//Imprime las etiquetas caracter por caracter
	//sumando 50 pixeles cuando se llega al delimitador
	//de caracteres, eso asegura de que las etiquetas se
	//mantengan separadas
	for (GLuint i = 0; i < etiquetasLen; i++) {
		if (i % delimitador == 0) {
			glRasterPos2i(xRaster, 0);
			xRaster += 50;
		}

		//Imprime las etiquetas con letra Helvetica de 12 puntos
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, etiquetas[i]);
	}

	//Modifica el valor de xRaster para comenzar a imprimir 
	//las líneas de la gráfica
	xRaster = -260;

	//Recorre el arreglo hasta hacer una linea por cada dato - 1
	//dentro del arreglo de datos
	for (GLuint i = 0; i < datosLen - 1; i++) {
		//Inicializa un punto en el dato en cuestión
		Punto2D Ptmp1(xRaster, datos[i]);
		//Inicializa otro punto en el dato siguiente
		Punto2D Ptmp2(xRaster + 50, datos[i + 1]);
		//Crea una línea a partir de los dos puntos
		//anteriores
		Linea2D Ltmp(Ptmp1, Ptmp2);
		//modifica el color de la línea a un derivado del 
		//Azul
		glColor3f(0.0, 0.3, 1.0);
		//dibuja la linea
		Ltmp.dibujar();
		//Cambia el color a un derivado del rojo (un tono de
		//anaranjado)
		glColor3f(1.0, 0.3, 0.0);
		//Crea un circulo en el punto que representa el dato
		//en cuestion, con un radio de 4 pixeles
		Circulo2D Ctmp(Ptmp1, 4);
		//Dibuja el círculo
		Ctmp.dibujar();

		//Verifica que si es el último circulo a dibujar
		//lo dibuja cuando llega al último dato al que ingresa
		//el ciclo de lo contrario no podrá ser representado
		if (i == datosLen - 2) {
			Circulo2D Ctmp2(Ptmp2, 4);
			Ctmp2.dibujar();
		}

		//Si ya fue representado todo en orden, suma 50 pixeles
		//a la coordenada del xRaster para representar otro punto
		//con 50 pixeles de separación del anterior
		xRaster += 50;
	}
}