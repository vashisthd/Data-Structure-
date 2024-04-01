// #include<stdio.h>
// int sum(int n)
// {
//     if(n==0)
//     return 0;
//     else
//     return n + sum(n-1);
// }
// int main()
// {   
//     int n;
//     printf("Enter a number upto which sum is required:");
//     scanf("%d",&n);
//     int res=sum(n);
//     if(res==0)
//     printf("Enter valid input.");
//     else
//     printf("Sum is %d.",res);
//     return 0;
// }

// #include<stdio.h>
// #include<math.h>
// int sum(int n)
// {   if(n<0)
//     return 0;
//     if(n==0)
//     return 1;
//     else
//     return pow(2,n) + sum(n-1);
// }
// int main()
// {
//     int n;
//     printf("Enter a number:");
//     scanf("%d",&n);
//     int res=sum(n);
//     if(res==0)
//     printf("Enter valid input.");
//     else
//     printf("Sum is %d.",res);
//     return 0;
// }

#include<stdio.h>
void series(int n,int copy)
{
    if(copy<0)
    {
        return ;
    }
    else{
    printf("%d , ",n-(copy));
    return series(n,copy-1);}
}
int main()
{
    int n;
    printf("Enter a number:\n");
    scanf("%d",&n);
    int copy=n-1;
    series(n,copy);
}