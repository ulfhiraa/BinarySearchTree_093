#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	string info;
	Node* leftChild;
	Node* rightChild;

	// constructor for the node Class
	Node(string i, Node* l, Node* r)
	{
		info = i;
		leftChild = l;
		rightChild = r;
	}
};

class BinaryTree
{
public:
	Node* ROOT;

	BinaryTree()
	{
		ROOT = NULL; // intializing ROOT to NULL
	}
};