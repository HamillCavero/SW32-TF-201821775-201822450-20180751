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

//string rndStr() 
//{
//	int n = 10 + rand() % 21;
//	stringstream ss;
//	for (int i = 0; i < n; ++i) {
//		ss << (char)('a' + rand() % 27);
//	}
//	return ss.str();
//}

int main() {
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4996)
#endif
	typedef AVLTree<Book*, string, nullptr> TreeStr;
	typedef AVLTree<Book*, int, nullptr> TreeInt;
	typedef AVLTree<Book*, string, nullptr> TreeFlt;
	typedef AVLTree<Book*, string, nullptr>TreeUpdate;

	auto l1 = [](Book* a) { return a->getName(); };
	auto l2 = [](Book* a) { return a->getSize(); };
	auto l3 = [](Book* a) { return a->getExtension(); };
	auto l4 = [](Book*a) {return a->getTimeUpdate(); };
	TreeStr* nameTree = new TreeStr(l1);
	TreeInt* sizeTree = new TreeInt(l2);
	TreeFlt* extensionTree = new TreeFlt(l3);
	TreeUpdate* time = new TreeUpdate(l4);

	auto ftime = last_write_time("C:\\Users\\USER\\Desktop\\FISICA LABORATORIO");
	std::time_t cftime = decltype(ftime)::clock::to_time_t(ftime); // assuming system_clock

	uintmax_t valorpeso;
	string path1 = "C:\\Users\\USER\\Desktop\\FISICA LABORATORIO";  // . es la careta del programa // investigar c++files system
	string path2 = "C:\\Users\\USER\\Desktop\\FISICA LABORATORIO";
	string path3 = "C:\\Users\\USER\\Desktop\\FISICA LABORATORIO";
	
	for (const auto & entry : directory_iterator(path1)) {
		//cout << entry.path() << endl;

		/*cout << path(entry.path()).filename() << endl;

		cout << file_size(entry.path()) << endl;

		cout << path(entry.path()).extension() << endl;
		*/
		ftime = last_write_time(entry.path());

		cftime = decltype(ftime)::clock::to_time_t(ftime);

		path2 = path(entry.path().filename()).u8string();

		path3 = path(entry.path().extension()).u8string();

		valorpeso = file_size(entry.path());
		Book* name = new Book(path2, valorpeso, path3, asctime(localtime(&cftime)));
		nameTree->add(name);
		sizeTree->add(name);
		extensionTree->add(name);
		time->add(name);
	}
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
	//cout << "ff"<<endl;
	//nameTree->innorden();
	cout << "---------------------" << endl;
	prnt(nameTree->find("f.txt"));
	/*prnt(sizeTree->find(2011));*/
	//prnt(scoreTree->find(4.5));
	cout << "---------------" << endl;
	/*string nombre;
	while (true)
	{

	cout << "Ingrese el nombre del archivo a buscar:" << endl; cin >> nombre;
	cout << "Buscando Archivo:" << endl;
	if (prnt(nameTree->find(nombre)) == true)
	{
	break;
	}
	};*/


	system("pause>0");
	delete nameTree;
	delete sizeTree;
	delete extensionTree;
#ifdef _MSC_VER
#pragma warning(pop)
#endif
	return 0;
}