#include<stdio.h>
#include<stdlib.h>


void print(int arr[], int size){
    int counter =0;
    while(counter < size){
        printf("%d  ",arr[counter]);
        counter++;
    }
    printf("\n\n");    
}

int swap(int *num1, int *num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int *selection(int arr[], int size){
    int min;
	int i =0;
    int j=0;

	for(i = 0; i<size-1; i++){
		min = i;
		for(j=i+1; j<size; j++)
        	if(arr[j] < arr[min])
				min = j;
            if(min != i)
			    swap(&arr[min],&arr[i]);
            //print(arr, );
	}
}

int *insertion(int arr[], int size){
    int i =0;
    int v = 0;
    int j = i-1;

    for(i=1; i<=size-1;i++){
        v = arr[i];
        j = i-1;
        while((j>=0) && (arr[j]>v)){
            arr[j+1] = arr[j];
            j = j-1;
            arr[j+1] = v;    
        }
    }
    return arr;
}

int main(int argc, char *argv[]){
    printf("%d\n",argc);
    if(argc<2){
        printf("You did not feed me argument, I will die now :(....\n\n");
        exit(1);
    } //otherwise continue on our merry way....

    int size = atoi(argv[1]);      //argv[0] is the program name
                                
    //Lets get a-crackin!
    int arr[size];
    for(int i=0; i<size-1;i++)
        arr[i] = 0;
    
    //menu driver
    int ch;
    
    while(1){
        printf("     MENU");
        printf("\n1.Selection\n2.Insertion\n3.Random Number Init\n4.Init manually\n5.change size\n6.Print elements of array\n\n");
        printf("Enter the choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("Selection Sort\n\n");
                    selection(arr,size);
                    print(arr,size);
                    break;
            case 2: printf("Insertion Sort\n\n");
                    insertion(arr,size);
                    print(arr,size);
                    break;
            case 3: printf("Random array: ")    ;
                    for(int i = 0; i<size-1; i++){
                        arr[i] = (rand()%60);
                    }
                    print(arr,size);
                    break;
            case 4://initialize value
                    printf("Enter the elements: ");
                    for(int i = 0; i<size-1; i++){
                        scanf("%d",&arr[i]);
                    }
                    print(arr,size);
                    break;
            case 5: printf("Enter the size: ");
                    scanf("%d",&size);
                    break;
            case 6: print(arr,size);
        }
    }
}
 