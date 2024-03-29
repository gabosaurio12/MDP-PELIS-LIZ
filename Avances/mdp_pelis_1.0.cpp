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

void altaProd (producto a[], int i){
	cout<<"Introduce la distribuidora\n";
	getline(cin, a[i].distribuidora);
	cout<<"Introduce el nombre de la pelicula\n";
	getline(cin, a[i].nombre);
	cout<<"Introduce la cantidad de ejemplares\n";
	cin>>a[i].cantidad;
	cout<<"Introduce el precio\n";
	cin>>a[i].precio;
	cout<<"Ingresa el genero de la pelicula\n";
	getline(cin, a[i].genero);
	cout<<"Ingresa el formato\n";
	getline(cin, a[i].formato);
	cout<<"Ingresa el director\n";
	getline(cin, a[i].director);
}

int confirmarProd(producto a[], int i){
	string respuesta;

	cout<<"¿Los datos introducidos son correctos?\n";
	cout<<a[i].distribuidora;
	cout<<a[i].nombre;
	cout<<a[i].cantidad;
	cout<<a[i].precio;
	cout<<a[i].genero;
	cout<<a[i].formato;
	cout<<a[i].director;
	cout<<"\t\t\tSi\t\tNo\n";
	cin>>respuesta;

	if(respuesta == "SI" || respuesta == "si" || respuesta =="Si"){
		return 1;
	}
	else{
		return 0;
	}

}


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

void distEspecifico(producto a[], string buscador, int n){
	for(int i=0; i<n; i++){
		if(a[i].distribuidora == buscador){
			cout<<a[i].clave;
			cout<<"\n"<<a[i].distribuidora;
			cout<<"\n"<<a[i].nombre;
			cout<<"\n"<<a[i].cantidad;
			cout<<"\n"<<a[i].precio;
			cout<<"\n"<<a[i].genero;
			cout<<"\n"<<a[i].formato;
			cout<<"\n"<<a[i].director<<"\n\n";
		}
	}
}

void masPrecio(producto a[], int precio, int n){
	for(int i=0; i<n; i++){
		if(a[i].precio > precio){
			cout<<a[i].clave<<"\t"<<a[i].distribuidora<<"\t"<<a[i].nombre<<"\t"<<a[i].cantidad<<"\t"<<a[i].precio<<"\t"<<a[i].genero<<"\t"<<a[i].formato<<"\t"<<a[i].director<<"\n\n";
		}
	}
}


int main(){
	producto peliculas[49];
	int n = 50;
	int i=0;
	int opcion;
	string proveedor;
	float precio;

	while (1){
		cout<<"\n\t\t\t\tInventario de Cine\n\n";
		cout<<"\n\t\t\t\tSelecciona una opcion\t\n";
		cout<<"\n\t\t\t1.Alta del producto\n";
		cout<<"\n\t\t\t2.Modificacion de un producto\n";
		cout<<"\n\t\t\t3.Mostrar Catalogo de productos\n";
		cout<<"\n\t\t\t4.Productos cuya existencia sea menor a N \n";
		cout<<"\n\t\t\t5.Productos que pertenezcan a una distribuidora especifica\n";
		cout<<"\n\t\t\t6.Productos que cuesten mas de un precio N\n";
		cout<<"\n\t\t\t\t\t7.Salir\t\t\t\t\n";

		cin>>opcion;

		switch(opcion){

			case 1:
			altaProd(peliculas, i);

			confirmarProd(peliculas,i);

			if(confirmarProd(peliculas, i)){
				i++;
			}

				
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
				cout << "Ingresa la distribuidora que quieres buscar \n";
				cin >> proveedor;

				distEspecifico(peliculas, proveedor, i+1);

				break;

			case 6:
				cout << "Ingresa el precio minimo que deben tener las peliculas \n";
				cin >> precio;

				masPrecio(peliculas, precio, i+1);
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
