#include <iostream>
#include <string>

using namespace std;

struct producto{
	string productora;
	string clave;
	string nombre;
	int cantidad;
	float precio;
	string genero;
	string formato;
	string director;
};

void menuPrincipal(){
	cout << "\n\t\t\t\tInventario de Cine\n\n";
	cout << "\n\t\t\t\tSelecciona una opcion\t\n";
	cout << "\n\t\t\t1.Alta del producto\n";
	cout << "\n\t\t\t2.Modificacion de un producto\n";
	cout << "\n\t\t\t3.Mostrar Catalogo de productos\n";
	cout << "\n\t\t\t4.Productos cuya existencia sea menor a N\n";
	cout << "\n\t\t\t5.Productos que pertenezcan a una distribuidora especifica\n";
	cout << "\n\t\t\t6.Productos que cuesten mas de un precio N\n";
	cout << "\n\t\t\t\t\t7.Salir\t\t\t\t\n\n";
	cout << "Ingresa la opcion: ";
}

int main(){
	producto peliculas[49];
	char opcion;

	while(1){
		menuPrincipal();
		cin >> opcion;

		switch(opcion){
			case '1':
				break;

			case '2':
				break;

			case '3':
				break;

			case '4':
				break;

			case '5':
				break;

			case '6':
				break;

			case '7':
				return 0;
				break;

			default:
				cout << "La opcion elegida no es valida \n";
				break;
		}
	}

	return 0;
}