//Programa realizado por Luis Eduardo Gutierez Saenz Pardo A01283825

#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Video.h"
#include "Episodio.h"

class Serie: public Video {
private:
	int temporadas;
	vector<Episodio> episodios;

public:
	Serie() {
		temporadas = 0;
	}

	Serie(string name, string genre, int i, int seasons) {
		nombre = name;
		genero = genre;
		id = i;
		temporadas = seasons;
	}

	void operator +(Episodio episode) {
		episodios.push_back(episode);
	}

	void setCalificacion(double rate, int i) {
		episodios[i-1].setCalificacion(rate);
	}

	double getCalificacion(int i) {
		double rate = episodios[i].getCalificacion();
		return rate;
	}

	string getGenero() {
		return genero;
	}

	int getNumeroEp() {
		int num = episodios.size();
		return num;
	}

	int getId() {
		return id;
	}

	void show() {
		cout << "\nNombre de Serie: " << nombre << "  Genero: " << genero << endl;
		cout << "Num temporadas: " << temporadas << endl;
	}

	void showRango(double rango1,double rango2) {
		cout << "\nNombre de Serie: " << nombre << "  Genero: " << genero << endl;
		cout << "    Episodios: " << endl;
		for (int i = 0; i < episodios.size(); i++) {
			if (episodios[i].getCalificacion() >= rango1 && episodios[i].getCalificacion() <= rango2) {
				cout << "      [" << i + 1 << "]" << endl;
				episodios[i].showEpisodio();
			}
		}
	}
};