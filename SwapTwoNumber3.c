//using Bitwise XOR;
#include<stdio.h>
int main(){
    int a,b;
    printf("please enter number First");
    scanf("%d",&a);
    printf("pleas enter number second ");
    scanf("%d",&b);
    printf("After swaping number \n");
    a=a^b;
    b=a^b;
    a=a^b;
    printf("First NUmber =%d \n Second Number =%d",a,b);
    return 0;
}