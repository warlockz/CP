#include <iostream>

using namespace std;

int bins(int arr[],int low,int high, int key)
{
	int n = high;
	int mid = 0;
	int position = -1;
	while(low <= high)
	{
		mid = (low + high)/2;
		if(arr[mid] == key)
		{
			position = mid;
			break;
		}
		else if(arr[mid] < key)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return position;
}


int main()
{

	int arr[] = {1 , 2, 3, 4 ,5, 6, 7,8,9,10,11,12,13};
	int key = -1;
	cin >> key;
	int pos = bins(arr,0,13,key);
	cout << "Ele f : \n"<< pos <<endl;
	return 0;
}
