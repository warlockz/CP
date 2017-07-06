/*
 * ipvalid.c
 *
 *  Created on: 25 May 2017
 *      Author: yogeshb2
 */
#include <stdio.h>
#include <string.h>

#define DELIM "."

int isNumeric(char *c)
{
	int flag = 0;
	while(*c)
	{
		if((*c >= '0') && (*c <= '9'))
		{
			flag = 1;
		}
		else
		{
			flag = 0;

		}
		++c;
	}
	return flag;
}

int isIPRangeValid(int num)
{
	//printf("isIPRangeValid %d : \n",num);
	if((num >= 0) && (num <= 255))
	{
		return 1;
	}
	return 0;
}

int isValidIP4(char *str)
{
	int count = 0;
	char *token = strtok(str,DELIM);
	while(token != NULL)
	{
		//printf("isValidIP4 = %s cnt = %d \n",token,count);
		if(!isNumeric(token))
		{
			break;
		}
		if(isIPRangeValid(atoi(token)))
		{
			count++;
		}
		token = strtok(NULL,DELIM);
	}

	if(count == 4)
	{
		return 1;
	}

	return 0;
}

void printInfo(int isValid,int ipind)
{
	if(isValid)
	{
		printf("ip is valid ip %d\n",ipind);
	}
	else
	{
		printf("ip is not valid ip %d\n",ipind);
	}

}

int main(int argc, char **argv)
{
	static int ipindex;
	char ip[] = "122.112.11.01";
	char ip2[] = "122.112.11";

	printf("Checking IP : \n");

	printInfo(isValidIP4(ip),++ipindex);
	printInfo(isValidIP4(ip2),++ipindex);

	return 0;
}






