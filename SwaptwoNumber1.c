//Using third variable;
#include<stdio.h>
int main(){
    int a,b;
    printf("please enter number First");
    scanf("%d",&a);
    printf("pleas enter number second ");
    scanf("%d",&b);
    printf("After swaping number \n");
    int temp=a;
    a=b;
    b=temp;
    printf("Firstnumber=%d \nSecond number =%d",a,b);
    return 0;
}
