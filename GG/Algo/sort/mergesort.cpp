/*
 * mergesort.cpp
 *
 *  Created on: 20 Jul 2017
 *      Author: yogeshb2
 */

#include <iostream>

using namespace std;

void merge(int arr[],int low,int mid,int high)
{
	int n1 = mid - low + 1;
	int n2 = high - mid;
	int i = 0,j = 0,L[n1],R[n2];
	//copy elements into separate arr

	for (i = 0; i < n1; ++i)
	{
		L[i] = arr[low+i];
	}

	for (j = 0; j < n2; ++j)
	{
		R[j] = arr[mid+1+j];
	}

	i = j = 0;
	int k = low;
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i++];
		}
		else
		{
			arr[k] = R[j++];
		}
		k++;
	}

	while(i < n1)
	{
		arr[k] = L[i++];
		k++;
	}

	while(j < n2)
	{
		arr[k] = R[j++];
		k++;
	}
}

void mergesort(int arr[],int l,int r)
{
	if(l < r)
	{
		int mid = (l + (r-l)/2);// same as (l+r)/2
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

void iterativemergesort(int a[],int l, int r)
{


}

int main(int argc, char **argv)
{
	int arr[] = {10,19,2,100,2,8,4,3};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "Sorted Elements : \n";
	for (int i = 0; i < size; ++i)
	{
		cout <<" "<< arr[i];
	}
	cout << "\n";
	mergesort(arr,0,size-1);
	cout << "Sorted Elements : \n";
	for (int i = 0; i < size; ++i)
	{
		cout <<" "<< arr[i];
	}
	cout << "\n";
	return 0;
}




