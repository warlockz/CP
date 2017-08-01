/*
 * dpt.cpp
 *
 *  Created on: 31-Jul-2017
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

int heightofbt(Node *root)
{
	if(root == NULL)
		return 0;
	else
	{
		int ltree = heightofbt(root->left);
		int rtree = heightofbt(root->left);

		if(ltree < rtree)
		{
			return (1 + ltree);
		}
		else
		{
			return (1 + rtree);
		}
	}
}

void printlevelnodes(Node *root,int level)
{
	if(root == NULL)
		return;
	if(level == 0)
	{
		cout << "[" << root->data << "]->";
	}
	else
	{
		//cout << "[" << root->data << "]->";
		printlevelnodes(root->left,level-1);
		printlevelnodes(root->right,level-1);
	}
}

void printbfs(Node *root)
{
	int height = heightofbt(root);
	for (int lvl = 0; lvl <= height ; ++lvl)
	{
		printlevelnodes(root,lvl);
	}
}

void printdfsinorder(Node *root)
{


}

int main(int argc, char **argv)
{
	Node *tree = newNode(1);
	tree->left = newNode(2);
	tree->right = newNode(3);
	tree->right->left  = newNode(4);
	tree->right->right = newNode(5);
	tree->left->left = newNode(6);
	tree->left->right = newNode(7);
	tree->left->left->right = newNode(8);
	tree->right->right->right = newNode(9);
	cout << "Height of tree is : "<<heightofbt(tree) <<endl;
	cout << "BFS printing nodes :";
	printbfs(tree);
	cout<<endl;
	return 0;
}
