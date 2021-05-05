#include <stdio.h>
#include <sys/time.h>
#include "f1.h"

void print_f1()
{
	puts("function f1");
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int *arr, int front, int end){
    int pivot = arr[end];
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}
void QuickSort(int *arr, int front, int end){
    if (front < end) {
        int pivot = Partition(arr, front, end);
        QuickSort(arr, front, pivot - 1);
        QuickSort(arr, pivot + 1, end);
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
	QuickSort(x, 0, 1000000);
	gettimeofday(&end,NULL);
	printf("the time is:%ld\n", 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec);	
	return 0;
}

