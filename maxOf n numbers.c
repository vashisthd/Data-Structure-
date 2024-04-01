#include<stdio.h>
void input(int n,int arr[n]){
    printf("Enter values \n");
    for(int i=0;i<n;i++){
        printf("Number %d : ",i+1);
        scanf("%d",&arr[i]);
    }
}
int greatest(int n,int arr[]){
    if(n==1){
        return arr[0];
    }
    else{
    int maxOfRest = greatest(n-1,arr+1);
    return (arr[0]>maxOfRest) ? arr[0] : maxOfRest;
    }
}
int main(){
    int size;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int arr[size];
    input(size,arr);
    int max = greatest(size,arr);
    printf("Greatest of all numbers is : %d ",max);
    return 0;
}