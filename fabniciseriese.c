#include<stdio.h>
int feb(int n){
    if(n==0)return 0;
    else if(n==1)return 1;
    else return (feb(n-1)+feb(n-2));

}
int main(){
    printf("Please enter number");
    int a;
    scanf("%d",&a);
    for (int  i = 0; i <a; i++)
    {
 printf("%d\t",feb(i));
    }
    
    return 0;
}