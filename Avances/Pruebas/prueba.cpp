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

int main(){

	int n;
	producto a[50];

	cout<<"No. de productos\n";
	cin>>n;

	for(int i = 0; i<n; i++){
		string cadena;
		cout << "Cadena 0 " << cadena << endl;
		cout << "A \n";
		cin.ignore();
		getline(cin, cadena);
		cout << "Cadena " << cadena << endl;
	}
	return 0;
}