#include <iostream>
#include <stack>

using namespace std;

void printNGE(int arr[],int n)
{

	stack<int> s;
	int element, next;

	s.push(arr[0]);
	next = -1;

	for (int i = 1; i < n; ++i)
	{
		next = arr[i];
		if (!s.empty())
		{
			element = s.top();
			s.pop();

			while(next > element)
			{
				cout << "Element : "<<element <<"---->" <<next <<"\n";
				if(s.empty())
				break;
				element = s.top();
				s.pop();
			}

			if(element > next)
			s.push(element);
		}

		s.push(next);
	}

	while(!s.empty())
	{
		element = s.top();
		s.pop();	
		next = -1;
		cout << "Element : "<<element <<"---->" <<next <<"\n";
	}

}

int main(int argc, char const *argv[])
{
	int arr[] = {13,7,6,12};
	//int arr[] = {1,1,1};
	int size = sizeof(arr)/sizeof(arr[0]);
	printNGE(arr,size);
	return 0;
}