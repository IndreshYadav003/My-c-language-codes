#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int num;                        //Data of the node
    struct node *nextptr;           //Address of the next node
}*stnode;
//Create node Function 1
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
//Create display Node Function 2
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
// Insert Beginning Function 3
struct node *insert_beg(struct node *start){
    struct node *new_node;
    int val;
    printf("Plesase Enter number which you are added=");
    scanf("%d",&val);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->num=val;
    new_node->nextptr=start;
    start=new_node;
    return start;
}
//Inser at the end of node 4
struct node *insert_end(struct node *start){
    struct node *new_node,*ptr;
    int val;
    printf("\n Plesase Enter number which you are added=");
    scanf("%d",&val);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->num=val;
    new_node->nextptr=NULL;
    ptr=start;
    while (ptr->nextptr!=NULL)
    {
        ptr=ptr->nextptr;
    }
    ptr->nextptr=new_node;
    return start;
}
//Create Insert node After a node Function 5
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
    while (preptr->num!=a)
    {
        preptr=ptr;
        ptr=ptr->nextptr;
    }
    preptr->nextptr=new_node;
    new_node->nextptr=ptr;
    return start;
}
//Insert befor a node 6

struct node *insertBeforeaNode(struct node *start){
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
//delete  start node 7
struct node *delete_beg(struct node *start){
    struct node *ptr;
    ptr=start;
    start=start->nextptr;
    free(ptr);
    return start;
}
//delete After a node 8
struct node *deleteAfter(struct node *start){
    struct node *new_node,*ptr,*preptr;
    int val;
    printf("\n Enter value which after you want to delete node");
    scanf("%d",&val);
    ptr=start;
    preptr=ptr;
    while (preptr->num!=val)
    {
        preptr=ptr;
        ptr=ptr->nextptr;
    }
    preptr->nextptr=ptr->nextptr;
    free(ptr);
    return start;
}
// delete end node 9
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
// delete a node 10
struct node *deleteNode(struct node *start){
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
//sort linked list 11
struct node *sortlinkedlist(struct node *start){
    struct node  *ptr,*preptr;
    int val;
    ptr=start;
    while (ptr->nextptr!=NULL)
    {
        preptr=ptr->nextptr;
        while ( preptr!= NULL)
        {
            if(ptr->num>preptr->num){
                val=ptr->num;
                ptr->num=preptr->num;
                preptr->num=val;
            }
            preptr=preptr->nextptr;
        }
        ptr=ptr->nextptr;
        
    }
    
    return start;
}
//serach element in linked list 12
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
int main(){
printf("*********** Main Menu*********** \n ");
printf("\n :Create node Function 1  \n");
printf("\n :Insert Beginning Function 2 \n");
printf("\n :Inser at the end of node 3\n");
printf("\n :Insert node After a node 4  \n");
printf("\n :Insert befor a node 5 \n");
printf("\n :delete  start node 6 \n");
printf("\n :delete After a node 7  \n");
printf("\n :delete end node 8 \n"); 
printf("\n :delete a node 9  \n");
printf("\n :sort linked list 10  \n");
printf("\n :serach element in linked list 11 \n");
stnode=NULL;
printf("\n pleasre Enter your Choose=");
int a;
scanf("%d",&a);
switch (a)
{
case 1:printf("\n Please enter number of nodes which you want=");
int n;
scanf("%d",&n);
stnode=createNodeList(n);
displayList(stnode);
    break;
case 2:printf("\n Please enter number of nodes which you want=");
scanf("%d",&n);
stnode=createNodeList(n);
displayList(stnode);
stnode=insert_beg(stnode);
displayList(stnode);
break;
case 3:printf("\n Please enter number of nodes which you want=");
scanf("%d",&n);
stnode=createNodeList(n);
displayList(stnode);
stnode=insert_end(stnode);
displayList(stnode);
break;
case 4:printf("\n Please enter number of nodes which you want=");
scanf("%d",&n);
stnode=createNodeList(n);
displayList(stnode);
stnode=insertAfteraNode(stnode);
displayList(stnode);
break;
case 5:printf("\n Please enter number of nodes which you want=");
scanf("%d",&n);
stnode=createNodeList(n);
displayList(stnode);
stnode=insertBeforeaNode(stnode);
displayList(stnode);
break;
case 6:printf("\n Please enter number of nodes which you want=");
scanf("%d",&n);
stnode=createNodeList(n);
displayList(stnode);
stnode=delete_beg(stnode);
printf("\n");
displayList(stnode);
break;
case 7:printf("\n Please enter number of nodes which you want=");
scanf("%d",&n);
stnode=createNodeList(n);
displayList(stnode);
stnode=delete_end(stnode);
printf("\n");
displayList(stnode);
break;
case 8:printf("\n Please enter number of nodes which you want=");
scanf("%d",&n);
stnode=createNodeList(n);
displayList(stnode);
stnode=deleteAfter(stnode);
printf("\n");
displayList(stnode);
break;
default:
case 9:printf("\n Please enter number of nodes which you want=");
scanf("%d",&n);
stnode=createNodeList(n);
displayList(stnode);
stnode=deleteNode(stnode);
printf("\n");
displayList(stnode);
break;
case 10:printf("\n Please enter number of nodes which you want=");
scanf("%d",&n);
stnode=createNodeList(n);
displayList(stnode);
stnode=sortlinkedlist(stnode);
printf("\n");
displayList(stnode);
break;
case 11:printf("\n Please enter number of nodes which you want=");
    scanf("%d", &n);
   stnode= createNodeList(n);
    printf("\n Data entered in the list : \n");
    displayList(stnode);
    printf("\n plase enter which value you want to search");
    int val;
    scanf("%d",&val);
   int v=searchlinkedlist(stnode,val);
if(v==-1){
    printf("\n false");
    printf("\n your search elenemt is not present");
}
else{
    printf("\ntrue");
    printf("\n your seach element is present");
}
break;
}
    return  0;
}