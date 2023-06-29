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

	void insert(string element) // Insert a node in the Binary Search Tree
	{
		Node* newNode = new Node(element, NULL, NULL); // step 1. Allocate memory for the new Node
	}

	void search(string element, Node*& parent, Node*& currentNode)
	{
		// This function searches the currentNode of the specified Node as well as the current Node of its parent
		currentNode = ROOT; // step 1. make a variable/pointer currentNode point to the ROOT node
		parent = NULL; // step 2. Make a variable/pointer parent point to NULL

		while ((currentNode != NULL) && (currentNode->info != element)) // step 3. repeats a, b, c until currentNode =NULL or node to be searches = currentNode
		{
			parent = currentNode;// 3a
			if (element < currentNode->info) // 3b
				currentNode = currentNode->leftChild;
			else // 3c
				currentNode = currentNode->rightChild;
		}
	}
};