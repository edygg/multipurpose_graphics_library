#include "Punto2D.h"
#include "Linea2D.h"
#include "Circulo2D.h"
#include "Poligono2D.h"
#include "Grafico2D.h"

#include <GL/gl.h>
#include <GL/glut.h>

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void init(const char*, const char*, float[], unsigned int);
void winReshapeFcn(int, int);
void genDibujo(void);
int menuPrincipal();

const int INICIO_MENU = 1;
const int FINAL_MENU = 3;

const int CREAR_GRAFICO = 1;
const int EXPORTAR_DATOS = 2;
Grafico2D* grafico;
GLuint reg;


int main(int argc, char* argv[]) {
	int opcion;
	grafico = NULL;
	string nombre;
	string etiquetas;
	vector<float> datos;
	bool ingresado = false;

	do {
		nombre = "";
		etiquetas "";
		datos.clean();
		
		opcion = menuPrincipal();

		switch(opcion) {
			case CREAR_GRAFICO:
			{
				char op_sub;

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
					case 'a':
					{
						getline(cin, nombre);

						cout << "Ingrese el nombre del gráfico: ";
						getline(cin, nombre);
						cout << "Ingrese las etiquetas juntas y sin espacios" << endl;
						cout << "Se separan cada 3 caracteres" << endl;
						cout << "Ingrese las etiquetas: ";
						getline(cin, etiquetas);

						char continuar;

						do {
							float tmp;
							cout << "Ingrese un dato: ";
							cin >> tmp;
							datos.push_back(tmp);

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

					case 'b':
					{
						if (ingresado) {
							float data[datos.size()];

							for (int i = 0; i < datos.size(); i++) {
								data[i] = datos[i];
							}

							const int width = 670, height = 600;
							glutInit(&argc, argv);
							glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
							glutInitWindowPosition(50, 100);
							glutInitWindowSize(width, height);
							glutCreateWindow(nombre.c_str());
							init(nombre.c_str(), etiquetas.c_str(), data, datos.size());
							glutDisplayFunc(genDibujo);
							glutReshapeFunc(winReshapeFcn);
							glutMainLoop();
						} else {
							cerr << "No hay datos que mostrar" << endl;
						}
					}
					break;
				}
			}
			break;

			case EXPORTAR_DATOS:
			{
				if (ingresado) {
					ofstream archivo("chart.csv", ios::out);

					if(!archivo) {
						cerr << "No se pudo abrir archivo" << endl;
						break;
					}

					string tmp;

					for (int i = 0; i < etiquetas.size(); i += 3) {
						tmp = etiquetas.substr(i, 3);
						if (i == etiquetas.size() - 1)
							archivo << tmp.c_str();
						else
							archivo << tmp.c_str() << ",";
					}
					archivo << "\n";

					for (int i = 0; i < datos.size(); i++) {
						if (i == datos.size() - 1)
							archivo << datos[i];
						else
							archivo << datos[i] << ",";
					}
					archivo << "\n";

					cout << "Archivo creado con éxito!" << endl;

				} else {
					cerr << "No hay datos que exportar" << endl;
				}
			}
			break;
		}

	} while (opcion != FINAL_MENU);
	if (!grafico)
		delete grafico;

	return 0;	
}

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

void init(const char* nombre, const char* etiquetas, float datos[], unsigned int cant) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	reg = glGenLists(1);
	
	glNewList(reg, GL_COMPILE);
		grafico = new Grafico2D(nombre, etiquetas, datos, cant);
		grafico->dibujar();
	glEndList();
}

void winReshapeFcn(int newWidth, int newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-1 * (newWidth / 2), newWidth / 2, -1 * (newHeight / 4), 3 * newHeight / 4);
}

void genDibujo(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glCallList(reg);
	glFlush();	
}