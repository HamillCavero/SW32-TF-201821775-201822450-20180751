#include<iostream>
#include<ctime>
#include<filesystem>
#include <chrono>
#include <iomanip>
#include "arbolAVL.h"
#include<Windows.h>
#include<vector>
#include <string>
#include<functional>
using namespace std;
using namespace std::experimental::filesystem;
namespace fs = std::experimental::filesystem;

using namespace std::chrono_literals;
void imprimir(int e)
{
	cout << " , " << e;
}
void imprime(string p)
{
	cout << " , " << p;
}
class Libreta 
{
	string name;
	int size;
	string extension; // good reads
	string timeupdate;
public:
	Libreta(string name, int size, string exte, string timeupdate)
		: name(name), size(size), extension(exte), timeupdate(timeupdate) {}

	string getName() { return name; }
	int getSize() { return size; }
	string getExtension() { return extension; }
	string getTimeUpdate() { return timeupdate; }
	//void setname(string name) { this->name = name; }
	//void setyear(int year) { this->size = year; }
	//void setscore(string score) { this->extension = score; }
	//void setTimeupdate(string update) { this->timeupdate = update; }

};
///------
int main() {
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4996)
#endif
	ArbolAVL<int>* sizefile;
	ArbolAVL<string>*  extension;
	ArbolAVL<string>* filename;
	ArbolAVL<string>* timeupdate;

	sizefile = new ArbolAVL<int>(imprimir);
	filename = new ArbolAVL<string>(imprime);
	extension = new ArbolAVL<string>(imprime);
	timeupdate = new ArbolAVL<string>(imprime);





	uintmax_t valorpeso;
	auto ftime = last_write_time("C:\\Users\\USER\\Desktop\\FISICA LABORATORIO");

	std::time_t cftime = decltype(ftime)::clock::to_time_t(ftime); // assuming system_clock

	string path1 = "C:\\Users\\USER\\Desktop\\FISICA LABORATORIO";  // . es la careta del programa // investigar c++files system
	string path2 = "C:\\Users\\USER\\Desktop\\FISICA LABORATORIO";
	string path3 = "C:\\Users\\USER\\Desktop\\FISICA LABORATORIO";

	for (const auto & entry : directory_iterator(path1)) {
		/*	cout << entry.path() << endl;

		cout << path(entry.path()).filename() << endl;*/

		/*	path2 = path(entry.path()).filename();

		cout << file_size(entry.path()) << endl;

		cout << path(entry.path()).extension() << endl;*/

		ftime = last_write_time(entry.path());

		cftime = decltype(ftime)::clock::to_time_t(ftime);

		path2 = path(entry.path().filename()).u8string();

		path3 = path(entry.path().extension()).u8string();

		valorpeso = file_size(entry.path());

		Libreta* libreta = new Libreta(path2, valorpeso, path3, asctime(localtime(&cftime)));

		sizefile->insertar(libreta->getSize());

		filename->insertar(libreta->getName());

		extension->insertar(libreta->getExtension());

		timeupdate->insertar(libreta->getTimeUpdate());
	}

	cout << "Peso de Archivos:" << endl;
	cout << "------------------" << endl;
	sizefile->inOrder();
	cout << "\n";
	cout << "---------------------";
	cout << "\n";
	cout << "Nombre archivos:" << endl;
	cout << "-----------------------" << endl;
	filename->inOrder();
	cout << "\n";
	cout << "------------------------";
	cout << "\n";
	cout << "Extension:" << endl;
	cout << "--------------------" << endl;
	extension->inOrder();
	cout << "\n";
	cout << "Fecha Time Update:" << endl;
	cout << "--------------------" << endl;
	timeupdate->inOrder();
	cout << "\n";
	system("pause");
#ifdef _MSC_VER
#pragma warning(pop)
#endif
	return 0;
}