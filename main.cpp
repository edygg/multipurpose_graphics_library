/****************************************************************************
 *                                                                          *
 *                   Proyecto No. 1	Programación III                        *
 *          Estudiante: Edilson Fernando Gónzález Martínez                  *
 *          Cuenta: 11211070                                                *
 *          Última Modificación: 10/12/2012                                 *
 *                                                                          *
 ****************************************************************************/
 //Clases de la librería MGL
#include "Punto2D.h"
#include "Linea2D.h"
#include "Circulo2D.h"
#include "Poligono2D.h"
#include "Grafico2D.h"

//Librelía GLUT y núcleo de OpenGL
#include <GL/gl.h>
#include <GL/glut.h>

//Librerías de C++ necesarias
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


/****************************************************************************
 *                                                                          *
 *                         Métodos (Declaración)                            *
 *                                                                          *
 ****************************************************************************/
void init(const char*, const char*, float[], unsigned int);
void winReshapeFcn(int, int);
void genDibujo(void);
int menuPrincipal();


/****************************************************************************
 *                                                                          *
 *                     Constantes de importancia                            *
 *                                                                          *
 ****************************************************************************/
//Menu
const int INICIO_MENU = 1;
const int FINAL_MENU = 3;
//Opciones del menú
const int CREAR_GRAFICO = 1;
const int EXPORTAR_DATOS = 2;
//Almacena el gráfico
Grafico2D* grafico;
//Registro de la lista de ejecución de las instrucciónes de OpenGL
GLuint reg;


/****************************************************************************
 *                                                                          *
 *                                  Main                                    *
 *                                                                          *
 ****************************************************************************/
int main(int argc, char* argv[]) {
	int opcion; //Opción del menú principal
	grafico = NULL; //Inicializa el apuntador al gráfico en nulo
	string nombre; //Almacena el nombre del gráfico
	string etiquetas; //Almacena las etiquetas del gráfico
	vector<float> datos; //Vector que almacena los datos del gráfico
	bool ingresado = false; //Valida si hay datos ingresados

	do {
		nombre = ""; //Inicializa el nombre con una cadena vacía
		etiquetas = ""; //Inicializa las etiquetas con una cadena vacía
		datos.clear(); //Borra todos los datos que se guarden en el vector
		
		opcion = menuPrincipal(); //Lee una opcion del menú principal

		//Opciones
		switch(opcion) {
			case CREAR_GRAFICO:
			{
				char op_sub; //Opción del menú secundario

				do {
					cout << "\ta. Ingresar datos" << endl
						 << "\tb. Mostrar grafico" << endl
						 << "Ingrese una opcion: ";
					cin >> op_sub;

					cout << endl;

					if (op_sub != 'a' && op_sub != 'b') {
						cerr << "Opción invalida" << endl;
					}

					cout << endl;
				} while (op_sub != 'a' && op_sub != 'b');

				switch(op_sub) {
					case 'a': //Pide los datos para generar un gráfico
					{
						getline(cin, nombre); //Limpia el cin de basura

						//Nombre
						cout << "Ingrese el nombre del gráfico: ";
						getline(cin, nombre);
						//Etiquetas
						cout << "Ingrese las etiquetas juntas y sin espacios" << endl;
						cout << "Se separan cada 3 caracteres" << endl;
						cout << "Ingrese las etiquetas: ";
						getline(cin, etiquetas);
						//Almacena 'S' si el usuario desea continuar guardando datos
						//'N' caso contrario
						char continuar;

						do {
							float tmp; //Almacena temporalmente el float con el dato
							//Pide un dato
							cout << "Ingrese un dato: ";
							cin >> tmp;
							datos.push_back(tmp); //Ingresa el dato en la tupla

							cout << endl;
							do {
								cout << "¿Desea continuar? [S/N]: ";
								cin >> continuar;
							} while (continuar != 'S' && continuar != 's' && continuar != 'N' && continuar != 'n');

						} while (continuar == 'S' || continuar == 's');
						ingresado = true;
						cout << endl;
					}
					break;

					case 'b': //Luego de ingresar los datos, está preparado para mostrarlo
					{
						if (ingresado) {
							float data[datos.size()]; //Crea un arreglo de floats a partir del vector

							for (int i = 0; i < datos.size(); i++) {
								data[i] = datos[i]; //Almacena los valores en el nuevo arreglo
							}

							const int width = 670, height = 600; //Tamaño de la ventana donde se muestra en gráfico
							glutInit(&argc, argv); //Inicializa GLUT
							glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
							glutInitWindowPosition(50, 100); //Establece la pocisión en donde se mostrará la ventana
							glutInitWindowSize(width, height); //Establece el tamaño de la ventana
							glutCreateWindow(nombre.c_str()); //Crea una ventana con el título del gráfico
							init(nombre.c_str(), etiquetas.c_str(), data, datos.size()); //Inicizaliza
							//el gráfico a partir de los datos ingresados por el usuario
							glutDisplayFunc(genDibujo); //Genera el dibujo a partir de la función
							glutReshapeFunc(winReshapeFcn); //Función que redimensiona la ventana
							glutMainLoop(); //Muestra la ventana en pantalla
						} else { //Si no hay datos ingresados, no hay gráfico que mostrar
							cerr << "No hay datos que mostrar" << endl; 
						}
					}
					break;
				}
			}
			break;

			case EXPORTAR_DATOS: //En un archivo .CSV
			{
				if (ingresado) { //Verifica si hay datos ingresados
					ofstream archivo("chart.csv", ios::out); //Inicializa el archivo donde se guardarán los datos

					if(!archivo) { //Si el archivo no pudo crearse saldrá de la opción
						cerr << "No se pudo abrir archivo" << endl;
						break;
					}

					string tmp; //Cadena temporal para almacenar etoquetas

					for (int i = 0; i < etiquetas.size(); i += 3) {
						tmp = etiquetas.substr(i, 3); //Almacena las etiquetas cada 3 caracteres
						if (i == etiquetas.size() - 1) //Si es la última linea no incluye la coma
							archivo << tmp.c_str();
						else
							archivo << tmp.c_str() << ","; //Caso contrario incluye la coma
					}
					archivo << "\n";//salta la linea 

					for (int i = 0; i < datos.size(); i++) { //Comienza a almacenar los datos
						if (i == datos.size() - 1) //Si es el último dato no coloca la coma
							archivo << datos[i];
						else
							archivo << datos[i] << ","; //Caso contrario la coloca
					}
					archivo << "\n";//salta la linea

					cout << "Archivo creado con éxito!" << endl; //El archivo se creó con éxito

				} else { //Si no hay datos ingresados por el usuario no hay nada que exportar
					cerr << "No hay datos que exportar" << endl;
				}
			}
			break;
		}

	} while (opcion != FINAL_MENU);
	if (!grafico)
		delete grafico; 

	return EXIT_SUCCESS;	
}


