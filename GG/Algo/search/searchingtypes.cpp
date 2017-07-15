#include <iostream>

using namespace std;


// Time Complexity : O(n)
int linearsearch(int arr[],int n,int x)
{
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == x)
		{
			return 1;
		}
	}
	return (-1);
}

// Time Complexity : O(Log n)
int binarysearchrec(int arr[],int l,int h,int x)
{
	if(l <= h)
	{
		int mid = (l+h)/2;
		if (arr[mid] == x)
		{
			return 1;
		}
		else if(arr[mid] < x)
		{
			return binarysearchrec(arr,l,mid + 1,x);
		}
		else 
		{
			return binarysearchrec(arr,l,mid - 1,x);
		}
	}
	return -1;
}

// Time Complexity : O(Log n)
// Auxillary Space : O(1) in case of iterative solution
int binarysearch(int arr[],int l,int h,int x)
{
	while(l <= h)
	{
		int mid = (l+h)/2;
		if (arr[mid] == x)
		{
			return 1;
		}
		else if(arr[mid] < x)
		{
			l = mid + 1;
		}
		else 
		{
			h = mid - 1;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int arr[] = {10,11,12,13,14,15,16,17,18,20};
	int x;
	cout << "Please enter the elemnt to search ? : \n";
	cin >> x;
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "Linear Search element Found : " << linearsearch(arr,size,x) << "\n";
	cout << "Binary Search element Found : " << binarysearch(arr,0,size-1,x) << "\n";
	cout << "Binary Search Rec element Found : " << binarysearch(arr,0,size-1,x) << "\n";
	return 0;
}