/*#include<stdio.h>
#define size 500
int main(){
    // int size;
    // printf("Enter max size of string:\n");
    // scanf("%d",&size);
    char str[size];
    printf("Enter a string:\n");
    gets(str);
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    int len=i;
    int flag=1,j=0,k=(len-1);
     while(j<k){
        if(str[j]!=str[k]){
            flag = 0;
            break;
     }
     j++,k--;
     }
    if(flag==1)
    printf("Entered string is palindrome.");
    else
    printf("Entered string is not palindrome.");

}*/
/*#include<stdio.h>
#include<string.h>
#define size 500
void reverse(char str[],int len){
    int i,temp;
    for(i=0;i<len/2;i++){
        for(int j=len-1-i;j>=0;j--){
            temp=str[i];
            str[i]=str[j];
            str[j]=temp;
            break;
        }
        
}
}
int main(){
    char str[size];
    printf("enter a string:\n");
    gets(str);
    int len=strlen(str);
    reverse(str,len);
    puts(str);
 }*/
//  #include<stdio.h>
//  typedef struct spterm{
//     int row,col,value;
//  }spterm;
//  void sorting(spterm sparseA[],int n){
//     for(int i=1;i<=n;i++){
        
//     }
//  }
//  int main(){

//  }
//{ Driver Code Starts
// Initial Template for C

#include <stdio.h>

struct pair {
    long long int min;
    long long int max;
};

struct pair getMinMax(long long int arr[], long long int n) ;

int main() {
    long long int t, n, a[100002], i;
    struct pair minmax;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);

        for (i = 0; i < n; i++) scanf("%d", &a[i]);
        minmax = getMinMax(a, n);
        printf("%d %d\n", minmax.min, minmax.max);
    }
    return 0;
}
// } Driver Code Ends


// User function Template for C
#include<stdio.h>
struct pair {
    long long int min;
    long long int max;
};


struct pair getMinMax(long long int arr[], long long int n) {
    int min=arr[0],max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min = arr[i];
        }
        if(arr[i]>max){
            max = arr[i];
        }
    }
    
}
int main(){
    long long int t,n,a[100002],i;
    struct pair minmax;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        minmax=getMinMax(a,n);
        printf("%d %d\n",minmax.min,minmax.max);

    }
    return 0;
}