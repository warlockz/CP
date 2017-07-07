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

Node* minimumValueNode(Node *root)
{
	Node *cur = root;

	while(cur->left != NULL)
		cur = cur->left;
	return cur;
}

Node* deletenode(Node *root,int key)
{
	if(root == NULL) return root;
	
	if (key < root->data)
	{
		root->left = deletenode(root->left,key);
	}
	else if (key > root->data)
	{
		root->right = deletenode(root->right,key);
	}
	else
	{
		if (root->left == NULL)
		{
			Node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			Node *temp = root->left;
			free(root);
			return temp;
		}
		//Now the node to delete has two node so need to get inorder sucessor of the node 
		//and swap or copy that node contents then delete the found node
		Node *temp = minimumValueNode(root->right);
		root->data = temp->data;
		root->right = deletenode(root->right,temp->data);
	}
	return root;
}

void findPredecessorSuccessor(Node *root,Node*& pre,Node*& suc,int key)
{
	if (root == NULL)
	{
		return;
	}

	if (root->data == key)
	{
		//the maxm value is Predecessor of left subtree
		if (root->left != NULL)
		{
			Node *temp = root->left;;
			while(temp->right)
				temp = temp->right;
			pre = temp;
		}

		//the minm value is Successor of right subtree
		if (root->right != NULL)
		{
			Node *temp = root->right;
			while(temp->left)
				temp = temp->left;
			suc = temp;
		}
		return;
	}

	if (key < root->data)
	{
		pre = root;	
		findPredecessorSuccessor(root->left,pre,suc,key);
	}
	else
	{
		suc = root;
		findPredecessorSuccessor(root->right,pre,suc,key);
	}

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
	tree = insert(tree,10);
	insert(tree,2);
	insert(tree,3);
	insert(tree,1);
	insert(tree,15);
	insert(tree,12);
	insert(tree,11);
	insert(tree,13);
	insert(tree,20);
	insert(tree,18);
	insert(tree,17);
	insert(tree,23);
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
		cout << "Found : "<<temp->data<< "\n";
	}
	else
	{
		cout << "Not Found 10"<< "\n";
	}
	cout << "\n";
	tree = deletenode(tree,15);
	printinorderbst(tree);
	cout << "\n";
	deletenode(tree,11);
	printinorderbst(tree);
	cout << "\n";
	Node *pre = NULL ,*suc = NULL;
	findPredecessorSuccessor(tree,pre,suc,13);
	cout<<"Predecessor : "<<pre->data<<" Successor : "<<suc->data<<"\n";
	return 0;
}
