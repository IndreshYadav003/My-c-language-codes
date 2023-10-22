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
struct node *delete_end(struct node *start){
    struct node *ptr,*preptr;
    ptr=start;
    preptr=ptr;
    while(ptr->nextptr!=NULL){
        preptr=ptr;
        ptr=ptr->nextptr;
    }
    preptr->nextptr=NULL;
    free(ptr);
    return start;
}
int main()
{
    int n;
		
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
   stnode= createNodeList(n);
    printf("\n Data entered in the list : \n");
    displayList(stnode);
    printf("\n After Deleting First Element \n");
    struct node *ptr=delete_end(stnode);
     displayList(ptr);
    
    return 0;
}
//out put of my code
 //Input the number of nodes : 5
 //Input data for node 1 : 34
 //Input data for node 2 : 98
 //Input data for node 3 : 65
 //Input data for node 4 : 43
 //Input data for node 5 : 28

 //Data entered in the list :
 //Data = 34       Data = 98       Data = 65       Data = 43       Data = 28
// After Deleting First Element
// Data = 34       Data = 98       Data = 65       Data = 43