/****************************************************************************
 *                                                                          *
 *                           Métodos (Definición)                           *
 *                                                                          *
 ****************************************************************************/
int menuPrincipal() {
	int op;

	do {
		cout << endl;

		cout << "\t1. Crear gráfico" << endl
			 << "\t2. Exportar datos" << endl
			 << "\t3. Salir" << endl
			 << "Ingrese una opción: ";
		cin >> op;
		cout << endl;

		if (op < INICIO_MENU || op > FINAL_MENU) {
			cerr << "Opción invalida" << endl;
		}

		cout << endl;
	} while (op < INICIO_MENU || op > FINAL_MENU);

	return op;
}

//Inicializa la ventana en modo OpenGL
void init(const char* nombre, const char* etiquetas, float datos[], unsigned int cant) {
	glClearColor(1.0, 1.0, 1.0, 0.0); //Establece el color de fondo en blanco
	reg = glGenLists(1); //Genera una lista de ejecución de instrucciones de OpenGL
	
	glNewList(reg, GL_COMPILE); //Establece las instrucciones dentro de la lista
		grafico = new Grafico2D(nombre, etiquetas, datos, cant); //Crea un gráfico
		grafico->dibujar(); //dibuja el gráfico
	glEndList();
}

//Función que controla el redimensionamiento de la ventana
void winReshapeFcn(int newWidth, int newHeight) {
	glViewport(0, 0, newWidth, newHeight); //Establece el punto de vista de manera frontal
	//Recuerde que OpenGL trara la 2D como caso de la 3D
	//Inicializa la nueva matriz de pixeles
	glMatrixMode(GL_PROJECTION);
	//Elimina el contenido de la ventana
	glLoadIdentity();
	//Limpia el buffer de la imagen
	glClear(GL_COLOR_BUFFER_BIT);
	//Establece el nuevo eje coordenado
	//El eje de las X se reparte la mitad de la ventana para la parte positiva
	//y la otra mitad para la parte negativa. El eje Y se reparte 3/4 de la ventana
	//para la parte positiva y 1/4 para la parte negativa
	gluOrtho2D(-1 * (newWidth / 2), newWidth / 2, -1 * (newHeight / 4), 3 * newHeight / 4);
}

//Función que genera el dibujo en la pantalla
void genDibujo(void) {
	glClear(GL_COLOR_BUFFER_BIT); //Limpia el buffer de la imagen
	glCallList(reg); //Llama a la lista de instrucciones de OpenGL
	glFlush(); //Fuerza al sistema a dibujar 
}