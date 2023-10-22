#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int num;                        //Data of the node
    struct node *nextptr;           //Address of the next node
}*stnode;

//creat a nodes;
struct node *createNodeList(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));

    if(stnode == NULL) //check whether the fnnode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
        return stnode;
    }
    else
    {
// reads data for the node through keyboard

        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        stnode->num = num;      
        stnode->nextptr = NULL; // links the address field to NULL
        tmp = stnode;
// Creating n nodes and adding to linked list
        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);
 
                fnNode->num = num;      // links the num field of fnNode with num
                fnNode->nextptr = NULL; // links the address field of fnNode with NULL
 
                tmp->nextptr = fnNode; // links previous node i.e. tmp to the fnNode
                tmp = tmp->nextptr; 
            }
        }
    }
    return stnode;
}
void displayList(struct node *start)
{
    
    if(start== NULL)
    {
        printf(" List is empty.");
    }
    else
    {
      struct node  *tmp = start;
        while(tmp != NULL)
        {
            printf(" Data = %d\t", tmp->num);       // prints the data of current node
            tmp = tmp->nextptr;                     // advances the position of current node
        }
    }
} 
int searchlinkedlist(struct node *start,int val){
    struct node  *ptr;
    

    ptr=start;
  while (ptr!=NULL)
  {
    if(ptr->num==val){
    return val;
      }
  ptr=ptr->nextptr;
  }
    return -1;
}
int main()
{
    int n;
		
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
   stnode= createNodeList(n);
    printf("\n Data entered in the list : \n");
    displayList(stnode);
    int val;
     printf("\n Please Enter Number Which you wantSearch");
    scanf("%d",&val);
    int  ptr=searchlinkedlist(stnode,val);
    //displayList(ptr);
    if(ptr==val){
        printf("True");
    }
    else
    printf("False");
    return 0;
}
 //out put of my function
  //Input the number of nodes : 5
 I//nput data for node 1 : 43
 //Input data for node 2 : 78
 //Input data for node 3 : 56
 //Input data for node 4 : 433
 //Input data for node 5 : 2

 ///Data entered in the list :
 //Data = 43       Data = 78       Data = 56       Data = 433      Data = 2
 //Please Enter Number Which you wantSearch78
//True
