#pragma once
class Operaciones {

public:

    virtual void encerarTablero()=0;
	virtual void mostrar() = 0;
	virtual void bloquear(int x, int y) = 0;
	virtual void quitarRelleno(int x, int y) = 0;
	virtual void solucionReinas() = 0;
	virtual void solucion(int x, int y, int n1) = 0;
	virtual void crearArchivo() = 0;
};