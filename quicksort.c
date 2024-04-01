#include<stdio.h>
void input(int arr[50],int n){
    printf("Enter the values \n");
    for(int i=0;i<n;i++){
        printf("arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
}
void swap(int* x,int* y){
    int temp = *x;
    *x= *y;
    *y=temp;
}

int partition( int arr[], int s, int e) {

    int pivot = arr[s];

    int count = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <=pivot) {
            count++; 
        }
    }

    //place pivot at right position
    int pivotIndex = s + count;
    swap(&arr[pivotIndex],&arr[s]);

    //left and right condition true krni h
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(&arr[i++],&arr[j--]);
        }

    }

    return pivotIndex;

}

void quickSort(int arr[], int s, int e) {

    //base case
    if(s >= e) 
        return ;

    //partitioon bnadiya
    int p = partition(arr, s, e);

    // for left part
    quickSort(arr, s, p-1);

    // for right part
    quickSort(arr, p+1, e);

}

int main() {
    int arr[50],start=0,size;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    input(arr,size);
    
    quickSort(arr, start, size-1);

    for(int i=0; i<size; i++) 
    {
        printf("%d ",arr[i]);
    } 
    printf("\n");


    return 0;
}