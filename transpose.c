#include<stdio.h>
typedef struct spterm{
    int row,col,val;
}spterm;
void display(spterm sparse[]){
    int k=1;
    for(int i=0;i<sparse[0].row;i++)
    {
        for(int j=0;j<sparse[0].col;j++)
        {
            if(sparse[k].row == i)
            {
                if(sparse[k].col == j){
                    printf("%d\t",sparse[k].val);
                    k++;
                }
                else{
                printf("0\t");
            }
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }
}
void alloting_value(int rowterms[],spterm sparseA[],spterm transP[]){
    for(int i=1;i<=sparseA[0].val;i++){
        int value = sparseA[i].col;
        transP[rowterms[value]].row=sparseA[i].col;
        transP[rowterms[value]].col=sparseA[i].row;
        transP[rowterms[value]].val=sparseA[i].val; 
        rowterms[value]=rowterms[value]+1;
    }
}
void counting_index(int arr[],int n,spterm sparseA[]){
    for(int i=0;i<n;i++){
       int value=sparseA[i].col;
       arr[value]++;
    }
}
void alloting_index(int count[],int rowterms[],int n){
    rowterms[0]=1;
    for(int i=1;i<n;i++){
        rowterms[i]=rowterms[i-1]+count[i-1];
    }
}
void initialize(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]=0;
    }
}

int main(){
    spterm sparseA[101],transP[101];
    printf("Enter total no of rows : ");
    scanf("%d",&sparseA[0].row);
    printf("Enter total no of columns : ");
    scanf("%d",&sparseA[0].col);
    printf("Enter total no of non-zero values : ");
    scanf("%d",&sparseA[0].val);
    for(int i=1;i<=sparseA[0].val;i++){
        printf("Enter row no. of element : ");
        scanf("%d",&sparseA[i].row);
        printf("Enter column no. of element : ");
        scanf("%d",&sparseA[i].col);
        printf("Enter non-zero value present at (%d,%d) : ",sparseA[i].row,sparseA[i].col);
        scanf("%d",&sparseA[i].val);
    }
    display(sparseA);
    int rowterms[50],count[50];
    initialize(rowterms,sparseA[0].col);
    initialize(count,sparseA[0].col);
    counting_index(count,sparseA[0].col,sparseA);
    alloting_index(count,rowterms,sparseA[0].col);
    alloting_value(rowterms,sparseA,transP);
    display(transP);
    return 0;
}