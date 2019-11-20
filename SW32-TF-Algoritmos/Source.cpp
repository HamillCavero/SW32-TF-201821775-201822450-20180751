#include <sstream>
#include <stdlib.h>
#include<iostream>
#include<ctime>
#include<filesystem>
#include <chrono>
#include <iomanip>
#include "arbolAVL.h"
#include<Windows.h>
#include<vector>
#include <string>
#include "Menu.h"
using namespace std;
using namespace std::experimental::filesystem;
namespace fs = std::experimental::filesystem;
using namespace std::chrono_literals;

class Book {
	string name;
	int size;
	string extension; // good reads
	string timeupdate;
public:
	Book(string name, int year, string score, string timeupdate)
		: name(name), size(year), extension(score), timeupdate(timeupdate) {}

	string getName() { return name; }
	int getSize() { return size; }
	string getExtension() { return extension; }
	string getTimeUpdate() { return timeupdate; }
	void setname(string name) { this->name = name; }
	void setyear(int year) { this->size = year; }
	void setscore(string score) { this->extension = score; }
	void setTimeupdate(string update) { this->timeupdate = update; }
};
typedef AVLTree<Book*, string, nullptr> TreeStr;
typedef AVLTree<Book*, int, nullptr> TreeInt;
typedef AVLTree<Book*, string, nullptr> TreeFlt;
typedef AVLTree<Book*, string, nullptr>TreeUpdate;

void opciones(int &opc) 
{
	cout << "Opciones apartir de la ruta:" << endl;
	cout << "Seleccione (2) para ver todos los archivos encontrados" << endl;
	cout << "Seleccione (3) para buscar por peso" << endl;
	cout << "Seleccione (8) para salir." << endl;
	cin >> opc;
}
void llenararbol(string ruta,string path2,string path3,TreeStr* names ,TreeInt* size,TreeFlt* extension ,TreeUpdate* hora,uintmax_t valorpeso)
{
	auto ftime = last_write_time(ruta);
	std::time_t cftime = decltype(ftime)::clock::to_time_t(ftime); // assuming system_clock
	for (const auto & entry : directory_iterator(ruta)) {

		ftime = last_write_time(entry.path());

		cftime = decltype(ftime)::clock::to_time_t(ftime);

		path2 = entry.path().stem().string();
		path3 = entry.path().extension().string();
		valorpeso = file_size(entry.path());
		Book* name = new Book(path2, valorpeso, path3, asctime(localtime(&cftime)));
		names->add(name);
		size->add(name);
		extension->add(name);
		hora->add(name);
	}
}

int main()
{
	/*inicializar();*/
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4996)
#endif
	int opc = 0;
	string ruta = "";
	uintmax_t valorpeso = 0;
	float pesoarchivo=0.0;
	Menu(opc);

	auto l1 = [](Book* a) { return a->getName(); };
	auto l2 = [](Book* a) { return a->getSize(); };
	auto l3 = [](Book* a) { return a->getExtension(); };
	auto l4 = [](Book*a) {return a->getTimeUpdate(); };
	TreeStr* nameTree = new TreeStr(l1);
	TreeInt* sizeTree = new TreeInt(l2);
	TreeFlt* extensionTree = new TreeFlt(l3);
	TreeUpdate* time = new TreeUpdate(l4);

	string path1 = "";  // . es la careta del programa // investigar c++files system
	string path2 = "";
	string path3 = "";
	auto prnt = [](Book* a)
	{

		if (a != nullptr)
		{
			cout << "{"
				<< a->getName() << ","
				<< a->getSize() << ","
				<< a->getExtension() << ","
				<< a->getTimeUpdate() << "\n";

		}
		else {
			cout << "Not found\n";

		}
	};
	while (true)
	{
		switch (opc)
		{
		case 1:
		{
			cout << "Ingrese la ruta : "; cin >> ruta;
			path1 = ruta;
			path2 = ruta;
			path3 = ruta;
			system("cls");
			llenararbol(ruta, path2, path3, nameTree, sizeTree, extensionTree, time, valorpeso);
			opciones(opc);
		}
		break;
		case 2:
		{
			cout << "Nombre archivo:" << endl;
			nameTree->inorder(prnt);
			cout << "-----------------------==\n";
			cout << "Peso archivo:" << endl;
			sizeTree->inorder(prnt);
			cout << "INVERSO:" << endl;
			sizeTree->postorden(prnt);
			cout << "-----------------------==\n";
			cout << "Extensión:" << endl;
			extensionTree->inorder(prnt);
			cout << "-----------------------==\n";
			cout << "Time Update: " << endl;
			cout << "-----------------------==\n";
			time->inorder(prnt);

			system("pause>0");
			system("cls");
			opciones(opc);
		}
		break;
		case 3:
		{
			cout << "Ingrese el peso buscado: "; cin >> pesoarchivo;
			cout << endl;
			cout << "---------------------------------" << endl;
			prnt(sizeTree->find(pesoarchivo));
			cout << "--------------------------";
			system("cls");
			opciones(opc);

		}
		break;
		case 8:
		{
			exit(0);
		}
		break;
		default:
			cout << "Opcion incorrecta:";
			break;
		}
	}
	/*if (opc == 1)
	{
		cout << "Ingrese la ruta : "; cin >> ruta;
		path1 = ruta;
		path2 = ruta;
		path3 = ruta;
		system("cls");
		opciones(opc);
	}*/
	
	//if (opc == 2)
	//{
	//	cout << "Nombre archivo:" << endl;
	//	nameTree->inorder(prnt);
	//	cout << "-----------------------==\n";
	//	cout << "Peso archivo:" << endl;
	//	sizeTree->inorder(prnt);
	//	cout << "INVERSO:" << endl;
	//	sizeTree->postorden(prnt);
	//	cout << "-----------------------==\n";
	//	cout << "Extensión:" << endl;
	//	extensionTree->inorder(prnt);
	//	cout << "-----------------------==\n";
	//	cout << "Time Update: " << endl;
	//	cout << "-----------------------==\n";
	//	time->inorder(prnt);
	//	
	//	system("pause>0");
	//	system("cls");
	//	opc = 0;
	//	opciones(opc);
	//
	//}
	/*if (opc == 3)
	{
		cout << "Ingrese el peso buscado: "; cin >> pesoarchivo;
		cout << endl;
		cout << "---------------------------------" << endl;
		prnt(sizeTree->find(pesoarchivo));
		cout << "--------------------------";
		opciones(opc);
	}
	*//*if (opc == 8) 
	{
		exit(0);
	}*/
	delete nameTree;
	delete time;
	delete sizeTree;
	delete extensionTree;
system("pause>0");
#ifdef _MSC_VER
#pragma warning(pop)
#endif
	return 0;
}