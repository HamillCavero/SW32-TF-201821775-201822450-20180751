#pragma once
#include<iostream>
#include<conio.h>
#include<functional>
#include<string>

using namespace std;

void Menu(int &opc) {
	
	while (opc == 0) 
	{
		cout << "\n\n\t\t\t\t      " << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
		cout << "\t\t\t\t      " << char(186) << "\t\t\t\t\t    " << char(186) << endl;
		cout << "\t\t\t\t      " << char(186) << "\t\t       MENU\t\t    " << char(186) << endl;
		cout << "\t\t\t\t      " << char(186) << "\t\t\t\t\t    " << char(186) << endl;
		cout << "\t\t\t\t      " << char(186) << "    1. Ingrese ruta:\t\t    " << char(186) << endl;
		cout << "\t\t\t\t      " << char(186) << "    8. Salir           \t\t    " << char(186) << endl;
		cout << "\t\t\t\t      " << char(186) << "\t\t\t\t\t    " << char(186);
		cout << "\n\t\t\t\t      " << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;

		do {
			
			cout << "ELIJA UNA OPCION: ";
			cin >> opc;
		} while (!(opc >= 1 && opc <= 5));
	
		system("cls");
	}
}
void Menu2(int &opc) {
	opc = 0;
	while (opc == 0)
	{
		cout << "\n\n\t\t\t\t      " << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
		cout << "\t\t\t\t      " << char(186) << "\t\t\t\t\t    " << char(186) << endl;
		cout << "\t\t\t\t      " << char(186) << "\t\t       MENU\t\t    " << char(186) << endl;
		cout << "\t\t\t\t      " << char(186) << "\t\t\t\t\t    " << char(186) << endl;
		cout << "\t\t\t\t      " << char(186) << "    2. Mostrar Archivos Encontrados\t\t    " << char(186) << endl;
		cout << "\t\t\t\t      " << char(186) << "    3. Buscar por peso\t\t    " << char(186) << endl;
		cout << "\t\t\t\t      " << char(186) << "    4. Ordenar Archivos\t\t    " << char(186) << endl;
		cout << "\t\t\t\t      " << char(186) << "    6. Ordenar Archivos\t\t    " << char(186) << endl;
		cout << "\t\t\t\t      " << char(186) << "    5. Salir           \t\t    " << char(186) << endl;

		cout << "\t\t\t\t      " << char(186) << "\t\t\t\t\t    " << char(186);
		cout << "\n\t\t\t\t      " << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;

		do {

			cout << "ELIJA UNA OPCION: ";
			cin >> opc;
		} while (!(opc >= 1 && opc <= 6));

		system("cls");
	}
}

