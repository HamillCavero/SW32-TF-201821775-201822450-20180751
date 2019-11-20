#pragma once
#include<iostream>
#include<conio.h>
#include<functional>
#include<string>

using namespace std;

void Menu(int opc) {
	string ruta;
	while (opc == 0) {
		cout << "------------------Menu-----------------" << endl;
		cout << "----1. Agregue una ruta----------------" << endl;
		cout << "----2. Salir---------------------------" << endl;
		cout << "Ingrese una opción: " << endl;
		cin >> opc;

		switch (opc)
		{

		case 1:
			cout << "Ingrese ruta";
			cin >> ruta;
			break;
		case 2:
			exit(0);
			break;
		default:
			cout << "Ingresa otra opcion papanatas";  
			break;
		}
	}

}



