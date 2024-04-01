// #include<stdio.h>
// void swap(int* x,int* y){
//     int temp=*x;
//     *x = *y;
//     *y = temp;
// }
// void insert_sort(int arr[50],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         int count=0;
//         for(int j=0;j<n;j++)
//         {
//             if(arr[i]>=arr[j])
//             {
//                 count ++;
//             }
//             else
//             continue;
//         }
//         swap(&arr[i],&arr[count]);
//     }
// }
// void print_array(int arr[50], int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         printf("%d ",arr[i]);
//     }
// }
// int main(){
//     int arr[50];
//     int size;
//     printf("Enter size of array:\n");
//     scanf("%d",&size);
//     for(int i=0;i<size;i++)
//     {
//         printf("Enter element of arr[%d]:",i);
//         scanf("%d",&arr[i]);
//     }
//     printf("\nThe array is:\n");
//     print_array(arr,size);
//     insert_sort(arr,size);
//     printf("\nSorted array is:\n");
//     print_array(arr,size);
// }
// // Selection sort in C

// // #include <stdio.h>

// // // function to swap the the position of two elements
// // void swap(int *a, int *b) {
// //   int temp = *a;
// //   *a = *b;
// //   *b = temp;
// // }

// // void selectionSort(int array[], int size) {
// //   for (int step = 0; step < size - 1; step++) {
// //     int min_idx = step;
// //     for (int i = step + 1; i < size; i++) {

// //       // To sort in descending order, change > to < in this line.
// //       // Select the minimum element in each loop.
// //       if (array[i] < array[min_idx])
// //         min_idx = i;
// //     }

// //     // put min at the correct position
// //     swap(&array[min_idx], &array[step]);
// //   }
// // }

// // // function to print an array
// // void printArray(int array[], int size) {
// //   for (int i = 0; i < size; ++i) {
// //     printf("%d  ", array[i]);
// //   }
// //   printf("\n");
// // }

// // // driver code
// // int main() {
// //   int data[] = {5,9,7,9,-1,9,3,5,-3};
// //   int size = sizeof(data) / sizeof(data[0]);
// //   selectionSort(data, size);
// //   printf("Sorted array in Acsending Order:\n");
// //   printArray(data, size);
// // }
#include<stdio.h>
void insertionsort (int arr[50],int n)
{
    int i,j;
    for(i=1;i<n;i++)
    {
        for(j=i;j>0;j--)
        {
         if (arr[j-1] > arr[j])
         {
            int k = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = k;
         }
        }
    }
}void print_array(int arr[50], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main(){
    int arr[50];
    int size;
    printf("Enter size of array:\n");
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        printf("Enter element of arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    printf("\nThe array is:\n");
    print_array(arr,size);
    insertionsort(arr,size);
    printf("\nSorted array is:\n");
    print_array(arr,size);
}