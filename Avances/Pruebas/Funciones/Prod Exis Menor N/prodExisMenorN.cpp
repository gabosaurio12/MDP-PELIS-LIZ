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

void menorAmayor(producto arreglo[], int cont){
	int i;
	i = 1;
	while(i < cont){
		producto aux;
		aux = arreglo[i];
		int j;
		j = i - 1;
		while(j > -1){
			if(aux.cantidad < arreglo[j].cantidad){
				arreglo[j+1] = arreglo[j];
			}
			j--;
		}
		arreglo[j+1] = aux;
		i++;
	}
}

void mayorAmenor(producto arreglo[], int cont){
	for(int i = 1; i < cont; i++){
		int band,j;
		producto aux;
		aux = arreglo[i];
		band = 0;
		j = i - 1;

		while(not band && j > -1){
			if(arreglo[i].cantidad < aux.cantidad){
				arreglo[j+1] = arreglo[j];
			}
			else{
				band = 1;
			}
		}
		arreglo[j+1] = aux;
	}
	
}


void prodExisMenorN(producto arrPelis[], int n, int max){
	producto arrMenores[49];
	int i, cont;
	char orden;
	i = 0;
	cont = 0;
	while(arrPelis[i].clave != "" && i < n){
		if(arrPelis[i].cantidad < max){
			arrMenores[cont] = arrPelis[i];
			cont++;
		}
		i++;
	}
	cout << "Quieres ordenarlos en orden: \n";
	cout << "1: Ascendente \t2:Descendente \t3:Por Clave\n";
	cin >> orden;

	switch(orden){
		case '1':
			cout << "Ascendente \n";
			menorAmayor(arrMenores,cont);
			for(i = 0; i < cont; i++){
				cout << arrMenores[i].clave << " ... " << arrMenores[i].nombre << " ... " << arrMenores[i].cantidad << "\n";
			}
			break;

		case '2':
			cout << "Descendente \n";
			mayorAmenor(arrMenores,cont);
			for(i = 0; i < cont; i++){
				cout << arrMenores[i].clave << " ... " << arrMenores[i].nombre << " ... " << arrMenores[i].cantidad << "\n";
			}
			break;

		default:
			cout << "Por Clave \n";
			for(i = 0; i < cont; i++){
				cout << arrMenores[i].clave << " ... " << arrMenores[i].nombre << " ... " << arrMenores[i].cantidad << "\n";
			}
			break;
	}
}

int main(){
	producto peliculas[49];
	char opcion;
	int n, max;
	n = 50;

	//pruebas
	peliculas[0].clave = "UN001";
	peliculas[0].nombre = "Peli 1"; 
	peliculas[0].cantidad = 5;
	peliculas[1].clave = "UN002";
	peliculas[1].nombre = "Peli 2";
	peliculas[1].cantidad = 2;
	peliculas[2].clave = "UN003";
	peliculas[2].nombre = "Peli 3";
	peliculas[2].cantidad = 7;
	peliculas[3].clave = "UN004";
	peliculas[3].nombre = "Peli 4";
	peliculas[3].cantidad = 10;

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
				cout << "Ingresa la cantidad maxima que quieres que tengan los productos \n";
				cin >> max;
				prodExisMenorN(peliculas,n,max);
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