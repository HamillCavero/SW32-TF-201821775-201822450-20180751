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
#include <cstdlib>
using namespace std;
using namespace std::experimental::filesystem;
namespace fs = std::experimental::filesystem;
using namespace std::chrono_literals;

class Book {
	string name;
	string nameFirst;
	string nameInv;
	int size;
	string extension; // good reads
	string timeupdate;
public:
	Book(string name,string nameFirst, string nameInv, int year, string score, string timeupdate)
		: name(name),nameFirst(nameFirst), nameInv(nameInv), size(year), extension(score), timeupdate(timeupdate) {}

	string getName() { return name; }
	string getNameFirst() { return nameFirst; }
	string getNameInv() { return nameInv; }
	int getSize() { return size; }
	string getExtension() { return extension; }
	string getTimeUpdate() { return timeupdate; }
	void setname(string name) { this->name = name; }
	void setnameFirst(string nameFirst) { this->nameFirst = nameFirst; }
	void setnameInv(string nameInv) { this->nameInv = nameInv; }
	void setyear(int year) { this->size = year; }
	void setscore(string score) { this->extension = score; }
	void setTimeupdate(string update) { this->timeupdate = update; }
};
typedef AVLTree<Book*, string, nullptr> TreeStr;
typedef AVLTree<Book*, string, nullptr> TreeStrFirst;
typedef AVLTree<Book*, string, nullptr> TreeStrInv;
typedef AVLTree<Book*, int, nullptr> TreeInt;
typedef AVLTree<Book*, string, nullptr> TreeFlt;
typedef AVLTree<Book*, string, nullptr>TreeUpdate;


string reverseStr(string& str)
{
	int n = str.length();
	for (int i = 0; i < n / 2; i++)
	{
		swap(str[i], str[n - i - 1]);
	}
	return str;
}
string primercaracter(string &str) 
{
   str = str.front();
	return str;

}

void llenararbol2(string ruta, string path2, string nameFirst, string path3, string path4, TreeStr* names, TreeStrFirst* namesFirst, TreeStrInv* namesInv, TreeInt* size, TreeFlt* extension, TreeUpdate* hora, uintmax_t valorpeso)
{
	auto ftime = last_write_time(ruta);
	std::time_t cftime = decltype(ftime)::clock::to_time_t(ftime); // assuming system_clock
	for (const auto & entry : directory_iterator(ruta)) {

		ftime = last_write_time(entry.path());

		cftime = decltype(ftime)::clock::to_time_t(ftime);

		path2 = entry.path().stem().string();
		path3 = entry.path().extension().string();
		valorpeso = file_size(entry.path());
		path4 = path2;
		path4 = reverseStr(path4);
		path4 = primercaracter(path4);
		nameFirst = path2;
		nameFirst = primercaracter(nameFirst);
		Book* name = new Book(path2,nameFirst, path4, valorpeso, path3, asctime(localtime(&cftime)));
		names->add(name);
		namesFirst->add(name);
		namesInv->add(name);
		size->add(name);
		extension->add(name);
		hora->add(name);
	}
}

