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
	getline(cin, arrPelis[i].distribuidora);
	transform(arrPelis[i].distribuidora.begin(),arrPelis[i].distribuidora.end(), arrPelis[i].distribuidora.begin(),::toupper);
	cout<<"Introduce el nombre de la pellicula\n";
	getline(cin, arrPelis[i].nombre);
	cout<<"Introduce la cantidad de ejemplares\n";
	cin>>arrPelis[i].cantidad;
	cout<<"Introduce el precio\n";
	cin>>arrPelis[i].precio;
	cout<<"Introduce el genero\n";
	getline(cin, arrPelis[i].genero);
	cout<<"Introduce el formato(DVD, BluRay, VHS o Digital)\n";
	getline(cin, arrPelis[i].formato);
	cout<<"Introduce el director\n";
	getline(cin, arrPelis[i].director);

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
