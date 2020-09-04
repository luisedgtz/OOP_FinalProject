//Programa realizado por Luis Eduardo Gutierez Saenz Pardo A01283825
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Episodio.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Video.h"

void cargarArchivos(vector<Video*> &videos) {
	//Se limpia la consola
	system("CLS");

	fstream archivoPeliculas;
	fstream archivoSeries;
	fstream archivoEpisodios;

	string idP, durP, rateP, nameP, genP;
	string idS, nameS, genS, tempS;
	string idSE, idE, nameE, durE, rateE, temp;

	int i = 0;

	//Se leen los archivo

	//Lectura del archivo Peliculas
	try {
		archivoPeliculas.open("ProyectoIntegrador-Peliculas.csv", ios::in);
		cout << "\nPeliculas cargadas" << endl;
	}
	catch (const std::exception&) {
		cout << "\nError al cargar las peliculas" << endl;
	}

	while (archivoPeliculas.good()) {
		getline(archivoPeliculas, idP, ',');
		getline(archivoPeliculas, nameP, ',');
		getline(archivoPeliculas, durP, ',');
		getline(archivoPeliculas, genP, ',');
		getline(archivoPeliculas, rateP, '\n');
		if (i > 0) {
			try {
				double rateM = stod(rateP);
				int iDP = stoi(idP);
				//Se insertan los objetos Pelicula en el vector
				videos.push_back(new Pelicula(nameP, genP, rateM, iDP, durP));
			}
			catch (const std::exception&) {

			}
		}
		i++;
	}
	archivoPeliculas.close();

	//Lectura del archivo Series
	i = 0;
	try {
		archivoSeries.open("ProyectoIntegrador-Series.csv", ios::in);
		cout << "\nSeries cargadas" << endl;
	}
	catch (const std::exception&) {
		cout << "\nError al cargar las Series" << endl;
	}
	while (archivoSeries.good()) {
		getline(archivoSeries, idS, ',');
		getline(archivoSeries, nameS, ',');
		getline(archivoSeries, genS, ',');
		getline(archivoSeries, tempS, '\n');
		if (i != 0) {
			try {
				int iDS = stoi(idS);
				int tempos = stoi(tempS);
				//Se insertan los objetos Serie en el vector
				videos.push_back(new Serie(nameS, genS, iDS, tempos));
			}
			catch (const std::exception&) {

			}
		}
		i++;
	}
	archivoSeries.close();

	//Lectura del archivo Episodios
	i = 0;
	try {
		archivoEpisodios.open("ProyectoIntegrador-Episodios.csv", ios::in);
		cout << "\nEpisodios cargados" << endl;
	}
	catch (const std::exception&) {
		cout << "\nError al cargar los episodios" << endl;
	}
	while (archivoEpisodios.good()) {
		getline(archivoEpisodios, idSE, ',');
		getline(archivoEpisodios, idE, ',');
		getline(archivoEpisodios, nameE, ',');
		getline(archivoEpisodios, durE, ',');
		getline(archivoEpisodios, rateE, ',');
		getline(archivoEpisodios, temp, '\n');
		if (i != 0) {
			try {
				double califE = stod(rateE);
				int tempE = stoi(temp);
				int iDE = stoi(idE);
				int iDSE = stoi(idSE);

				Episodio episodio = Episodio(nameE, iDE, tempE, durE, califE);

				//Se agregan los objetos Episodio al vector de episodios del objeto Serie especifico
				for (int j = 0; j < videos.size(); j++) {
					if (videos[j]->getId() == iDSE) {
						videos[j]->operator+(Episodio(episodio));
					}
				}
			}
			catch (const std::exception&) {

			}
		}
		i++;
	}
	archivoEpisodios.close();
}

