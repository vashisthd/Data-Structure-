// #include<stdio.h>
// void input(int arr[50],int n){
//     printf("Enter the values \n");
//     for(int i=0;i<n;i++){
//         printf("arr[%d] : ",i);
//         scanf("%d",&arr[i]);
//     }
// }
// void print(int arr[50],int n){
//     printf("Array is : ");
//     for(int i=0;i<n;i++){
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
// }
// void swap(int* x,int* y){
//     int temp=*x;
//     *x = *y;
//     *y = temp;
// }
// void sorting(int start,int end,int arr[50]){
//     int count=0;
//     if(start>end){
//         return ;
//     }
//     else{
//         for(int i=0;i<=end;i++){
//         if(arr[i]<=arr[start]){
//             count++;
//         }
//         }
//         swap(&arr[start],&arr[count]);
//         return sorting(start+1,end,arr);
//     }
// }
// int main(){
//     int arr[50],size,start=0;
//     printf("Enter the size of array : ");
//     scanf("%d",&size);
//     int end=size-1;
//     input(arr,size);
//     print(arr,size);
//     sorting(start,end,arr);
//     printf("Sorted ");
//     print(arr,size);
// }
// C program for insertion sort
#include <math.h>
#include <stdio.h>

/* Function to sort an array 
using insertion sort*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) 
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], 
		that are greater than key, 
		to one position ahead of 
		their current position */
		while (j >= 0 && arr[j] > key) 
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// A utility function to print 
// an array of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver code
int main()
{
	int arr[] = {12, 11, 13, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, n);
	printArray(arr, n);

	return 0;
}
