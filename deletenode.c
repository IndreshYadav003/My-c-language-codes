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
struct node *deleteBefore(struct node *start){
    struct node *new_node,*ptr,*preptr;
    int val;
    printf("\n Enter  node value which  you want to delete node");
    scanf("%d",&val);
    ptr=start;
    preptr=ptr;
    while (ptr->num!=val)
    {
        preptr=ptr;
        ptr=ptr->nextptr;
    }
    preptr->nextptr=ptr->nextptr;
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
    struct node *ptr=deleteBefore(stnode);
     displayList(ptr);
    
    return 0;
}
//out put of my code
 //Input the number of nodes : 7
/// Input data for node 1 : 54
// Input data for node 2 : 34
 //Input data for node 3 : 32
 //Input data for node 4 : 2434
 //Input data for node 5 : 56
 //Input data for node 6 : 45
 //Input data for node 7 : 53

// Data entered in the list :
// Data = 54       Data = 34       Data = 32       Data = 2434     Data = 56       Data = 45       Data = 53
// Enter  node value which  you want to delete node56
// Data = 54       Data = 34       Data = 32       Data = 2434     Data = 45       Data = 53


