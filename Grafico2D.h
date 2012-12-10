#ifndef GRAFICO2D_H
#define GRAFICO2D_H
//Clase padre Figura2D
#include "Figura2D.h"
//Clase Punto2D necesaria solo para representar puntos
//no se utilizaran su método de dibujo
#include "Punto2D.h"
//Clase Linea2D necesaria para poder mostrar la línea
//continua del gráfico de línea
#include "Linea2D.h"
//Clase Circulo2D necesaria para mostrar un punto 
//dentro del plano cartesiano que representa un
//dato.
#include "Circulo2D.h"
//Librería del manejador de ventanas GLUT de OpenGL
#include <GL/glut.h>
//Librería cstring utilizada para el manejo de cadenas
//tipo C. La librería GLUT no aceptra string para
//dibujar caracteres en pantalla
#include <cstring>
using namespace std;

/**************************************************
 *              Clase Hija Grafico2D              *
 *  Posee como atributos dos apuntadores del      *
 *  tipo GLubyte*: nombre, etiquetas; sirven para *
 *  almacenar los caracteres correspondientes al  *
 *  nombre y las etiquetas que se imprimirán en   *
 *  pantalla. Como la especificiación de          *
 *  impresión depende de GLUT, no podemos         *
 *  imprimir char solamente sus representaciones  *
 *  enteras correspondientes en la Tabla ASCII.   *
 *  Otro atributo es un apuntador tipo GLfloat*   *
 *  que almacena un arreglo de de floats que      *
 *  contiene los datos que se representarán en    *
 *  la gráfica. Además, es necesario almacenar    *
 *  los tamaños de cada uno de los arreglos que   *
 *  almacenan en éstos apuntadores. Por ultimo,   *
 *  hay un valor delimitador que representa la    *
 *  cantidad de caracteres a la cual se imprimime *
 *  una nueva etiqueta dentro del gráfico, por    *
 *  defecto es cada 3 caracteres.                 *
 **************************************************/
class Grafico2D : public Figura2D {
	//Apuntador que guarda un arreglo de bytes (caracteres)
	//con el nombre del gráfico;
	GLubyte* nombre;
	//Tamaño del arreglo con el nombre
	GLuint nombreLen;
	//Apuntador que guarda un arreglo de bytes (catacteres)
	//con las etiquetas. Estas están juntas, sin espacios
	GLubyte* etiquetas;
	//Tamaño del arreglo que contiene las etiquetas
	GLuint etiquetasLen;
	//Apuntador que almacena un arreglo de floats con los 
	//datos a imprimir en pantalla
	GLfloat* datos;
	//Tamaño del arreglo que contiene los datos
	GLuint datosLen;
	//Deliminator, con el se calcula cada cuantos caracteres
	//se cambiar de etiqueta
	unsigned int delimitador;
	//Constructor de copia privado, impide las copias de esta clase
	Grafico2D(const Grafico2D&);
public:
	//Constructor que recibe un const char* con el nombre
	//otro const char* con las etiquetas juntas y sin espacios
	//un const float[] que contiene una tupla de datos a graficar
	//y un unsigned int con la cantidad de datos que contiene la tupla
	Grafico2D(const char*, const char*, const float[] , unsigned int);
	//Destrutor
	~Grafico2D();
	//Setea el delimitador para que el cambio entre etiquetas sea 
	//de menos o más caracteres
	void setDelimitador(unsigned int);
	//Método dibujar de la case padre Figura2D
	void dibujar();
};

#endif