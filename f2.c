#include <stdio.h>
#include <sys/time.h>
#include "f2.h"

void print_f2(){
    puts("function f2");
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;     
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
   
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
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
	mergeSort(x, 0, 1000000);
	gettimeofday(&end,NULL);
	printf("the time is:%ld\n", 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec);	
	return 0;
}
