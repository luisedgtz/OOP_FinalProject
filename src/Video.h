//Programa realizado por Luis Eduardo Gutierez Saenz Pardo A01283825

#pragma once
#include <iostream>
#include <string>

#include "Episodio.h"
using namespace std;

//Clase Abstracta. Padre de Pelicula y Serie
//Establece metodos virtuales para el uso de polimorfismo

class Video {
protected:
	string nombre;
	string genero;
	int id;

public:
	Video() {
		nombre = "";
		genero = "";
		id = 0;
	}

	Video(string name, string genre, int i) {
		nombre = name;
		genero = genre;
		id = i;
	}

	virtual void operator+(Episodio episode) {}

	virtual void setCalificacion(double rate, int i) {}
	
	virtual double getCalificacion(int i) {
		return 0;
	}

	virtual string getGenero() {
		return "";
	}

	virtual int getNumeroEp() {
		return 1;
	}

	virtual int getId() {
		return id;
	}

	virtual void showRango(double rango1,double rango2) {}

	virtual void show(){}
};