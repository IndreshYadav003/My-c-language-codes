#include<stdio.h>
int fact(int a){
    if(a==0)return 1;
    else return (a*fact(a-1));
}
int main(){
    printf("Please enter number");
    int n;
    scanf("%d",&n);
    printf("Factorial of number=%d",fact(n));
    return 0;
}