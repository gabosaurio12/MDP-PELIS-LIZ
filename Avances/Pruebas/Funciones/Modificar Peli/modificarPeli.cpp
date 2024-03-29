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

int posicionPeli(producto arrPelis[], string clave, int n){
	for (int i = 0; i < n; i++){
		if(arrPelis[i].clave == clave){
			return i;
		}
	}
	return 50;
}

void modificarPeli(producto arrPelis[],int n){
	string clave;
	int posicion, r;
	cout << "Ingresa la clave del producto: ";
	cin >> clave;
	posicion = posicionPeli(arrPelis,clave,n);
	
	if(posicion = 50){
		cout << "Clave invalida \n";
	}
	else{
		char opcion;
		int nuevaCantidad;
		float nuevoPrecio;
		string nuevaProductora, nuevoNombre, nuevoGenero, nuevoFormato, nuevoDirector;

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
				cout << "Ingresa la nueva Productora: ";
				cin >> nuevaProductora;
				arrPelis[posicion].productora = nuevaProductora;
				cout << "La Productora ha sido =actualizada \n";
				break;

			case '2':
				cout << "Ingresa el nuevo Nombre: ";
				cin >> nuevoNombre;
				arrPelis[posicion].nombre = nuevoNombre;
				cout << "El nombre ha sido actualizado \n";
				break;

			case '3':
				cout << "Ingresa la nueva Cantidad en existencia: ";
				cin >> nuevaCantidad;
				arrPelis[posicion].cantidad = nuevaCantidad;
				cout << "La Cantidad ha sido actualizada \n";
				break;

			case '4':
				cout << "Ingresa el Precio nuevo: ";
				cin >> nuevoPrecio;
				arrPelis[posicion].precio = nuevoPrecio;
				cout << "El Precio ha sido actualizado \n";
				break;

			case '5':
				cout << "Ingresa el Genero nuevo: ";
				cin >> nuevoGenero;
				arrPelis[posicion].genero = nuevoGenero;
				cout << "El Genero ha sido actualizado \n";
				break;

			case '6':
				cout << "Ingresa el nuevo Formato: ";
				cin >> nuevoFormato;
				arrPelis[posicion].formato = nuevoFormato;
				cout << "El Formato ha sido actualizado \n";
				break;

			case '7':
				cout << "Ingresa el Director nuevo: ";
				cin >> nuevoDirector;
				arrPelis[posicion].director = nuevoDirector;
				cout << "El Director ha sido actualizado \n";
				break;

			case '8':
				menuPrincipal();
				break;

			default:
				cout << "Opcion invalida \n";
				modificarPeli(arrPelis,n);
		}
	}
}


int main(){
	producto peliculas[49];
	int n, i, j;
	char opcion;
	n = 50;
	i = 0;

	while(1){
		menuPrincipal();
		cin >> opcion;

		switch(opcion){
			case '1':

				break;

			case '2':
				modificarPeli(peliculas,n);
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