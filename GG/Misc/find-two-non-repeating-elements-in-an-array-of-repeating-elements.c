#include <stdio.h>
#include <malloc.h>


void get2NonRepatingNos(int a[],int n,int *x, int *y)
{
	int totalxor = a[0];
	int i,setbitno;
	*x = 0;
	*y = 0;
	for ( i = 1; i < n; ++i)
	{
		totalxor = totalxor ^ a[i];
	}
	//to get rightmost set bit no.
	setbitno = (totalxor & ~(totalxor-1));

	printf("set bit no = %d \n", setbitno);
	for (i = 0; i < n; ++i)
	{
		if (setbitno & a[i])
		{
			*x = *x ^ a[i];
		}
		else
		{
			*y = *y ^ a[i];
		}

		printf("cur >> x = %d y =%d \n", *x, *y);
	}


}


int main(int argc, char const *argv[])
{
	int a[] = {3, 14, 4, 5, 5, 4, 3, 7};

	int *x = (int*)malloc(sizeof(int));
	int *y = (int*)malloc(sizeof(int));

	get2NonRepatingNos(a,8,x,y);

	printf("x = %d y =%d \n", *x, *y);
	
	return 0;
}