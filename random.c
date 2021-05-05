#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "random.h"

void print_random()
{	
        puts("function random");
}

int main()
{
	
	FILE *text1, *text2;
	srand(time(NULL));
	char chars[] = "abcdefghijklmnopqrstuvwxyz";
        int nchars = strlen(chars);
	text1=fopen("dataset1.txt", "w");
	text2=fopen("dataset2.txt", "w");
	if((text1==NULL)||(text2==NULL))
	{
		printf("Error");
		return (-1);
	}
	for(int i=0;i<1000000;i++)
	{
		fprintf(text1, "%d\n", (int)rand());
        	for (int j = 0; j < 100; j++)
        		fputc(chars[(int) ((rand() / ((double) RAND_MAX + 1)) * nchars)], text2);
		fputs("\n", text2);
		
	}	
	fclose(text1);
	fclose(text2);
	return 0;
}
