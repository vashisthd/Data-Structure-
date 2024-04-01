#include<stdio.h>
typedef struct spterm{
    int row,col,val;
}spterm;
void read_matrix(spterm sparseA[])
{
    for(int i=1;i<=sparseA[0].val;i++)
    {
        printf("Enter row number of non-zero value:\n");
        scanf("%d",&sparseA[i].row);
        printf("Enter col number of non-zero value:\n");
        scanf("%d",&sparseA[i].col);
        printf("Enter non-zero value:\n");
        scanf("%d",&sparseA[i].val);
    }
}
void display(spterm sparseA[])
{   
    int k=1;
    for(int i=0;i<sparseA[0].row;i++)
    {
        for(int j=0;j<sparseA [0].col;j++)
        {
            if(sparseA[k].row==i && sparseA[k].col==j)
            {
                printf("%d\t",sparseA[k].val);
                k++;
            }
            else
            printf("0\t");
        }
        printf("\n");
    }
}
void transpose(spterm sparseA[] , spterm transp[])
{   transp[0].col=sparseA[0].row;
    transp[0].row=sparseA[0].col;
    transp[0].val=sparseA[0].val;

    int rowterms[sparseA[0].col];
    int starting_index[sparseA[0].col];
    for(int i=0;i<sparseA[0].col;i++)
    {
        rowterms[i]=0;
    }
    for(int i=1;i<=sparseA[0].val;i++)
    {
        rowterms[sparseA[i].col]++;
    }
    starting_index[0]=1;
    for(int i=1;i<sparseA[0].col;i++)
    {
        starting_index[i]=starting_index[i-1]+rowterms[i-1];
    }
    int col=0,index=0;
    for(int i=1;i<=sparseA[0].val;i++)
    {   
        col=sparseA[i].col;
        index=starting_index[col];
        transp[index].row=sparseA[i].col;
        transp[index].col=sparseA[i].row;
        transp[index].val=sparseA[i].val;
        starting_index[col]++;
    }
}
void display_trans(spterm transp[]){
    for(int i=0;i<=transp[0].val;i++){
        printf("%d\t%d\t%d\n",transp[i].row,transp[i].col,transp[i].val);
    }
}
int main(){
spterm sparseA[101];
spterm transp[101];
printf("Enter total number of rows:\n");
scanf("%d",&sparseA[0].row);
printf("Enter total number of columns:\n");
scanf("%d",&sparseA[0].col);
printf("Enter total number of non-zero values:\n");
scanf("%d",&sparseA[0].val);
read_matrix(sparseA);
printf("Original matrix is:\n");
display(sparseA);
transpose(sparseA,transp);
printf("Transpose format is : \n");
display_trans(transp);
printf("\n");
printf("Transposed matrix is:\n");
display(transp);
}