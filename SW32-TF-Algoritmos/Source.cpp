#include<iostream>
#include<ctime>
#include<filesystem>
#include <chrono>
#include <iomanip>
#include "arbolAVL.h"
#include<Windows.h>
#include<vector>
#include <string>
using namespace std;
using namespace std::experimental::filesystem;
namespace fs = std::experimental::filesystem;

using namespace std::chrono_literals;
void imprimir(int e) {
	cout << " " << e;
}
void imprime(string p) 
{
	cout << " " << p;
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
	ArbolAVL<string>* arbolito;
	ArbolAVL<string>* file;
	file = new ArbolAVL<string>(imprime);
	arbolito = new ArbolAVL<string>(imprime);
	auto ftime = last_write_time("C:\\Users\\Aldo\\Pictures\\Saved Pictures");

	std::time_t cftime = decltype(ftime)::clock::to_time_t(ftime); // assuming system_clock

	string path1 = "C:\\Users\\Aldo\\Pictures\\Saved Pictures";  // . es la careta del programa // investigar c++files system
	string path2 = "C:\\Users\\Aldo\\Pictures\\Saved Pictures";
	string path3 = "C:\\Users\\Aldo\\Pictures\\Saved Pictures";

	for (const auto & entry : directory_iterator(path1)) {
		cout << entry.path() << endl;
		cout << path(entry.path()).filename() << endl;
		/*path2 = path(entry.path()).filename();*/
		cout << file_size(entry.path()) << endl;
		cout << path(entry.path()).extension() << endl;
		ftime = last_write_time(entry.path());
		cftime = decltype(ftime)::clock::to_time_t(ftime);
		path2 = path(entry.path().filename()).u8string();
		path3= path(entry.path().extension()).u8string();
		cout << "File write time is " << asctime(localtime(&cftime));
		sizefile->insertar(file_size(entry.path()));
		file->insertar(path2);
		arbolito->insertar(path3);
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
	cout << "\n";
	sizefile->inOrder();
	cout << "\n";
	file->inOrder();
	cout << "\n";
	arbolito->inOrder();
	cout << "\n";
	system("pause");
#ifdef _MSC_VER
#pragma warning(pop)
#endif
	return 0;
}