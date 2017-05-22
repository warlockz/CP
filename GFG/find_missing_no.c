#include <stdio.h>


int getMissingNoMethod1(int a[],int n)
{
	int i;
	int total = (n + 1)*(n + 2) / 2;

	for (i = 0; i < n; ++i)
	{
		total -= a[i];
	}

	return total;	
}


int getMissingNoMethod2(int a[],int n)
{
	int i;
	int x1 = a[0];
	int x2 = 1;

	for (int i = 1; i < n; ++i)
	{
		x1 = x1 ^ a[i];	
	}
	
	for (int i = 2; i <= (n+1); ++i)
	{
		x2 = x2 ^ i;
	}

	return (x1 ^ x2);	
}



int main(int argc, char const *argv[])
{
	int arr[] = {1, 2, 3, 5};
	int miss = 0;

	miss = getMissingNoMethod1(arr,4);
	printf("The missing no is = %d\n",miss );
	miss = getMissingNoMethod2(arr,4);
	printf("The missing no is = %d\n",miss );
	return 0;
}