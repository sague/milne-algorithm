#include <iostream>

#define func(x,y) 2*x*y;
#define fdev(x,y) 4*x*y+2*y;



#include "Plot.hpp"
#include "metodos.hpp"


int main(int argc, char const *argv[])
{

	double x, y, h, n;

	cout << "Ingrese las condiciones iniciales: " << endl;

	cout << "\n Ingrese x(0): "  << endl;
	cin >> x;
	cout << "\n Ingrese y(0): "  << endl;
	cin >> y;

	cout << "Ingrese h: "  << endl;
	cin >> h;

	cout << "Ingrese las n Iteraciones: "  << endl;
	cin >> n;

	// Crea una clase que contien todos los metodos con las 
	// condiciones iniciales dadas
	Metodos mis_metodos(x, y, h, n);

	// Muestra las tablas de cada métodos
	mis_metodos.milne();
	mis_metodos.runge_kutta();
	mis_metodos.taylor();

	Plot myPlot;

	myPlot.generate("gnu_salida.gnu");

	cin >> n;
	
	return 0;
}	