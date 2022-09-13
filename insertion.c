#include<stdio.h>
#define MAXSIZE 6

int *Rinsertion(int arr[], int i, int j, int v, int n){
    if(i>n)
        return arr;
    else{
        v = arr[i];
        j = i-1;
        while((j>=0) && (arr[j]>v)){
            arr[j+1] = arr[j];
            j = j-1;
            arr[j+1] = v;
        }
        Rinsertion(arr,++i,j,v,n);
    }
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
    while(counter < MAXSIZE){
        printf("%d  ",arr[counter]);
        counter++;
    }
    printf("\n\n");    
}

int main(){
    int i =0;
    int arr[MAXSIZE] = {1,8,19,2,23,9}; //,6,69,420,3};
    while(i < MAXSIZE){
        printf("%d  ",arr[i]);
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
            case 2: int *ar = Rinsertion(arr,1,0,0,MAXSIZE);
                    print(ar);
                    break;
        }
    }   
}