#include<iostream>
#include<ctime>
#include "arbolAVL.h"
#include<Windows.h>
using namespace std;

void imprimir(int e) {
	cout << " " << e;
}

///------
int main() {
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
}