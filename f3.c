#include <stdio.h>
#include <sys/time.h>
#include "f3.h"

void pirnt_f3(){
    puts("function f3");
}
int findLargestNum(int * array, int size){
  
  int i;
  int largestNum = -1;
  
  for(i = 0; i < size; i++){
    if(array[i] > largestNum)
      largestNum = array[i];
  }
  
  return largestNum;
}

void radixSort(int * array, int size){  
  int i;
  int semiSorted[size];
  int significantDigit = 1;
  int largestNum = findLargestNum(array, size);
  
  while (largestNum / significantDigit > 0){  
    int bucket[10] = { 0 };
    for (i = 0; i < size; i++)
      bucket[(array[i] / significantDigit) % 10]++;
    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];
    for (i = size - 1; i >= 0; i--)
      semiSorted[--bucket[(array[i] / significantDigit) % 10]] = array[i];
    for (i = 0; i < size; i++)
      array[i] = semiSorted[i];
    significantDigit *= 10;
  }
}
int main()
{
	FILE *fp;
	struct timeval start;
	struct timeval end;
	int x[1000000];
	fp = fopen("dataset1.txt", "r");
	if(fp==NULL)
	{
		printf("error\n");
		return (-1);
	}
	for(int i=0; i<1000000; i++)
		fscanf(fp, "%d", &x[i]);

	gettimeofday(&start,NULL);
	radixSort(x, 1000000);
	gettimeofday(&end,NULL);
	printf("the time is:%ld\n", 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec);	
	return 0;
}
