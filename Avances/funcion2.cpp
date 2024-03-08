#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

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
	cout<<"\n\t\t\t\tInventario de Cine\n\n";
	cout<<"\n\t\t\t\tSelecciona una opcion\t\n";
	cout<<"\n\t\t\t1.Alta del producto\n";
	cout<<"\n\t\t\t2.Modificacion de un producto\n";
	cout<<"\n\t\t\t3.Mostrar Catalogo de productos\n";
	cout<<"\n\t\t\t4.Productos cuya existencia sea menor a N \n";
	cout<<"\n\t\t\t5.Productos que pertenezcan a una distribuidora especifica\n";
	cout<<"\n\t\t\t6.Productos que cuesten mas de un precio N\n";
	cout<<"\n\t\t\t\t\t7.Salir\t\t\t\t\n";
}

int posicionPeli(producto arrPelis[], string clave, int n){
	for(int i = 0; i < n; i++){
		if(arrPelis[i].clave == clave){
			return i;
		}
	}
	return 50;
}

void modificarPeli(producto arrPelis[], int n, int j){
	string clave;
	cout << "Ingresa la clave del producto ";
	cin >> clave;

	int posicion = posicionPeli(arrPelis,clave,n);
	if(posicion == 50){
		while(j < 2){
			cout << "Clave invalida, vuelve a intentarlo \n";
			j++;
			modificarPeli(arrPelis,n,j);
		}
		j = 0;
	}
	else{
		char opcion;
		string nuevaProductora;
		string nuevoNombre;
		int nuevaCantidad;
		float nuevoPrecio;
		string nuevoGenero;
		string nuevoFormato;
		string nuevoDirector;

		cout << "Elige la opcion que deseas modificar \n";
		cout << "1. Productora \n";
		cout << "2. Nombre \n";
		cout << "3. Cantidad \n";
		cout << "4. Precio \n";
		cout << "5. Genero \n";
		cout << "6. Formato \n";
		cout << "7. Director \n";
		cout << "8. Regresar \n";
		cin >> opcion;

		switch(opcion){
			case '1':
				cout << "Ingresa la nueva Productora ";
				cin >> nuevaProductora;
				arrPelis[posicion].productora = nuevaProductora;
				cout << "La productora ha sido actualizada \n";
				cout << arrPelis[posicion].productora;
				break;
			
			case '2':
				cout << "Ingresa el nuevo Nombre ";
				cin >> nuevoNombre;
				arrPelis[posicion].nombre = nuevoNombre;
				cout << "La productora ha sido actualizada \n";
				cout << arrPelis[posicion].nombre;
				break;
			
			case '3':
				cout << "Ingresa la nueva Cantidad en existencia ";
				cin >> nuevaCantidad;
				arrPelis[posicion].cantidad = nuevaCantidad;
				cout << "La Cantidad ha sido actualizada \n";
				cout << arrPelis[posicion].cantidad;
				break;
			
			case '4':
				cout << "Ingresa el Precio nuevo ";
				cin >> nuevoPrecio;
				arrPelis[posicion].precio = nuevoPrecio;
				cout << "El Precio ha sido actualizado \n";
				cout << arrPelis[posicion].precio;
				break;
			
			case '5':
				cout << "Ingresa el Genero nuevo ";
				cin >> nuevoGenero;
				arrPelis[posicion].genero = nuevoGenero;
				cout << "El Genero ha sido actualizado \n";
				cout << arrPelis[posicion].genero;
				break;
			
			case '6':
				cout << "Ingresa el nuevo Formato ";
				cin >> nuevoFormato;
				arrPelis[posicion].formato = nuevoFormato;
				cout << "El Formato ha sido actualizado \n";
				cout << arrPelis[posicion].formato;
				break;

			case '7':
				cout << "Ingresa el Director nuevo ";
				cin >> nuevoDirector;
				arrPelis[posicion].director = nuevoDirector;
				cout << "El Director ha sido actualizado \n";
				cout << arrPelis[posicion].director;
				break;

			case '8':
				menuPrincipal();
				break;

			default:
				cout << "Opcion invalida \n";
				modificarPeli(arrPelis,n,j);
		}
	}
}

int main(){
	producto peliculas[49];
	int n = 50;
	int i=0;
	int j=0;
	char opcion;
	string proveedor;
	float precio;

	while (1){
		menuPrincipal();
		cout << "Ingresa la opcion: ";
		cin >> opcion;
		switch(opcion){

			case '1':
				
				break;

			case '2':
				//funcion para modificar un campo
				modificarPeli(peliculas,n,j);
				break;

			case '3':
				//escribir el arreglo de los productos				

				break;

			case '4':
				
				int max;
				cout << "Ingresa el numero de existencia maximo que deben tener los productos \n";
				cin >> max;
				break;

			case '5':
				cout << "Ingresa la distribuidora que quieres buscar \n";
				cin >> proveedor;

				break;

			case '6':
				cout << "Ingresa el precio minimo que deben tener las peliculas \n";
				cin >> precio;
				break;	

			case '7':
				return 0;	
				break;

			default:
				cout<<"\nLa opcion elegida no es valida";
				break;	
		}		
	}


	return 0;
}

