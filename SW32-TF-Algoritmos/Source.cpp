#include<iostream>
#include<ctime>
#include<filesystem>
#include "arbolAVL.h"
#include<Windows.h>
using namespace std;
using namespace std::experimental::filesystem;

void imprimir(int e) {
	cout << " " << e;
}

///------
int main() {
	string path = "C:\\Users\\Aldo\\Documents\\Especificación y Análisis de Requerimientos";
	for (const auto & entry : recursive_directory_iterator(path)) {
		cout << entry.path() << endl;
	}
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