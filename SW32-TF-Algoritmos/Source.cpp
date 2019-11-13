#include<iostream>
#include<ctime>
#include<filesystem>
#include <chrono>
#include <iomanip>
#include "arbolAVL.h"
#include<Windows.h>
using namespace std;
using namespace std::experimental::filesystem;
namespace fs = std::experimental::filesystem;

using namespace std::chrono_literals;
void imprimir(int e) {
	cout << " " << e;
}
///------
int main() {
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4996)
#endif
	ArbolAVL<int>* tree;
	ArbolAVL<int>* sizefile;
	sizefile = new ArbolAVL<int>(imprimir);
	tree = new ArbolAVL<int>(imprimir);
	auto ftime = last_write_time("E:\\felicidad\\tree.h");

	std::time_t cftime = decltype(ftime)::clock::to_time_t(ftime); // assuming system_clock

	string path1 = "E:\\felicidad";  // . es la careta del programa // investigar c++files system

	for (const auto & entry : directory_iterator(path1)) {
		cout << entry.path() << endl ;
		cout << path(entry.path()).filename() << endl;
		cout << file_size(entry.path()) << endl;
		cout << path(entry.path()).extension() << endl; 

		ftime = last_write_time(entry.path());
		cftime = decltype(ftime)::clock::to_time_t(ftime);

		cout << "File write time is " << asctime(localtime(&cftime));
		sizefile->insertar(file_size(entry.path()));
	}


	srand(time_t(NULL));
	//--

	//--
	
	//----
	/*cout << "Randon Number Generating..." << endl;
	for (int i = 0; i < 7; i++) {
		int val = 1 + rand() % 100;
		cout << "Inserting(";
		imprimir(val);
		cout << ")" << endl;
		///----
		tree->insertar(val);
	}*/
	//--
	tree->inOrder();
	sizefile->inOrder();
	cout << "\n";
	system("pause");
#ifdef _MSC_VER
#pragma warning(pop)
#endif
	return 0;
}