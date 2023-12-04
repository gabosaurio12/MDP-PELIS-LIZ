#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct producto{
	string distribuidora;
	string nombre;
	int cantidad;
	float precio;
	string genero;
	string formato;
	string director;
	string clave;
};

void altaproducto(producto arrPelis[], int i){
	
	cout<<"Introduce la distribuidora\n";
	cin.ignore();
	getline(cin, arrPelis[i].distribuidora);
	transform(arrPelis[i].distribuidora.begin(),arrPelis[i].distribuidora.end(), arrPelis[i].distribuidora.begin(),::toupper);
	cout<<"Introduce el nombre de la pellicula\n";
	getline(cin, arrPelis[i].nombre);
	cout<<"Introduce la cantidad de ejemplares\n";
	cin>>arrPelis[i].cantidad;
	cout<<"Introduce el precio\n";
	cin>>arrPelis[i].precio;
	cout<<"Introduce el genero\n";
	cin.ignore();
	getline(cin, arrPelis[i].genero);
	cout<<"Introduce el formato(DVD, BluRay, VHS o Digital)\n";
	getline(cin, arrPelis[i].formato);
	cout<<"Introduce el director\n";
	getline(cin, arrPelis[i].director);

}

int longitudCadena(string palabra, int posicion){
	int contador = 0;
	int i = 0;

	while(palabra[i] != '\0'){
		contador++;
		i++;
	}
	return contador;
}

string generarClave(producto arrPelis[], int posicion){
	int j = 0;
	string palabra = arrPelis[posicion].distribuidora;
	string letrasc="";
	string numcad="";
	string clavecomp;

	posicion = posicion + 1;

	int lcad = longitudCadena(palabra, posicion);

	stringstream ss;

	ss << posicion;
	ss >> numcad;

	numcad = '0' + numcad;

	if(posicion < 10){
		numcad = '0' + numcad;
	}

	if(lcad < 2){
		clavecomp = palabra + palabra + numcad;
	}
	else {
		while (j < 2){
		letrasc = letrasc + palabra[j];
		j++;
	}

	clavecomp = letrasc + numcad;

	}

	return clavecomp;

}

int confirmarproducto(producto arrPelis[], int i){
	string respuesta;

	cout<<"¿Los datos introducidos son correctos?\n";
	cout<<"Distribuidora: "<<arrPelis[i].distribuidora<<"\n";
	cout<<"Nombre: "<<arrPelis[i].nombre<<"\n";
	cout<<"Cantidad: "<<arrPelis[i].cantidad<<"\n";
	cout<<"Precio: "<<arrPelis[i].precio<<"\n";
	cout<<"Genero: "<<arrPelis[i].genero<<"\n";
	cout<<"Formato: "<<arrPelis[i].formato<<"\n";
	cout<<"Director: "<<arrPelis[i].director<<"\n";
	cout<<"\t\t\t1:Si\t\t\t2:No\t\t\t\n";
	cin>>respuesta;

	if(respuesta == "1" || respuesta == "Si" || respuesta =="SI" || respuesta =="si"){
		return 1;
	}
	else{
		return 0;
	}

}


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

void masPrecio(producto arrPelis[], int minprecio, int nProductos){
	for (int i=0; i<nProductos; i++){
		if(arrPelis[i].precio > minprecio){
			cout<<"\n";
			cout<<arrPelis[i].clave<<"\n";
			cout<<arrPelis[i].distribuidora<<"\n";
			cout<<arrPelis[i].nombre<<"\n";
			cout<<arrPelis[i].cantidad<<"\n";
			cout<<arrPelis[i].precio<<"\n";
			cout<<arrPelis[i].genero<<"\n";
			cout<<arrPelis[i].formato<<"\n";
			cout<<arrPelis[i].director<<"\n";
		}
	}
}

int main(){
	char opcion;
	int i = 0;
	string distribuidora;
	int nP = 0;
	int precioMin;

	producto peliculas[50];


	while(1){
	cout<<"\n\t\t\t\tInventario de Cine\n\n";
	cout<<"\n\n\t\t\t\t Selecciona una opcion\t\n";
	cout<<"\n\t\t\t1.Alta del producto\n";
	cout<<"\n\t\t\t2.Modificar un producto\n";
	cout<<"\n\t\t\t3.Mostrar catalogo de productos\n";
	cout<<"\n\t\t\t4.Productos cuya existencia sea mayor a N\n";
	cout<<"\n\t\t5. Productos que pertenecan a una distribuidora especifica\n";
	cout<<"\n\t\t\t6. Productos que cuesten mas de un precio N\n";
	cout<<"\n\t\t\t\t\t7. Salir\t\t\t\t\n";

	cin>>opcion;

	switch(opcion){
	     case '1':
	     	//altaproducto(peliculas, i);

	     	/*if(confirmarproducto(peliculas, i)){
	     		peliculas[i].clave = generarClave(peliculas, i);
				i = i+1;
				nP = nP+1;	     			
	     	}*/
	     	break;
	     
	     case '2':
	     	//modificar
		modificarPeli(peliculas,np);
	     	break;

	     case'3':
	     	//mostrar catalogo

	     	break;

	 	case '4':
	 		//productos mayor a N

	 		break;

	 	case '5':
	 		cout<<"¿Qué distribuidora quieres buscar?\n";
	 		getline(cin, distribuidora);		
	 		buscaDistribuidor(peliculas, distribuidora, nP);

	 		break;
	 	
	 	case '6':
	 		cout<<"Introduce el precio a comparar\n";
	 		cin>>precioMin;
			
	    		while(precioMin < 0){
		      		cout<<"Introduce el precio correcto\n";
	 	      		cin>>precioMin;
	    		}
      
      masPrecio(peliculas, precioMin, nP);

	 		break;

	 case '7':
	 	
	 	return 0;

	 	break;

	default:
		cout<<"La opcion elegida no es valida\n";

		break;

	}

	}

	return 0;
}
