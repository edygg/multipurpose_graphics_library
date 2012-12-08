all : test
	rm Punto2D.o Circulo2D.o Linea2D.o prueba.o

test : Punto2D.o Linea2D.o prueba.o
	g++ -lGL -lGLU -lglut Punto2D.o Circulo2D.o Linea2D.o prueba.o -o test

prueba.o : Punto2D.o Linea2D.o Circulo2D.o
	g++ -c -lGL -lGLU -lglut prueba.cpp

Linea2D.o : Punto2D.o
	g++ -c -lGL Linea2D.cpp

Circulo2D.o : Punto2D.o
	g++ -c -lGL Circulo2D.cpp

Punto2D.o : 
	g++ -c -lGL Punto2D.cpp
