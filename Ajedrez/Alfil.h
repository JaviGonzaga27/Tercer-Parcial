#pragma once
#include <iostream>
#include <fstream>
#include "Operaciones.h"

using namespace std;

class Alfil: public Operaciones {

public:

	Alfil(int n1);

	//set
	void setN(int n1);
	void setContador(int contador1);
	void setValidar(bool** validar1);
	void setTablero(char** tablero1);

	//get
	int getN();
	int getContador();
	bool** getValidar();
	char** getTablero();

	//operaciones
	void encerarTablero() override;
	void mostrar() override;
	void bloquear(int x, int y) override;
	void quitarRelleno(int x, int y) override;
	void solucionReinas()override;
	void solucion(int x, int y, int n1) override;
	void crearArchivo() override;

private:

	bool** validar;
	char** tablero;
	std::fstream archivo;
	int contador;
	int n;
};