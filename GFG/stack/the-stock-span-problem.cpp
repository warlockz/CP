#include <iostream>
#include <stack>
using namespace std;

//Ineffienct Method without using Stack Time complemixity = O(n^2)
void CalculateSpan(int price[],int S[],int n)
{
	S[0] = 1; //since 1st no need tocheck

	for (int i = 1; i < n; ++i)
	{
		S[i] = 1;
		for (int j = i-1 ; ((j >= 0) && price[i] >= price[j]); j--)
		{
			S[i]++;
		}
	}
	
}

//Efficient Method using stack
void CalculateSpanEff(int price[],int S[],int n)
{
	stack<int> stk;
	stk.push(0);// Pushing 1st element
	S[0] = 1;

	for (int i = 1; i < n; ++i)
	{
		//check whether all elemnets before indexed i is greater than or before elemnts
		// is less than or equal then pop stack
		while((!stk.empty()) && (price[stk.top()] <= price[i]))
		stk.pop();
		//if stack is empty then all elemnts is <= then assign no.of elemnts
		//traversed else travesed minus the the stack top elemnt
		S[i] = (stk.empty())? (i + 1) : (i - stk.top());
		//Now push the current index to check for next itern
		stk.push(i);
	}
}
/*
Time Complexity: O(n). It seems more than O(n) at first look. 
If we take a closer look, we can observe that every element of array 
is added and removed from stack at most once.
 So there are total 2n operations at most. 
 Assuming that a stack operation takes O(1) time,
  we can say that the time complexity is O(n).

Auxiliary Space: O(n) in worst case when all elements are sorted 
in decreasing order.
*/

void printArr(int S[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << S[i] << " ";
	}	
	cout << "\n";
}

int main(int argc, char const *argv[])
{
	int arr[] = {10, 4, 5, 90, 120, 80};
	int n = sizeof(arr)/sizeof(arr[0]);
	int S[n];
	//CalculateSpan(arr,S,n);
	CalculateSpanEff(arr,S,n);
	printArr(S,n);
	return 0;
}