#include <stdio.h>

typedef unsigned char byte;

void show_bytes(byte* bptr,int n)
{
	int i;
	for (i = 0; i < n; ++i,bptr++)
	{
		printf("%.2x ",*bptr);	
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int x = 1;
	show_bytes((byte*)&x,sizeof(int));
	return 0;
}