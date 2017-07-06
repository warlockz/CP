/*
 * Array_reverse.cpp
 *
 *  Created on: 1 Jun 2017
 *      Author: yogeshb2
 */

#include <iostream>

using namespace std;

void reverse(int arr[], int n)
{
	int temp;
	int mid = n/2;
	for (int i = 0; i < mid; ++i)
	{
		temp = arr[i];
		arr[i] = arr[--n];
		arr[n] = temp;
	}
}

void recursivereverse(int arr[],int s, int n)
{
	n--;
	int mid = n/2;
	if(s <= mid)
	{
		int temp = arr[s];
		arr[s] = arr[n];
		arr[n] = temp;
		s++;
		recursivereverse(arr,s,n);
	}
}


int main(int argc, char **argv)
{
	int arr[10] = {1, 2, 3, 4, 5};
	reverse(arr,5);

	cout << "Arr Reversde \n";
	for (int i = 0; i < 5; ++i)
	{
		cout << " " << arr[i];
	}
	cout << "\n";

	recursivereverse(arr,0,5);

	cout << "Arr Recursive Reversde \n";
	for (int i = 0; i < 5; ++i)
	{
		cout << " " << arr[i];
	}
	cout << "\n";


}



