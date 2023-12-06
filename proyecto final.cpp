#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

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
	
	cout<<"Introduce el nombre de la pelicula\n";
	getline(cin, arrPelis[i].nombre);
	transform(arrPelis[i].nombre.begin(),arrPelis[i].nombre.end(), arrPelis[i].nombre.begin(),::toupper);
	
	cout<<"Introduce la cantidad de ejemplares\n";
	cin>>arrPelis[i].cantidad;
	
	cout<<"Introduce el precio\n";
	cin>>arrPelis[i].precio;
	
	cout<<"Introduce el genero\n";
	cin.ignore();
	getline(cin, arrPelis[i].genero);
	transform(arrPelis[i].genero.begin(),arrPelis[i].genero.end(), arrPelis[i].genero.begin(),::toupper);
	
	cout<<"Introduce el formato(DVD, BluRay, VHS o Digital)\n";
	getline(cin, arrPelis[i].formato);
	transform(arrPelis[i].formato.begin(),arrPelis[i].formato.end(), arrPelis[i].formato.begin(),::toupper);
	
	cout<<"Introduce el director\n";
	getline(cin, arrPelis[i].director);
	transform(arrPelis[i].director.begin(),arrPelis[i].director.end(), arrPelis[i].director.begin(),::toupper);
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

	cout<<"\n¿Los datos introducidos son correctos?\n";
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
	int posicion;
	cout << "Ingresa la clave del producto: ";
	cin >> clave;
	transform(clave.begin(),clave.end(),clave.begin(), ::toupper);
	posicion = posicionPeli(arrPelis,clave,n);
	
	if(posicion == 50){
		cout << "Clave invalida \n";
	}
	else{
		char opcion;
		string nuevaDistribuidora, nuevoNombre, nuevoGenero, nuevoFormato, nuevoDirector;
		int nuevaCantidad;
		float nuevoPrecio;

		cout << "\n";
		cout << "CLAVE " << arrPelis[posicion].clave << "\n";
		cout << "DISTRIBUIDORA " << arrPelis[posicion].distribuidora << "\n";
		cout << "NOMBRE " << arrPelis[posicion].nombre << "\n";
		cout << "CANTIDAD " << arrPelis[posicion].cantidad << "\n";
		cout << "PRECIO " << arrPelis[posicion].precio << "\n";
		cout << "GENERO " << arrPelis[posicion].genero << "\n";
		cout << "FORMATO " << arrPelis[posicion].formato << "\n";
		cout << "DIRECTOR " << arrPelis[posicion].director << "\n";

		cout << "\nElige la opcion que deseas modificar \n";

		cout << "1. Distribuidora \n";
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
				cout << "Ingresa la nueva Distribuidora: ";
				cin.ignore();
				getline(cin, nuevaDistribuidora);
				transform(nuevaDistribuidora.begin(), nuevaDistribuidora.end(), nuevaDistribuidora.begin(), ::toupper);
				arrPelis[posicion].distribuidora = nuevaDistribuidora;
				cout << "La Distribuidora ha sido actualizada \n";
				break;

			case '2':
				cout << "Ingresa el nuevo Nombre: ";
				cin.ignore();
				getline(cin, nuevoNombre);
				transform(nuevoNombre.begin(), nuevoNombre.end(), nuevoNombre.begin(), ::toupper);
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
				cin>> nuevoPrecio;
				arrPelis[posicion].precio = nuevoPrecio;
				cout << "El Precio ha sido actualizado \n";
				break;

			case '5':
				cout << "Ingresa el Genero nuevo: ";
				cin.ignore();
				getline(cin, nuevoGenero);
				transform(nuevoGenero.begin(), nuevoGenero.end(), nuevoGenero.begin(), ::toupper);
				arrPelis[posicion].genero = nuevoGenero;
				cout << "El Genero ha sido actualizado \n";
				break;

			case '6':
				cout << "Ingresa el nuevo Formato: ";
				cin.ignore();
				getline(cin, nuevoFormato);
				transform(nuevoFormato.begin(), nuevoFormato.end(), nuevoFormato.begin(), ::toupper);
				arrPelis[posicion].formato = nuevoFormato;
				cout << "El Formato ha sido actualizado \n";
				break;

			case '7':
				cout << "Ingresa el Director nuevo: ";
				cin.ignore();
				getline(cin, nuevoDirector);
				transform(nuevoDirector.begin(), nuevoDirector.end(), nuevoDirector.begin(), ::toupper);
				arrPelis[posicion].director = nuevoDirector;
				cout << "El Director ha sido actualizado \n";
				break;

			case '8':

				break;

			default:
				cout << "Opcion invalida \n";
				modificarPeli(arrPelis,n);
		}
	}
}

