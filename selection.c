#include<stdio.h>
#include"swap.c"

#define MAXSIZE 7

long int count;

void print(int arr[]){
	for(int i=0; i<count; i++)
	       printf("%d ",arr[i]);
	printf("\n\n");
}	

int *Rselection(int arr[],int i){
	if(i>count)
		return arr;
	else	{
		int min = i;
        int j;
		for(j = i+1; j<count-1; j++)
			if(arr[j]<arr[min])
                min = j;
            print(arr);
            if(min != i)
			    swap(&arr[min],&arr[i]);	
		//calling function
		Rselection(arr,++i);
	}
}

int selection(int arr[]){
    int min;
	int i =0,j=0;

	for(i = 0; i<count-1; i++){
		min = i;
		for(j=i+1; j<count; j++)
        	if(arr[j] < arr[min])
				min = j;
            if(min != i)
			    swap(&arr[min],&arr[i]);
            print(arr);
	}
} 

int main(){
	int arr[] = {64,25,0,12,22,11,1,70};
    count = sizeof(arr)/sizeof(arr[0]);

    print(arr);

	
    selection(arr);
    Rselection(arr,0);
    
    print(arr);
}
