#pragma once
#include "NodoAVL.h"

template<class T>
class ArbolAVL 
{
private:
	Node<T>* raiz;
	void(*procesar)(T);
	//---
	int max(int a, int b) {
		return (a > b ? a : b);
	}
	//---
	int _altura(Node<T>* nodo) {
		if (nodo == nullptr) return -1;
		return nodo->height;
	}
	//---
	bool _insertar(Node<T>*& nodo, T e) {
		if (nodo == nullptr) {
			nodo = new Node<T>();
			nodo->key = e;
		}
		else if (e < nodo->key) {
			_insertar(nodo->left, e);
		}
		else if (e >= nodo->key) {
			_insertar(nodo->right, e);
		} 
		//===============================================================
		//INI_DE_BALANCEO
		int hi = _altura(nodo->left);
		int hd = _altura(nodo->right);
		int d = hd - hi;
		if (d > 1) {//pesado a la derecha
			int hni = _altura(nodo->right->left);
			int hnd = _altura(nodo->right->right);
			if (hni > hnd) { //zig zag derecha izquierda
				_rotarDer(nodo->right->left, nodo->right, nodo->right);
			}
			_rotarIzq(nodo, nodo->right, nodo);
		}
		else if (d < -1) { //pesado a la izquierda
			int hni = _altura(nodo->left->left);
			int hnd = _altura(nodo->left->right);
			if (hnd > hni) {//zig zag derecha izquierda
				_rotarIzq(nodo->left, nodo->left->right, nodo->left);
			}
			_rotarDer(nodo->left, nodo, nodo);
		}
		//FIN_DE_BALANCEO
		//===============================================================
		hi = _altura(nodo->left);
		hd = _altura(nodo->right);
		nodo->height = 1 + ((hi > hd) ? hi : hd);
		return true;
	}
	//---
	//p is paren of x
	void _rotarDer(Node<T>*& x, Node<T>* y, Node<T>*& p) {
		p = x;
		y->left = x->right;
		p->right = y;
	}
	//---
	//p is paren of x
	void _rotarIzq(Node<T>* x, Node<T>*& y, Node<T>*& p) {
		p = y;
		x->right = y->left;
		p->left = x;
	}
	//---
	void _inOrder(Node<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrder(nodo->left);
		procesar(nodo->key);
		_inOrder(nodo->right);
	}
public:
	ArbolAVL(void(*pf)(T))
	{
		this->procesar = pf;
		raiz = nullptr;
	}
	//----
	void insertar(T e) 
	{
		_insertar(raiz, e);
	}
	//---
	void inOrder() {
		_inOrder(raiz);
	}
};