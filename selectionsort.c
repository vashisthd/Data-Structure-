#include<stdio.h>
void input(int arr[50],int n){
    printf("Enter the values \n");
    for(int i=0;i<n;i++){
        printf("arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
}
void swap(int* x,int* y){
    int temp=*x;
    *x = *y;
    *y = temp;
}
void sorting(int start,int end,int arr[50]){
    int min=arr[start],index=start;
    if(start == end){
        return ;
    } 
    else{
        for(int i=start;i<=end;i++){
            if(min>arr[i]){
                min=arr[i];
                index=i;
            }
        }
        swap(&arr[start],&arr[index]);
        return sorting(start+1,end,arr);
    }
}
void print(int arr[50],int n){
    printf("Array is : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[50],start=0,size;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int end=size-1;
    input(arr,size);
    print(arr,size);
    sorting(start,end,arr);
    printf("Sorted ");
    print(arr,size);
}