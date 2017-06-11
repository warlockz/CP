/*
 * design-and-implement-special-stack-data-structure_with_all_oper_BigO1.cpp
 *
 *  Created on: 9 Jun 2017
 *      Author: yogeshb2
 */

#include <iostream>
#include <stack>

using namespace std;
//template<class T>
template<typename T>
class SpecialStack
{
	stack<T> actual;
	stack<T> min_aux;
	public:
		int pop()
		{
			int val = -1;
			if(!isEmpty())
			{
				val = actual.top();
				actual.pop();
				min_aux.pop();
			}
			return (val);
		}
		void push(T data)
		{
			if(isEmpty())
			{
				min_aux.push(data);
				actual.push(data);
			}
			else
			{
				if(data < min_aux.top())
				{
					int temp = min_aux.top();
					min_aux.pop();
					min_aux.push(data);
				}
				actual.push(data);
			}
		}
		int getmin()
		{
			if(!isEmpty())
			return (min_aux.top());
			return (-1);
		}
		bool isEmpty()
		{
			return (actual.empty());
		}
		/*friend ostream& operator<<(ostream& os,SpecialStack<T> stk)
		{
			os<<"Stack Elements : \n";
			while(!stk.isEmpty())
			{
				os<<"["<<stk.pop()<<"]";
			}
			os<<"\n";
			return (os);
		}*/
};

ostream& operator<<(ostream& os,SpecialStack<int> stk)
{
	os<<"Stack Elements : \n";
	while(!stk.isEmpty())
	{
		os<<"["<<stk.pop()<<"]";
	}
	os<<"\n";
	return (os);

}



int main(int argc, char **argv)
{
	SpecialStack<int> stk;
	stk.push(5);
	stk.push(3);
	stk.push(0);
	stk.push(9);
	stk.push(57);
	cout<<stk;
	cout<<"Min val : "<<stk.getmin()<<"\n";
}
