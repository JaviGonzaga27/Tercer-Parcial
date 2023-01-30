#pragma once
#include "Alfil.h"

Alfil::Alfil(int n1) {
	n = n1;
	validar = new bool* [n];
	tablero = new char* [n];
	encerarTablero();
	crearArchivo();
}

//gets
int Alfil::getN() { return n; }
int Alfil::getContador() { return contador; }
bool** Alfil::getValidar() { return validar; }
char** Alfil::getTablero() { return tablero; }
//sets
void Alfil::setN(int n1) { n = n1; }
void Alfil::setContador(int contador1) { contador = contador1; }
void Alfil::setValidar(bool** validar1) { validar = validar1; }
void Alfil::setTablero(char** tablero1) { tablero = tablero1; }


void Alfil::encerarTablero() {
	for (int i = 0; i < 8; i++) {
		validar[i] = new bool[n];
		tablero[i] = new char[n];
		for (int j = 0; j < 8; j++) {
			*(*(validar + i) + j) = false;
			*(*(tablero + i) + j) = '*';
		}
	}
}

void Alfil::crearArchivo() {
	archivo.open("exaustivo.txt", fstream::out);
	archivo << "solucion" << n << "*" << n << endl << endl;
	contador = 0;
}

void Alfil::bloquear(int x, int y) {
	int aux1, aux2;

	aux2 = y; //diagonal
	aux1 = x;
	while (aux1 > 0 && aux2 > 0) {
		aux1--;
		aux2--;
	}
	aux2 = y;
	aux1 = x;
	while (aux1 < n && aux2>0) {
		aux1++;
		aux2--;
	}
	aux1--;
	aux2++;
	while (aux1 >= 0 && aux2 < n) {
		*(*(validar + aux1) + aux2) = true;
		aux1--;
		aux2++;
	}
}

void Alfil::mostrar() {
	contador++;
	archivo << "solucion N " << contador << endl;
	cout << endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			archivo << *(*(tablero + i) + j) << " ";
			cout << *(*(tablero + i) + j) << " ";
		}
		archivo << endl;
		cout << endl;
	}
	archivo << endl;
	cout << endl;
}

void Alfil::quitarRelleno(int x, int y) {
	*(*(tablero + x) + y) = '*';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			*(*(validar + i) + j) = false;
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (*(*(tablero + i) + j) == 'R')
				bloquear(i, j);
		}
	}
}

void Alfil::solucion(int x, int y, int n1) {
	*(*(tablero + x) + y) = 'R';
	bloquear(x, y);
	if (n1 == n) {
		mostrar();
	}
	else {
		for (int i = 0; i < 8; i++) {
			if (*(*(validar + i) + y + 1) == false) {
				solucion(i, y + 1, n1 + 1);
			}
		}
	}
	quitarRelleno(x, y);
}

void Alfil::solucionReinas() {
	for (int i = 0; i < 8; i++) {
		solucion(i, 0, 1);
	}
	archivo.close();
}