void mostrarCatalogo(producto arrPelis[], int n){
	for(int i = 0; i < n; i++){
		cout << "\n";
		cout << "CLAVE " << arrPelis[i].clave << "\n";
		cout << "DISTRIBUIDORA " << arrPelis[i].distribuidora << "\n";
		cout << "NOMBRE " << arrPelis[i].nombre << "\n";
		cout << "CANTIDAD " << arrPelis[i].cantidad << "\n";
		cout << "PRECIO " << arrPelis[i].precio << "\n";
		cout << "GENERO " << arrPelis[i].genero << "\n";
		cout << "FORMATO " << arrPelis[i].formato << "\n";
		cout << "DIRECTOR " << arrPelis[i].director << "\n";
	}
}

void prodExisMenorN(producto arrPelis[], int n, int max){
	producto arrMenores[49];
	int cont;
	char orden;
	cont = 0;
	for(int i = 0; i < n; i++){
		if(arrPelis[i].cantidad < max){
			arrMenores[cont] = arrPelis[i];
			cont++;
		}
		i++;
	}

	for(int i = 0; i < cont; i++){
		cout << "\n";
		cout << "CLAVE " << arrMenores[i].clave << "\n";
		cout << "NOMBRE " << arrPelis[i].nombre << "\n";
		cout << "CANTIDAD " << arrPelis[i].cantidad << "\n";
		cout << "PRECIO " << arrPelis[i].precio << "\n";
		cout << "GENERO " << arrPelis[i].genero << "\n";
		cout << "FORMATO " << arrPelis[i].formato << "\n";
	}
}

void buscaDistribuidor(producto arrPelis[], string distribucion, int nProductos){
	for(int i = 0; i<nProductos; i++){
		if(arrPelis[i].distribuidora == distribucion){
			cout<<"\n";
			cout<< "CLAVE " << arrPelis[i].clave<<"\n";
			cout<< "DISTRIBUIDORA " << arrPelis[i].distribuidora<<"\n";
			cout<< "NOMBRE " << arrPelis[i].nombre<<"\n";
			cout<< "CANTIDAD " << arrPelis[i].cantidad<<"\n";
			cout<< "PRECIO " << arrPelis[i].precio<<"\n";
			cout<<"FORMATO " << arrPelis[i].formato<<"\n";
		}
	}
}

void masPrecio(producto arrPelis[], int minprecio, int nProductos){
	for (int i=0; i<nProductos; i++){
		if(arrPelis[i].precio > minprecio){
			cout<<"\n";
			cout<< "CLAVE " << arrPelis[i].clave<<"\n";
			cout<< "NOMBRE " << arrPelis[i].nombre<<"\n";
			cout<< "CANTIDAD " << arrPelis[i].cantidad<<"\n";
			cout<< "PRECIO " << arrPelis[i].precio<<"\n";
			cout<< "FORMATO " << arrPelis[i].formato<<"\n";
		}
	}
}

int main(){
	producto peliculas[50];

	char opcion;
	int i = 0;
	int nP = 0;
	int prod = 0;
	int precioMin;
	int max;
	string distribuidora;



	while(1){
		cout<<"\n\t\t\t\tInventario de Cine\n";
		cout<<"\n\n\t\t\t\tSelecciona una opcion\t\n";
		cout<<"\n\t\t\t1.Alta del producto\n";
		cout<<"\n\t\t\t2.Modificar un producto\n";
		cout<<"\n\t\t\t3.Mostrar catalogo de productos\n";
		cout<<"\n\t\t\t4.Productos cuya existencia sea menor a N\n";
		cout<<"\n\t\t\t5. Productos que pertenecan a una distribuidora especifica\n";
		cout<<"\n\t\t\t6. Productos que cuesten mas de un precio N\n";
		cout<<"\n\t\t\t\t\t7. Salir\t\t\t\t\n";
	
		cout << "Ingresa la opcion: ";
		//cin.ignore();  solo si se compila con gcc
		cin>>opcion;
	
		switch(opcion){
			case '1':
				if(prod < 50){
					altaproducto(peliculas, i);
			
					if(confirmarproducto(peliculas, i)){
						peliculas[i].clave = generarClave(peliculas, i);
						i = i+1;
						nP = nP+1;	     			
					}

					prod++;
				}
				else{
					cout << "Ya no se pueden dar mas productos de alta \n";
				}
		     	break;
		     
			case '2':
				//modificar
				modificarPeli(peliculas,nP);
			break;
	
			case'3':
		     		//mostrar catalogo
				mostrarCatalogo(peliculas,nP);
		     		break;
	
			case '4':
				//productos mayor a N
				cout << "Ingresa la cantidad maxima que quieres que tengan los productos \n";
				cin >> max;
				
		    	while(max < 0){
			      		cout<<"Introduce la cantidad correcta\n";
		 	      		cin>>max;
		    		}	
				prodExisMenorN(peliculas,nP,max);
				break;
	
		 	case '5':
		 		cout<<"¿Qué distribuidora quieres buscar?\n";
		 		cin.ignore();
		 		getline(cin, distribuidora);
		 		transform(distribuidora.begin(), distribuidora.end(), distribuidora.begin(), ::toupper);	
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
