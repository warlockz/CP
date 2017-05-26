#include <stdio.h>

#define GETSIZE(x)  (size_t)((char*)(&x+1) - (char*)&x)

#define OFFSET(x,y)	((size_t)&(((x*)0)->y))

typedef struct apple
{
	int no;
	char seed;
}apple;

int main()
{
	int i = 10;
	double d;
	printf("My size of i = %d  and d = %d\n",GETSIZE(i),GETSIZE(d));
	printf("Apple = %d ",OFFSET(apple,seed));
	return 0;
}