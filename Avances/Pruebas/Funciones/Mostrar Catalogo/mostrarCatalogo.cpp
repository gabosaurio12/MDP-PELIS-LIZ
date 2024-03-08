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

void mostrarCatalogo(producto arrPelis[], int n){
	bool band;
	int i;
	band = true;
	i = 0;
	while(band && i < n){
		if(arrPelis[i].clave == ""){
			band = false;
		}
		else{
			cout << arrPelis[i].clave << " ... " << arrPelis[i].nombre << " ... " << arrPelis[i].precio << " ... " << arrPelis[i].cantidad << "\n";
		}
		i++;
	}
}

int main(){
	producto peliculas[49];
	char opcion;
	int n;
	n = 50;

	//peliculas de prueba
	peliculas[0].clave = "UN001";
	peliculas[0].nombre = "Peli 1"; 
	peliculas[1].clave = "UN002";
	peliculas[1].nombre = "Peli 2";
	peliculas[2].clave = "UN003";
	peliculas[2].nombre = "Peli 3";
	peliculas[3].clave = "UN004";
	peliculas[3].nombre = "Peli 4";


	while(1){
		menuPrincipal();
		cin >> opcion;

		switch(opcion){
			case '1':
				break;

			case '2':
				break;

			case '3':
				mostrarCatalogo(peliculas,n);
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