// Code for Bubble sort 
#include<stdio.h>
void input(int arr[50],int n){
    printf("Enter the values \n");
    for(int i=0;i<n;i++){
        printf("arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
}
void print(int arr[50],int n){
    printf("Array is : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void swap(int* x,int* y){
    int temp=*x;
    *x = *y;
    *y = temp;
}
void sorting(int start,int end,int arr[50]){
    if(start>end){
        return ;
    }
    else{
        for(int i=0;i<=end;i++){
        if(arr[i]>arr[i+1]){
           swap(&arr[i],&arr[i+1]);
        }
        }
        return sorting(start,end-1,arr);
    }
}
int main(){
    int arr[50],size,start=0;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int end=size-1;
    input(arr,size);
    print(arr,size);
    sorting(start,end,arr);
    printf("Sorted ");
    print(arr,size);
}