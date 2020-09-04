//Programa realizado por Luis Eduardo Gutierez Saenz Pardo A01283825

#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "Video.h"
#include "Episodio.h"

class Pelicula : public Video {
private:
	string duracion;
	double calificacion;

public:
	Pelicula() {
		duracion = "0";
		calificacion = 0;
	}

	Pelicula(string name, string genre, double rate, int i, string duration) {
		nombre = name;
		genero = genre;
		calificacion = rate;
		id = i;
		duracion = duration;
	}

	void setCalificacion(double rate, int i) {
		calificacion = rate;
	}

	double getCalificacion(int i) {
		return calificacion;
	}

	string getGenero() {
		return genero;
	}

	int getNumeroEp() {
		return 1;
	}

	int getId() {
		return id;
	}

	void show() {
		cout << "\nNombre de Pelicula: " << nombre << "  Genero: " << genero << endl;
		cout << "Duracion: " << duracion << " Calificacion: " << calificacion << endl;
	}

	void showRango(double rango1, double rango2) {
		if (calificacion >= rango1 && calificacion <= rango2) {
			cout << "\nNombre de Pelicula: " << nombre << "  Genero: " << genero << endl;
			cout << "Duracion: " << duracion << " Calificacion: " << calificacion << endl;
		}
	}
};