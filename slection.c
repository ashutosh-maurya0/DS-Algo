#include<stdio.h>
#include"swap.c"

#define MAXSIZE 7

void print(int arr[]){
	for(int i=0; i<MAXSIZE-1; i++)
	       printf("%d ",arr[i]);
	printf("\n\n");
}	

int *Rselection(int arr[],int i){
	if(i<MAXSIZE-1)
		return arr;
	else	{
		int min = i;
		for(int j = i+1; j<MAXSIZE; j++)
			if(arr[min]>arr[j])
				swap(&arr[min],&arr[j]);	
		//calling function
		Rselection(arr,++i);
	}
}

int main(){
	int arr[] = {1,5,2,9,7,0,4};
	int n = 7;
	int min;
	int i =0,j=0;

	for(i = 0; i<n-1; i++){
		min = i;
		for(j=i+1; j<n; j++)
			if(arr[j] < arr[min])
				min = j;
			if(min != i) {
			//int temp = arr[min];
			//arr[min] = arr[i];
			//arr[i]   = temp;
			swap(&arr[min],&arr[i]);
		}
	}

	print(arr);
}
