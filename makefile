#Compilador
cc = g++

#Librerías de OpenGL: librería núcleo, librería de utilerías y la librería de manejo de ventanas
libs_OpenGL = -lGL -lGLU -lglut

#Banderas
cflags = -c

#Archivos necesarios a compilar
archivos = Punto2D.o Circulo2D.o Poligono2D.o Linea2D.o prueba.o

#Clases de la Librería MGL
clases = Punto2D.o Circulo2D.o Poligono2D.o Linea2D.o

all : test
	rm $(archivos)

test : $(archivos)
	$(cc) $(libs_OpenGL) $(archivos) -o test

prueba.o : $(clases)
	$(cc) $(cflags) $(libs_OpenGL) prueba.cpp

Poligono2D.o : Punto2D.o
	$(cc) $(cflags) $(libs_OpenGL) Poligono2D.cpp

Linea2D.o : Punto2D.o
	$(cc) $(cflags) $(libs_OpenGL) Linea2D.cpp

Circulo2D.o : Punto2D.o
	$(cc) $(cflags) $(libs_OpenGL) Circulo2D.cpp

Punto2D.o : 
	$(cc) $(cflags) $(libs_OpenGL) Punto2D.cpp
