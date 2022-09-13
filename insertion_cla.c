#include<stdio.h>

int *Rinsertion(int arr[], int i, int v, int j, int n){
    if(i<=n-1){
        v = arr[i];
        j = i-1;
        while((j>=0) && (arr[j]>v)){
            arr[j+1] = arr[j];
            j = j-1;
            arr[j+1] = v;
        }
        Rinsertion(arr,++i,v,j,10);
    }
    else
        return arr; 
}


int *Iinsertion(int arr[]){
    int i =0;
    int v = 0;
    int j = i-1;
    int n = 10;

    for(i=1; i<=n-1;i++){
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

void print(int arr[]){
    int counter =0;
    while(counter < 10){
        printf("%d  ",arr[counter]);
        counter++;
    }
    printf("\n\n");    
}

int main(int argc, char **argv){
    int i =0;

    int *arr[0] = argv[1];
    while(i < 10){
        printf("%d  ",(arr[0]+i));
        i++;
    }
    printf("\n\n");

    int ch;
    while(1){
        printf("1.Iterative Insertion\n2.Recursive Insertion\n\n");
        printf("Enter the choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1: print(Iinsertion(arr));
                    break;
            case 2: //int v = 0//arr[i];
                    //int j = 0//i-1;
                    int *ar = Rinsertion(arr,1,0,0,10);
                    print(ar);
                    break;
        }
    }   
}