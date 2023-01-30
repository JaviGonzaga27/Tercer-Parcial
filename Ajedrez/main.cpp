#include <iostream>
#include <fstream>
#include "Alfil.h"
using namespace std;

int main(int argc, char** argv) {
	int n;
	cout<<"\tIngrese el numero de alfiles: "<<endl;
	cin>>n;
	Alfil *obj=new Alfil(n);
	obj->solucionReinas();
	cout<<"Se creo el archivo txt"<<endl;
	return 0;
}