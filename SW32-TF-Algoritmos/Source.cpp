#include<iostream>
#include<ctime>
#include<filesystem>
#include <chrono>
#include <iomanip>
#include "arbolAVL.h"
#include<Windows.h>
using namespace std;
using namespace std::experimental::filesystem;
using namespace std::chrono_literals;
void imprimir(int e) {
	cout << " " << e;
}

///------
int main() {
	//string path = "C:\\Users\\Aldo\\Documents\\Especificación y Análisis de Requerimientos";
	
	

	string path1 = "E:\\felicidad";  // . es la careta del programa // investigar c++files system
	

	for (const auto & entry : directory_iterator(path1)) {
		cout << entry.path() << endl ;
		cout << path(entry.path()).filename() << endl;
		cout << file_size(entry.path()) << endl;
		cout << path(entry.path()).extension() << endl; 
		
	}

	/* path1 = "E:\\New folder\\asdfghj.txt";
	for (const auto & entry : recursive_directory_iterator(path1)) {
		cout << entry.path() << endl;
	}*/

	srand(time_t(NULL));
	//--
	ArbolAVL<int>* tree;
	//--
	tree = new ArbolAVL<int>(imprimir);
	//----
	cout << "Randon Number Generating..." << endl;
	for (int i = 0; i < 7; i++) {
		int val = 1 + rand() % 100;
		cout << "Inserting(";
		imprimir(val);
		cout << ")" << endl;
		///----
		tree->insertar(val);
	}
	//--
	tree->inOrder();
	cout << "\n";
	system("pause");
	return 0;
}