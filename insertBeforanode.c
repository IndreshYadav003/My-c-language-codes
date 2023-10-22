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
struct node *insertAfteraNode(struct node *start){
    struct node *new_node,*ptr,*preptr;
    int val;
    printf("\n Plesase Enter number which you are added=");
    scanf("%d",&val);
    printf("\n Enter the value after which node you inser");
    int a;
    scanf("%d",&a);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->num=val;
    new_node->nextptr=NULL;
    ptr=start;
    preptr=ptr;
    while (ptr->num!=a)
    {
        preptr=ptr;
        ptr=ptr->nextptr;
    }
    preptr->nextptr=new_node;
    new_node->nextptr=ptr;
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
    struct node *ptr=insertAfteraNode(stnode);
     displayList(ptr);
    
    return 0;
}

//Data = 1        Data = 2        Data = 3        Data = 4        Data = 5
 //Plesase Enter number which you are added=564

 //Enter the value after which node you inser4
// Data = 1        Data = 2        Data = 3        Data = 564      Data = 4        Data = 5


