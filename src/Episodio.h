//Programa realizado por Luis Eduardo Gutierez Saenz Pardo A01283825

#pragma once
#include <iostream>
#include <string>
using namespace std;


class Episodio {
private:
	string nombre;
	int id;
	int temporada;
	string duracion;
	double calificacion;

public:
	Episodio() {
		nombre = "";
		id = 0;
		temporada = 0;
		duracion = "0";
		calificacion = 0;
	}

	Episodio(string name, int i, int season, string duration, double rate) {
		nombre = name;
		id = i;
		temporada = season;
		duracion = duration;
		calificacion = rate;
	}

	void setCalificacion(double rate) {
		calificacion = rate;
	}

	double getCalificacion() {
		return calificacion;
	}

	void showEpisodio() {
		cout << "       Nombre de Episodio: " << nombre << "  Temporada: " << temporada << endl;
		cout << "       Duracion: " << duracion << " Calificacion: " << calificacion << endl;
	}
};
