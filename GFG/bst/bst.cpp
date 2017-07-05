/*
 * bst.cpp
 *
 *  Created on: 5 Jul 2017
 *      Author: yogeshb2
 */
#include <iostream>
#include <malloc.h>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node* newNode(int data)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

Node* insert(Node *root,int key)
{
	if(root == NULL)
		return (newNode(key));
	else
	{
		if(key < root->data)
		{
			root->left = (insert(root->left,key));
		}
		else
		{
			root->right = (insert(root->right,key));
		}
	}
	return root;
}

Node* search(Node *root,int key)
{
	if((root == NULL) || (root->data == key))
		return root;
	else
	{
		if(key < root->data)
			return (search(root->left,key));
		else
			return (search(root->right,key));
	}
}

Node* deletenode(Node *root,int key)
{


}

void printinorderbst(Node *root)
{
	if(root == NULL)
		return;
	else
	{
		printinorderbst(root->left);
		cout<<"->"<< root->data;
		printinorderbst(root->right);
	}
}

int main(int argc, char **argv)
{
	Node *tree = NULL;
	tree = insert(tree,1);
	insert(tree,2);
	insert(tree,3);
	insert(tree,4);
	insert(tree,5);
	cout << "Printing BST :  \n";
	printinorderbst(tree);
	cout << "\n";
	cout << "Searching : Node 4: \n";
	Node *temp = search(tree,4);
	if(temp)
	{
		cout << "Found : "<<temp->data << "\n";
	}
	else
	{
		cout << "Not Found 4"<< "\n";
	}
	cout << "Searching : Node 10: \n";
	temp = search(tree,10);
	if(temp)
	{
		cout << "Forund : "<<temp->data<< "\n";
	}
	else
	{
		cout << "Not Found 10"<< "\n";
	}

	return 0;
}
