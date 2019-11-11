#pragma once
template <class T>
struct Node 
{
	T key;
	struct Node* left;
	struct Node* right;
	int height; //LA ALTURA
	Node()
	{
		left = nullptr;
		right = nullptr;
		height = 0;
	}
};