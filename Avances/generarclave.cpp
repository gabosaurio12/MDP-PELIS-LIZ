#include <iostream>
#include <string>
#include<sstream>

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

string letrasClave(producto a[], int n){
	int j=0;

	string palabra = a[n].distribuidora;

	string letrasc = "";

	while(j<2){
		letrasc = letrasc + palabra[j];
		j++;
	}

	return letrasc;
}

string numerosClave(int n){
	string numcad = "";
	char cero = '0';
	n=n+1;
	stringstream ss;

	ss << n;

	ss >> numcad;

	numcad = cero + numcad;

	if(n<9){
		numcad = '0' + numcad;
	}

	return numcad;
}

string claveCompleta(producto a[], int n){
	string letras = letrasClave(a, n);

	string numeros = numerosClave(n);

	string clavecomp = letras + numeros;

	return clavecomp;
}

void altaProd(producto a[], int n){
	for(int i=0; i<n; i++){
		cout<<"Introduce la distribuidora \n";
		cin.ignore();
		getline(cin, a[i].distribuidora);

		cout<<"La clave es: \n";
		a[i].clave = claveCompleta(a, i);
		cout<<a[i].clave << "\n";
		
		cout<<"Introduce el nombre de la pelicula \n";
		getline(cin, a[i].nombre);
		
		cout<<"Introduce la cantidad de ejemplares\n";
		cin>>a[i].cantidad;
		
		cout<<"Introduce el precio \n";
		cin>>a[i].precio;
		
		cout<<"Ingresa el genero \n";
		cin.ignore();
		getline(cin, a[i].genero);
		
		cout<<"Ingresa el formato \n";
		getline(cin, a[i].formato);
		
		cout<<"Ingresa el director \n";
		getline(cin, a[i].director);
	}
}

int main(){
	int n;
	producto arreglo[50];

	cout<<"No. de productos\n";
	cin>>n;

	cout<<"Introduce los datos\n";
	altaProd(arreglo, n);

	return 0;
}
