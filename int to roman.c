// #include<stdio.h>
// int main(){
//     int arr[] = {1,2,3,4,5,6,7,8,9,10,40,50,90,100,400,500,900,1000};
//    char str[18] ={'I','II','III','IV','V','VI','VII','VIII','IX','X','XL','L','XC','C','CD','D','CM','M'};
//    printf("Roman Numeral Converter:\n");
//    int num;
//    printf("Enter integer : ");
//    scanf("%d",&num);
//    if(num <= 0 || num > 3999){
//     printf("NOT IN DOMAIN");
//    }
//    else{
//     int a = num/1000;
//     int x = num%1000;
//     int b = x/100;
//     int y = x%100;
//     int c = y/10;
//     int d = y%10;
//     for(int i =0;i<a;i++){
//         printf("%s",str[17]);
//     }
//     for(int i=0;i<18;i++){
//         if((b*100)==arr[i]){
//             printf("%s",str[i]);
//         }
//     }
//    }
// }
/*#include <stdio.h>

// Function to convert decimal to Roman numeral
void decimalToRoman(int num) {
    int decimal[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int i = 0;
    while (num > 0) {
        // Repeat the current Roman numeral while num is greater than or equal to the decimal value
        while (num >= decimal[i]) {
            printf("%s", roman[i]);
            num -= decimal[i];
        }
        i++;
    }
}

int main() {
    int num;

    // Input the decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    if (num <= 0 || num > 3999) {
        printf("Invalid input. Please enter a number between 1 and 3999.\n");
    } else {
        printf("Roman numeral equivalent: ");
        decimalToRoman(num);
        printf("\n");
    }
    return 0;
}*/

#include<stdio.h>
#include<string.h>
#define max 1200
int main(){
    char string[max];
    char strsmall[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char strbig[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    printf("Enter the string : ");
    gets(string);
    int n = strlen(string);
    int flag =0;
    for(int i=0;i<26;i++){
        int count = 0;
        int index  =-1;
        for(int j=0;j<n;j++){
            if(string[j] == strsmall[i] || string[j] == strbig[i] ){
                index = j;  
            }
            if((index>=0)&&index<=n){
                count ++;
            }
            
        }
        if(count != 0){
            flag =1;
            count =0;
            continue;
        }
        else{
            flag =0;
            break;
        }
    }
    if(flag == 0)
    printf("not");
    else
    printf("yes");
}
/*
#include<stdio.h>
#define max 200
void input(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("Enter value of arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
}
int main(){
    int arr[max];
    int n,sum;
    int c[50];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter numbers:\n");
    input(arr,n);
    printf("Enter sum : ");
    scanf("%d",&sum);
    int flag=0,count=0;
    int d=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((arr[i]+arr[j])==sum){
                flag =1;
                count ++;
                c[d]=arr[i];
                c[d+1]=arr[j];
                d=d+2;

            }
        }
    }
    if(flag == 1){
        printf("Yes sum is present & %d pairs exist ",count);
    }
    else
    printf("Sum doesn't exist \n");
    
    for(int d=0;d<(count*2);d=d+2){
    printf("Given sum occurs by the sum of %d & %d.\n",c[d],c[d+1]);
}
}

#include<stdio.h>
   int main(){
    int n,key;
    printf("Enter size of array:\n");
    scanf("%d",&n);
    int arr[n];
    int c[50];
    int d=0;
    for(int i=0;i<n;i++)
    {
        printf("Enter element of arr[%d]:\n",i);
        scanf("%d",&arr[i]);
    }
    printf("Enter key:\n");
    scanf("%d",&key);
     int flag=0,index;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            // if(flag==0)
            // {index=i;}
            flag=1;
            c[d]=i;
            d++;

        }
    }
    if(flag==1)
    {
        printf("Key is present in the array at index :\n");
        for(int i=0;i<d;i++)
        {
            printf("%d ",c[i]);
        }
    }
    else
    printf("Key is not present in the array.");
   }*/

  /* #include<stdio.h>
   #include<string.h>
   int main(){
    char str[100];
    printf("Enter a string:\n");
    gets(str);
    int n=strlen(str);
    //int flag=0;   RADHIKA
    int length;
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(str[j]!=str[i])
            {   
                continue;
            }
            else
            {
                length = j;
                break;
            }
           
        }
        if(length>0)
        break;
    }
    printf("Max substring is present of length %d.",length);
   }*/