void mostrarConRango(vector<Video*>& videos) {
	system("CLS");
	int selecGen;
	double rango1,rango2;
	int counter = 0;
	string genre;
	bool condicion = false;

	cout << "\nDigite un minimo de calificacion: ";
	//Se valida la entrada del usuario
	while (!(cin >> rango1)) {
		cout << "Porfavor digite un numero: ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	cout << "\nDigite un maximo de calificacion: ";
	while (!(cin >> rango2)) {
		cout << "Porfavor digite un numero: ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	cout << "\nSeleccione un genero" << endl;
	cout << "1)DRAMA 2)ACCION 3)MISTERIO: ";
	while (!(cin >> selecGen)) {
		cout << "Porfavor digite un numero: ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	if (selecGen == 1) {
		genre = "Drama";
		condicion = true;
	}
	else if (selecGen == 2) {
		genre = "Accion";
		condicion = true;
	}
	else if (selecGen == 3) {
		genre = "Misterio";
		condicion = true;
	}
	else {
		cout << "\nTu seleccion no es valida, vuelve a intentarlo" << endl;
		genre = "";
	}

	if (condicion) {
		for (int i = 0; i < videos.size(); i++) {
			if (videos[i]->getGenero() == genre) {
				if (videos[i]->getNumeroEp() == 1) {
					//Se imprimen las peliculas
					videos[i]->showRango(rango1,rango2);
				}
				else {
					//Se imprimen los episodios de la serie en el rango
					videos[i]->showRango(rango1,rango2);
				}
			}
		}
	}
	
}

void mostrarPorGenero(vector<Video*>& videos) {
	system("CLS");
	int selecGen;
	bool condicion = false;
	string genre;

	cout << "\nSeleccione un genero" << endl;
	cout << "1)DRAMA 2)ACCION 3)MISTERIO: ";
	while (!(cin >> selecGen)) {
		cout << "Porfavor digite un numero: ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	if (selecGen == 1) {
		genre = "Drama";
		condicion = true;
	}
	else if (selecGen == 2) {
		genre = "Accion";
		condicion = true;
	}
	else if (selecGen == 3) {
		genre = "Misterio";
		condicion = true;
	}
	else {
		cout << "\nTu seleccion no es valida, vuelve a intentarlo" << endl;
		genre = "";
	}

	if (condicion) {
		for (int i = 0; i < videos.size(); i++) {
			if (videos[i]->getGenero() == genre) {
				//Se muestran los videos por genero
				videos[i]->show();
			}
		}
	}

}

void mostrarEpisodiosRate(vector<Video*>& videos) {
	system("CLS");
	int serieElec;
	double rango1, rango2;

	//Se imprimen todas las series
	for (int i = 0; i < videos.size(); i++) {
		if (videos[i]->getNumeroEp() > 1) {
			cout << "[" << i << "]";
			videos[i]->show();
		}
	}

	cout << "\nSeleccione una opcion digitando el numero entre []: ";

	while (!(cin >> serieElec)) {
		cout << "Porfavor digite un numero: ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	cout << "\Digite una calificacion minima: ";
	while (!(cin >> rango1)) {
		cout << "Porfavor digite un numero: ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	cout << "\Digite una calificacion maxima: ";
	while (!(cin >> rango2)) {
		cout << "Porfavor digite un numero: ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	//Se valida el indice de la serie
	if (serieElec >= 0 && serieElec <= videos.size() - 1) {
		if (videos[serieElec]->getNumeroEp() == 1) {
			cout << "\nEsta no es una serie, vuelva a intentarlo" << endl;
		}
		else {
			//Se imprimen los Episodios en el rango
			videos[serieElec]->showRango(rango1, rango2);
		}
	}
	else {
		cout << "\nEsa opcion no es valida" << endl;
	}
}

void mostrarPeliculasRate(vector<Video*>& videos) {
	system("CLS");

	double rango1, rango2;

	cout << "\Digite una calificacion minima: ";
	while (!(cin >> rango1)) {
		cout << "Porfavor digite un numero: ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	cout << "\Digite una calificacion maxima: ";
	while (!(cin >> rango2)) {
		cout << "Porfavor digite un numero: ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	//Se muestran la peliculas en el rango indicado
	for (int i = 0; i < videos.size(); i++) {
		if (videos[i]->getNumeroEp() == 1) {
			videos[i]->showRango(rango1, rango2);
		}
	}
}

void calificarVideo(vector<Video*>& videos) {
	system("CLS");
	int videoSelec, episodioSelec;
	double rate;

	//Se imprimen las peliculas y series
	for (int i = 0; i < videos.size(); i++) {
		cout << "[" << i << "]";
		videos[i]->show();
	}

	cout << "\nEscoge una opcion para calificar: ";
	while (!(cin >> videoSelec)) {
		cout << "Porfavor digite un numero: ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	//Se valida el indice escogido
	if (videoSelec >= 0 && videoSelec <= videos.size() - 1) {
		//Se valida si es una pelicula o serie
		if (videos[videoSelec]->getNumeroEp() == 1) {
			cout << "\nDigita una calificacion: ";
			while (!(cin >> rate)) {
				cout << "Porfavor digite un numero: ";
				cin.clear();
				cin.ignore(100, '\n');
			}
			//Se cambia la calificacion de la pelicula
			videos[videoSelec]->setCalificacion(rate, 0);
		}
		else {
			//Se imprimen todos los capitulos de la serie
			videos[videoSelec]->showRango(-100, 100);
			cout << "\nEscoge un episodio";
			while (!(cin >> episodioSelec)) {
				cout << "Porfavor digite un numero: ";
				cin.clear();
				cin.ignore(100, '\n');
			}

			cout << "\nDigita una calificacion: ";
			while (!(cin >> rate)) {
				cout << "Porfavor digite un numero: ";
				cin.clear();
				cin.ignore(100, '\n');
			}
			//Se cambia la calificacion del episodio de la serie
			videos[videoSelec]->setCalificacion(rate, episodioSelec);
		}
	}
	else {
		cout << "\nEsa opcion no es valida" << endl;
	}
}

int main() {

	//Vector de todos los videos
	vector<Video*> videos;

	bool condicion = true;
	int opcion;

	//Menu
	while (condicion) {
		cout << "\n------------MENU-------------" << endl;
		cout << "1) Cargar archivos de datos" << endl;
		cout << "2) Mostrar videos con rango de calificacion y genero" << endl;
		cout << "3) Mostrar videos de genero especifico" << endl;
		cout << "4) Mostrar episodios de serie con rango de calificacion" << endl;
		cout << "5) Mostrar peliculas con rango de calificacion" << endl;
		cout << "6) Calificar un video" << endl;
		cout << "0) Salir " << endl;

		cout << "Opcion: ";
		//Validacion de la entrada
		while (!(cin >> opcion)) {
			cout << "Porfavor digite un numero: ";
			cin.clear();
			cin.ignore(100, '\n');
		}

		switch (opcion)
		{
		case 1:
			//Validacion de la doble carga de archivo
			if (videos.empty()) {
				cargarArchivos(videos);
			}
			else {
				cout << "\nYa cargaste los archivos" << endl;
			}
			break;

		case 2:
			//Validacion del vector vacio
			if (videos.empty()) {
				cout << "\nPrimero tiene que cargar los videos" << endl;
			}
			else {
				mostrarConRango(videos);
			}
			break;
		case 3:
			if (videos.empty()) {
				cout << "\nPrimero tiene que cargar los videos" << endl;
			}
			else {
				mostrarPorGenero(videos);
			}
			break;
		case 4:
			if (videos.empty()) {
				cout << "\nPrimero tiene que cargar los videos" << endl;
			}
			else {
				mostrarEpisodiosRate(videos);
			}
			break;
		case 5:
			if (videos.empty()) {
				cout << "\nPrimero tiene que cargar los videos" << endl;
			}
			else {
				mostrarPeliculasRate(videos);
			}
			break;
		case 6:
			if (videos.empty()) {
				cout << "\nPrimero tiene que cargar los videos" << endl;
			}
			else {
				calificarVideo(videos);
			}
			break;
		case 0:
			system("CLS");
			cout << "\nGracias por su preferencia" << endl;
			condicion = false;
			break;
		default:
			cout << "\nSeleccione una opcion valida" << endl;
			break;
		}
	}
	return 0;
}