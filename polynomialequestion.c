#include<stdio.h>
#include<stdlib.h>
struct node{
int coeff;
int exp;
struct node *next;
};
void display(struct node *head){

struct node *ptr;
ptr=head;
while(ptr!=NULL){
  printf("%dx^%d",ptr->coeff,ptr->exp);
  if(ptr->exp!=0)
  printf("+");
    ptr=ptr->next;

}
printf("\n");
}
struct node *fun(struct node *start)
{
 struct  node *newnode,*ptr;
 int n,a,b;
 printf("please enter power of polymail=");
 scanf("%d",&b);
 printf("\n");
 while (b!=-1)
 {
 printf("enter ceoffcent=");
 scanf("%d",&n);
 printf(" enter exp=");
 scanf("%d",&a);
 printf("\n");
    if(start==NULL){
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->coeff=n;
        newnode->exp=a;
        newnode->next=NULL;
        start=newnode;
    }
    else{
        ptr=start;
        while (ptr->next!=NULL)
        
     ptr=ptr->next;
           newnode=(struct node*)malloc(sizeof(struct node));
           newnode->coeff=n;
           newnode->exp=a;
           newnode->next=NULL;
           ptr->next=newnode;
          // ptr=ptr->next;
        
    }
    b--;
    
    }
       return start; 
    }

int main()
{
    struct node* head=NULL;
    head=fun(head);
    display(head);
return 0;
}
