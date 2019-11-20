#pragma once
#include <functional>

#define max(a, b) ( a > b? a : b )

using namespace std;

template <typename T, typename Comparable = T, T NONE = 0>
class AVLTree {
	struct Node {
		T elem;
		int   h;//altura
		int   n;
		Node* left;
		Node* right;

		Node(T elem)
			: elem(elem), left(nullptr), right(nullptr), h(0), n(1) {}
	};

	Node* root;
	int len;
	function<Comparable(T)> key;
	void(*procesar)(T);
	void destroy(Node* node)
	{
		if (node != nullptr) {
			destroy(node->left);
			destroy(node->right);
			delete node;
		}
	}
	Node* add(Node* node, T elem)
	{
		if (node == nullptr) {
			node = new Node(elem);
		}
		else {
			if (key(elem) < key(node->elem)) {
				node->left = add(node->left, elem);
			}
			else {
				node->right = add(node->right, elem);
			}
			node = balance(node);
		}
		return node;
	}
	T find(Node* node, Comparable val) {
		if (node == nullptr) {
			return NONE;
		}
		else if (val == key(node->elem)) {
			return node->elem;
		}
		else if (val < key(node->elem)) {
			return find(node->left, val);
		}
		else {
			return find(node->right, val);
		}
	}

	void inorder(Node* node, function<void(T)> proc) {
		if (node != nullptr) {
			inorder(node->left, proc);
			proc(node->elem);
			inorder(node->right, proc);
		}
	}
	void postorden(Node* node, function<void(T)> proc) {
		if (node != nullptr) {
	
			postorden(node->right, proc);
			proc(node->elem);
			postorden(node->left, proc);
	
		}
	}

	// BALANCEO!
	int height(Node* node) { return node == nullptr ? -1 : node->h; }
	int length(Node* node) { return node == nullptr ? 0 : node->n; }
	void update(Node* node)
	{
		node->h = 1 + max(height(node->left), height(node->right));
		node->n = 1 + length(node->left) + length(node->right);
	}
	Node* rotLeft(Node* node) {
		Node* aux = node->right;
		node->right = aux->left;
		aux->left = node;
		update(aux->left);
		update(aux);
		return aux;
	}
	Node* rotRight(Node* node) {
		Node* aux = node->left;
		node->left = aux->right;
		aux->right = node;
		update(aux->right);
		update(aux);
		return aux;
	}
	Node* balance(Node* node) {
		int hl = height(node->left);
		int hr = height(node->right);
		if (hl - hr > 1) {
			if (height(node->left->right) > height(node->left->left))
			{
				node->left = rotLeft(node->left);
			}
			node = rotRight(node);
		}
		else if (hl - hr < -1) {
			if (height(node->right->left) > height(node->right->right)) {
				node->right = rotRight(node->right);
			}
			node = rotLeft(node);
		}
		else {
			update(node);
		}
		return node;
	}
public:
	AVLTree(function<Comparable(T)> key = [](T a) {return a; })
		: root(nullptr), len(0), key(key) {}
	~AVLTree() {
		destroy(root);
	}
	int size() {
		return len;
	}
	void eliminar() 
	{
		destroy(root);
	}
	void add(T elem) {
		root = add(root, elem);
	}
	bool remove(Comparable val)
	{
		// Encontrar el nodo con elemento a eliminar
		Node* aux = root;
		Node* parent;
		bool left;
		while (aux != nullptr) {
			if (val == key(aux->elem)) break;
			parent = aux;
			if (val < key(aux->elem)) {
				left = true;
				aux = aux->left;
			}
			else {
				left = false;
				aux = aux->right;
			}
		}
		if (aux == nullptr) return false;
		if (aux->left == nullptr) {
			if (aux == root) root = aux->right;
			else if (left)   parent->left = aux->right;
			else             parent->right = aux->right;
			delete aux;
		}
		else {
			Node* aux2 = aux->left;
			while (aux2->right != nullptr) {
				parent = aux2;
				aux2 = aux2->right;
			}
			if (aux2 == aux->left) aux->left = aux2->left;
			else                   parent->right = aux2->left;
			aux->elem = aux2->elem;
			delete aux2;
		}
		return true;
	}
	T find(Comparable val)
	{
		return find(root, val);
	}

	// meh
	void inorder(function<void(T)> proc)
	{
		inorder(root, proc);
	}
	void postorden(function<void(T)> proc) 
	{
		postorden(root, proc);
	}
};