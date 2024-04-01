// // #include<stdio.h>
// // void display(int poly3[],int deg3)
// // {
// //     for(int i=0;i<=deg3;i++)
// //     {   
// //          if(i!=0 && i<=deg3 && poly3[i-1]!=0 && poly3[i]>0)
// //         {
// //             printf("+ ");
// //         }
// //         if((deg3-i)!=0 && poly3[i]!=0)
// //         printf("%d x^%d ", poly3[i],(deg3-i));

// //         else if( (deg3-i)==0 && poly3[i]!=0)
// //         {
// //             printf("%d",poly3[i]);  
// //         }
        
       
// //     }
// // }
// // int main(){
// //     int deg1,deg2,deg3;
// //     int poly1[50],poly2[50],poly3[50];
// //     printf("Enter degree of 1st polynomial:\n");
// //     scanf("%d",&deg1);
// //     printf("\n");
// //     printf("Enter degree of 2nd polynomial:\n");
// //     scanf("%d",&deg2);
// //     printf("\n");
// //     printf("Reading 1st polynomial:\n");
// //     printf("\n");
// //     for(int i=0;i<=deg1;i++)
// //     {
// //         printf("Enter coefficient of x raised to the power %d :\n", (deg1-i));
// //         scanf("%d",&poly1[i]);
// //     }
// //     printf("\n");
// //     printf("Reading 2nd polynomial:\n");
// //     printf("\n");
// //     for(int i=0;i<=deg2;i++)
// //     {
// //         printf("Enter coefficient of x raised to the power %d :\n", (deg2-i));
// //         scanf("%d",&poly2[i]);
// //     }
// //     if(deg1==deg2)
// //     {
// //         deg3=deg1;
// //         for(int i=0;i<=deg3;i++)
// //         {
// //             poly3[i]=poly1[i]+poly2[i];
// //         }
// //     }
// //     else if(deg1>deg2)
// //     {
// //         deg3=deg1;
// //         int i,j=0;
// //         for(i=0;i<(deg1-deg2);i++)
// //         {
// //             poly3[i]=poly1[i];
// //         }
// //         while(i<=deg1)
// //         {
// //             poly3[i]=poly2[j]+poly1[i];
// //             j++;
// //             i++;
// //         }
// //     }
// //     else if(deg2>deg1)
// //     {
// //         deg3=deg2;
// //         int i,j=0;
// //         for(i=0;i<(deg2-deg1);i++)
// //         {
// //             poly3[i]=poly2[i];
// //         }
// //         while(i<=deg2)
// //         {
// //             poly3[i]=poly2[i]+poly1[j];
// //             j++;
// //             i++;
// //         }
// //     }
// //     printf("\n");
// //     int degree;
// //     int k=deg3;
// //     for(int i=0;i<=deg3;i++)
// //     {
// //         if(poly3[i]!=0)
// //         {
// //             degree=k;
// //             break;
// //         }
// //         else
// //         k--;
// //     }
// //     printf("Degree of 3rd polynomial is: %d\n",degree);
// //     printf("\n");
// //     printf("Required polynomial is:\n");
// //     printf("\n");
// //     display(poly3,deg3);
// //     printf("\n");
// // }
// #include<stdio.h>
// typedef struct spterm{
//     int row,col,val;
// }spterm;
// void display(spterm sparse[]){
//     int k=1;
//     for(int i=0;i<sparse[0].row;i++)
//     {
//         for(int j=0;j<sparse[0].col;j++)
//         {
//             if(sparse[k].row == i)
//             {
//                 if(sparse[k].col == j){
//                     printf("%d\t",sparse[k].val);
//                     k++;
//                 }
//                 else{
//                 printf("0\t");
//             }
//             }
//             else
//             {
//                 printf("0\t");
//             }
//         }
//         printf("\n");
//     }
// }