int main()
{
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4996)
#endif
	int opc = 0;
	int pesoporusuario = 0;
	int orden=0;
	int selección = 0;
	string ruta = "";
	/*string str = "kkdeprro";*/
	string reversename = "";
	string letrabuscar = "";
	string nombrebuscar = "";
	uintmax_t valorpeso = 0;
	float pesoarchivo = 0.0;
	Menu(opc);
	auto l1 = [](Book* a) { return a->getName(); };
	auto l12 = [](Book* a) { return a->getNameFirst(); };
	auto l11 = [](Book* a) { return a->getNameInv(); };
	auto l2 = [](Book* a) { return a->getSize(); };
	auto l3 = [](Book* a) { return a->getExtension(); };
	auto l4 = [](Book*a) {return a->getTimeUpdate(); };
	TreeStr* nameTree = new TreeStr(l1);
	TreeStr* nameTreeInv = new TreeStrInv(l11);
	TreeStr* nameTreeFirst = new TreeStrFirst(l12);
	TreeInt* sizeTree = new TreeInt(l2);
	TreeFlt* extensionTree = new TreeFlt(l3);
	TreeUpdate* time = new TreeUpdate(l4);

	string path1 = "";  // . es la careta del programa // investigar c++files system
	string path2 = "";
	string path3 = "";
	string path4 = "";
	string nameFirst = "";
	string valorUserInputSTR = "";
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
		else 
		{
			cout << "Not found\n";
		}
	};
	auto prnt2 = [](Book* a)
	{

		if (a != nullptr)
		{
			cout << "{"
				<< a->getNameInv() << ","
				<< a->getSize() << ","
				<< a->getExtension() << ","
				<< a->getTimeUpdate() << "\n";

		}
		else {
			cout << "Not found\n";
		}
	};
	auto prnt3 = [](Book* a)
	{

		if (a != nullptr)
		{
			cout << "{"
				<< a->getName() << ","
				<< a->getSize() << ","
				<< a->getExtension() << ","
				<< a->getTimeUpdate() << "\n";

		}
		else
		{
			cout << "Not found\n";
		}
	};
	auto prntcontiene = [valorUserInputSTR](Book *a)
	{
		if (a->getName().find(valorUserInputSTR) != string::npos)
		{
			cout << "{ "
				<< a->getName() << " | "
				<< a->getExtension() << " | "
				<< a->getTimeUpdate() << " | "
				<< a->getSize() << " bytes | ";
		}
		else 
		{
			cout << "Not found \n";
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
			llenararbol2(ruta, path2, nameFirst, path3, path4, nameTree, nameTreeFirst, nameTreeInv, sizeTree, extensionTree, time, valorpeso);
			Menu2(opc);
		}
		break;
		case 2:
		{
			cout << "Nombre archivo:" << endl;
			nameTree->inorder(prnt);
			cout << "-----------------------==\n";
			cout << "Peso archivo:" << endl;
			sizeTree->inorder(prnt);
			cout << "-----------------------==\n";
			cout << "Extensión:" << endl;
			extensionTree->inorder(prnt);
			cout << "-----------------------==\n";
			cout << "Time Update: " << endl;
			cout << "-----------------------==\n";
			time->inorder(prnt);

			system("pause>0");
			system("cls");
			Menu2(opc);
		}
		break;
		case 3:
		{ int selec = 0;
		cout << "Ingrese por que caracteristica desea buscar:" << endl;
		cout << "1 =Name , 2=Peso , 3= extension" << endl;
		cin >> selec;
		switch (selec)
		{
		case 2:
			cout << "Ingrese el peso buscado: "; cin >> pesoarchivo;
			cout << endl;
			cout << "---------------------------------" << endl;
			prnt(sizeTree->find(pesoarchivo));
			cout << "--------------------------" << endl;
			break;
		case 3:
			cout << "Ingrese la extensión a buscar: "; cin >> nombrebuscar;
			cout << endl;
			cout << "---------------------------------" << endl;
			prnt(extensionTree->find(nombrebuscar));
			cout << "--------------------------" << endl;
			break;
		case 1:
			cout << "Ingrese el nombre a buscar: "; cin >> nombrebuscar;
			cout << endl;
			cout << "---------------------------------" << endl;
			prnt(nameTree->find(nombrebuscar));
			cout << "--------------------------" << endl;
			break;
		default:
			cout << "Ingrese otro valor:";
			break;

		}
		system("cls");
		Menu2(opc);
		}
		break;
		case 4:
		{
			cout << "Nombres Inversos: " << endl;
			nameTreeFirst->inorder(prnt3);
			cout << "-----------------------==\n";
			system("pause>0");
			system("cls");
			Menu2(opc);
		}
		break;
		case 5:
		{
		cout << "Ingrese busqueda por primera letra(1) o última letra(0): "; cin >> selección;
		switch (selección)
		{
		case 1:
			cout << "Ingrese la primera letra para buscar: " << endl; cin >> letrabuscar;
			prnt(nameTreeFirst->find(letrabuscar));
			break;
		case 0:
			cout << "Ingrese la ultima letra para buscar: " << endl; cin >> letrabuscar;
			prnt(nameTreeInv->find(letrabuscar));
			break;
		default:
			break;
		}
		Menu2(opc);
		break;
		case 6:
		{
			cout << "Ingrese el nombre de busqueda: "; cin >> valorUserInputSTR;
			cout << "Ingrese el peso del archivo:"; cin >> pesoporusuario;
			sizeTree->find2(pesoporusuario, prntcontiene);
			Menu2(opc);
		}
		case 7:
			cout << "Ingrese (1)Ascendente o (0) Descendente: "; cin >> orden;
			switch (orden)
			{
			case 1:
				cout << "Nombre archivo:" << endl;
				nameTree->inorder(prnt);
				cout << "-----------------------==\n";
				cout << "Peso archivo:" << endl;
				sizeTree->inorder(prnt);
				cout << "-----------------------==\n";
				cout << "Extensión:" << endl;
				extensionTree->inorder(prnt);
				cout << "-----------------------==\n";
				cout << "Time Update: " << endl;
				cout << "-----------------------==\n";
				time->inorder(prnt);
				break;
			case 0:
				cout << "Nombre archivo:" << endl;
				nameTree->postorden(prnt);
				cout << "-----------------------==\n";
				cout << "Peso archivo:" << endl;
				sizeTree->postorden(prnt);
				cout << "-----------------------==\n";
				cout << "Extensión:" << endl;
				extensionTree->postorden(prnt);
				cout << "-----------------------==\n";
				cout << "Time Update: " << endl;
				cout << "-----------------------==\n";
				time->postorden(prnt);
				break;

			default:
				cout << "Ingrese otro valor para orden:";
				cin >> orden;
				break;
			}
			system("cls");
			Menu2(opc);
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
	}
	
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
	delete nameTreeInv;
	delete time;
	delete sizeTree;
	delete extensionTree;
system("pause>0");
#ifdef _MSC_VER
#pragma warning(pop)
#endif
	return 0;
}