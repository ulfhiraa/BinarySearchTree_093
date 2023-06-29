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
		newNode->info = element; //step 2. Assign value to the data field of the new Node
		newNode->leftChild = NULL; // step 3. Make the left and right child of the new Node point to NULL
		newNode->rightChild = NULL;

		Node* parent = NULL;
		Node* currentNode = NULL;
		search(element, parent, currentNode); // step 4. Locate the node which will be the parent of the node to be inserted

		if (parent == NULL) // step 5. If the parent is NULL (Tree is empty)
		{
			ROOT = newNode; // 5a. Mark the new Node as ROOT
			return; // step 5b. exit 
		}

		if (element < parent->info) // step 6. if the value in the data field of the new Node is less than that of parent
		{
			parent->leftChild = newNode; // 6a. make the left child of the parent point to the new Node
		}
		else if (element > parent->info) // step 7. if the value in the data field of the new Node is greater than that of the parent
		{
			parent->rightChild = newNode; // 7a. make the right child of the parent point to the new Node 
		}
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

	//traversing
	void inorder(Node* ptr) // cara pertama
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			inorder(ptr->leftChild);
			cout << ptr->info << " ";
			inorder(ptr->rightChild);
		}
	}

	void preorder(Node* ptr) // cara kedua
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}

		if (ptr != NULL)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftChild);
			preorder(ptr->rightChild);
		}
	}

	void postorder(Node* ptr) // cara ketiga
	{
		// performs the postorder traversal of the tree
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			postorder(ptr->leftChild);
			postorder(ptr->rightChild);
			cout << ptr->info << " ";
		}
	}
};

int main()
{
	BinaryTree obj;
}