// void sparse_transpose(spterm sparse[], spterm transp[])
// {
//     transp[0].row=sparse[0].col;
//     transp[0].col=sparse[0].row;
//     transp[0].val=sparse[0].val;
//     int k=1;
//    for(int i=0;i<sparse[0].col;i++)
//     {
//         for(int j=1;j<=sparse[0].val;j++)
//         {
//             if(sparse[j].col==i)
//             {
//                 transp[k].row=sparse[j].col;
//                 transp[k].col=sparse[j].row;
//                 transp[k].val=sparse[j].val;
//                 k++;
//             }
//         }
//     }
// }
// void transp_display(spterm transp[]){
//     int k=1;
//     for(int i=0;i<transp[0].row;i++)
//     {
//         for(int j=0;j<transp[0].col;j++)
//         {
//             if(i==transp[k].row && j==transp[k].col)
//             {
//                 printf("%d\t",transp[k].val);
//                 k++;
//             }
//             else
//             {
//                 printf("0\t");
//             }
//         }
//         printf("\n");
//     }
// }
// int main(){
//     spterm sparseA[101];
//     spterm transpose[101];
//     printf("Enter total number of rows:\n");
//     scanf("%d",&sparseA[0].row);
//     printf("Enter total number of columns:\n");
//     scanf("%d",&sparseA[0].col);
//     printf("Enter total number of non=zero values:\n");
//     scanf("%d",&sparseA[0].val);
//     for(int i=1;i<=sparseA[0].val;i++)
//     {
//         printf("Enter row number of non-zero value %d:\n",i);
//         scanf("%d",&sparseA[i].row);
//         printf("Enter column number of non-zero value %d:\n",i);
//         scanf("%d",&sparseA[i].col);
//         printf("Enter non-zero value:\n");
//         scanf("%d",&sparseA[i].val);
//     }
//     printf("Original matrix is:\n");
//     display(sparseA);
//     sparse_transpose(sparseA,transpose);
//     printf("Transpose matrix is:\n");
//     transp_display(transpose);
// }
#include<stdio.h>
void display(int poly[], int* deg)
{
    printf("Polynomial of degree %d is: ",*deg);
    for(int i=0;i<*deg;i++)
    {
        printf("%d x^%d + ",poly[i],(*deg)-i);
    }
    printf("%d\n",poly[*deg]);
}
void read_poly(int poly[50],int *deg)
{
    printf("Enter degree of polynomial:\n");
    scanf("%d",&*deg);
    for(int i=0;i<=*deg;i++)
    {
        printf("Enter coefficient of x raised to the power %d:\n",(*deg)-i);
        scanf("%d",&poly[i]);
    }
    display(poly,&(*deg));
}
void poly_add(int poly1[], int poly2[], int poly3[], int *deg1, int *deg2)
{ 
    int i,j,deg3;
    if(*deg1==*deg2)
    {   i=0;
        deg3=*deg1;
        for(int i=0;i<=*deg1;i++)
        {
            poly3[i]=poly1[i]+poly2[i];
        }
        printf("value of i is %d\n",i);
        display(poly3,&deg3);
    }
    else if(*deg1>*deg2)
    {   
        deg3=*deg1;
        for(int i=0;i<(*deg1-*deg2);i++)
        {
            poly3[i]=poly1[i];
        }
        j=0;
        for(i=(*deg1-*deg2);i<=*deg1;i++)
        {
            poly3[i]=poly1[i]+poly2[j];
            i++;j++;
        }
        display(poly3,&deg3);
    }
    else{   
        deg3=*deg2;
        for(int j=0;j<(*deg2-*deg1);j++)
        {
            poly3[j]=poly2[j];
        }
        j=(*deg2-*deg1),i=0;
        while(j<=*deg2)
        {
            poly3[j]=poly1[i]+poly2[j];
            i++;j++;
        }
        display(poly3,&deg3);
    }
}
int main()
{
    int poly1[50],poly2[50],poly3[50];
    int deg1,deg2;
    printf("Reading 1st polynomial:\n");
    read_poly(poly1,&deg1);
    printf("Reading 2nd polynomial:\n");
    read_poly(poly2,&deg2);
    poly_add(poly1,poly2,poly3,&deg1,&deg2);
}