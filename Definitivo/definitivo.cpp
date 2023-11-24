#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct producto{
	string distribuidora;
	string clave;
	string nombre;
	int cantidad;
	float precio;
	string genero;
	string formato;
	string director;
};

int posicionProd(producto a[], int n, string cl){
	for (int i = 0; i < n; i++){
		if (cl == a[i].clave){
			return i;
		}
	}
	return 50;
}

void modificar(producto a[]){
	// clave de prueba
	a[0].clave = "1234";
	
	string bClave;
	cout << "Ingresa la clave del producto que quieres editar: ";
	cin >> bClave;
	int posicion = posicionProd(a,50,bClave);
	if(posicion == 50){
		cout << "Clave invalida \n";
		modificar(a);
	}

	cout << "1. Distribuidora \n";
	cout << "2. Nombre \n";
	cout << "3. Cantidad \n";
	cout << "4. Precio \n";
	cout << "5. Genero \n";
	cout << "6. Formato \n";
	cout << "7. Director \n";

	int opcion;
	cin >> opcion;
	switch(opcion){
		case 1:
			cout << "Ingresa la nueva Distribuidora: ";
			cin.ignore();
			getline(cin, a[posicion].distribuidora);
			cout << "Distribuidora actualizada \n";
			cout << a[posicion].distribuidora;
			break;
		
		case 2:
			cout << "Ingresa el nuevo nombre: ";
			cin >> a[posicion].nombre;
			cout << "Nombre actualizado \n";
			cout << a[posicion].nombre;
			break;

		case 3:
			cout << "Ingresa la nueva cantidad: ";
			cin >> a[posicion].cantidad;
			cout << "Cantidad actualizada \n";
			cout << a[posicion].cantidad;
			break;

		case 4:
			cout << "Ingresa el nuevo precio: ";
			cin >> a[posicion].precio;
			cout << "Precio actualizado \n";
			cout << a[posicion].precio;
			break;

		case 5:
			cout << "Ingresa el nuevo genero: ";
			cin >> a[posicion].genero;
			cout << "Genero actualizado \n";
			cout << a[posicion].genero;
			break;

		case 6:
			cout << "Ingresa el nuevo formato: ";
			cin >> a[posicion].formato;
			cout << "Formato actualizado \n";
			cout << a[posicion].formato;
			break;

		case 7:
			cout << "Ingresa el nuevo Director: ";
			cin >> a[posicion].director;
			cout << "Director actualizado \n";
			cout << a[posicion].director;
			break;

		default:
			cout << "La opcion elegida no es valida \n";
	}

}

void catalogo(producto a[], int n){
	bool band = true;
	int i = 0;
	// arreglos de prueba, se pueden borrar
	a[0].clave = "1989";
	a[0].nombre = "Dead Poets Society";
	a[1].clave = "1973";
	a[1].nombre = "Star Wars";
	a[2].clave = "1997";
	a[2].nombre = "Harry Potter";
	// datos = a[i].clave << " ... " << a[i].nombre << " ... ";
	while(band && i < n){
		if(a[i].clave == ""){
			band = false;
		}
		else{
			cout << a[i].clave << " ... " << a[i].nombre << " ... " << endl;
			i++;
		}
	}
}


int main(){
	producto peliculas[49];
	int n = 50;
	int opcion;
	while (1){
		cout<<"\n\t\t\t\tInventario de Cine\n\n";
		cout<<"\n\t\t\t\tSelecciona una opcion\t\n";
		cout<<"\n\t\t\t1.Alta del producto\n";
		cout<<"\n\t\t\t2.Modificacion de un producto\n";
		cout<<"\n\t\t\t3.Mostrar Catalogo de productos\n";
		cout<<"\n\t\t\t4.Productos cuya existencia sea menor a N \n";
		cout<<"\n\t\t\t5.Productos que pertenezcan a un proveedor especifico\n";
		cout<<"\n\t\t\t6.Productos que cuesten mas de un precio N\n";
		cout<<"\n\t\t\t\t\t7.Salir\t\t\t\t\n";

		cin>>opcion;

		switch(opcion){

			case 1:
				//funcion para leer arreglo de registros :)
				
				break;

			case 2:
				//funcion para modificar un campo
				modificar(peliculas);
				break;

			case 3:
				//escribir el arreglo de los productos
				catalogo(peliculas,n);
				break;

			case 4:
				
				int max;
				cout << "Ingresa el numero de existencia maximo que deben tener los productos \n";
				cin >> max;
				break;

			case 5:
				int proveedor;
				cout << "Ingresa el proveedor que quieres buscar \n";
				cin >> proveedor;
				break;
			case 6:
				int precio;
				cout << "Ingresa el precio minimo que deben tener las peliculas \n";
				cin >> precio;
				break;	

			case 7:
				return 0;	
				break;

			default:
				cout<<"La opcion elegida no es valida";
				break;	
		}		
		}


	return 0;
}
