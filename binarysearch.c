#include<stdio.h>
void input(int *arr,int n){
    printf("Enter the values \n");
    for(int i=0;i<n;i++){
        printf("arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
}
int binarysearch(int *arr,int start,int end,int key){
     int mid=(start+end)/2,status;
     if(start<=end){
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]>key){
            status = binarysearch(arr,start,mid-1,key);
            return status;
        }
        else{
            status = binarysearch(arr,mid+1,end,key);
            return status;
        }
     }
     else
        return -1;
}
int main(){
    int arr[50],start=0,size,key;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    input(arr,size);
    printf("Enter the key you want to search : ");
    scanf("%d",&key);
    int result = binarysearch(arr, start, size-1,key);
    if(result == -1){
        printf("%d is not present in array \n",key);
    }
    else{
        printf("%d is present at %d index \n",key,result);
    }
    return 0;
}