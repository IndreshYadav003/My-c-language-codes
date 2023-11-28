#include<stdio.h>
#define size 5 
int dq[100];
int front = -1, rear =-1;

//Insertion from front
void front_insert(int a){  
if((front==0 && rear==size-1) || (front==rear+1)) {  
 printf("deque is full, Insertion is not possible");  
    }  
 else if((front==-1) && (rear==-1))  {  
front=rear=0;  
dq[front]=a;  
}  
else if(front==0){  
 front=size-1;  
dq[front]=a;  
}  
else  
{  
front=front-1;  
 dq[front]=a;  
}  
}  

// insertion from rear end
void rear_indert(int n)  {  
if((front==0 && rear==size-1) || (front==rear+1))  
{  
printf("deque is full");  
}  
else if((front==-1) && (rear==-1))  
{  
rear=0;  
dq[rear]=n;  
 }  
else if(rear==size-1)  { 
rear=0;  
dq[rear]=n;  
 }  
 else  
 {  
rear++;  
dq[rear]=n;  
}    
}  

//function to analyze state of queue.  
void display()  
{  
int i=front;  
printf("\n Elements inside the double ended queue are : ");    
 while(i!=rear)  
 {  
printf("%d ",dq[i]);  
i=(i+1)%size;  
}  
printf("%d",dq[rear]);  
}  

void front_Delete()  {  
if((front==-1) && (rear==-1))  
{
    printf("There is no element to delete inside a deque");  
 }  
 else if(front==rear)  
{  
 printf("\nThe deleted element from the front is %d", dq[front]);  
 front=-1;  
 rear=-1;        
 }       else if(front==(size-1))  
     {  
 printf("\nThe deleted element from the front is %d", dq[front]);  
         front=0;  
     }  
     else  
     {  
          printf("\nThe deleted element from the front is %d", dq[front]);  
          front=front+1;  
     }  
}  

// dequeue_rear() function deletes the element from the rear  

void rear_Delete()  
{  
  if((front==-1) && (rear==-1))  
    {  
        printf("Deque is empty");  
    }  
    else if(front==rear)  
    {  
        printf("\nThe deleted element from rear is %d", dq[rear]);  
        front=-1;  
        rear=-1;        
    }  
     else if(rear==0)  
     {  
         printf("\nThe deleted element from the rear node is %d", dq[rear]);  
         rear=size-1;  
     }  
     else  
     {  
          printf("\nThe deleted element from rear node is %d", dq[rear]);  
          rear = rear-1;  
     }  
}  
int main() {   
    front_insert(-5);   
front_insert(2);  
    rear_indert(17);  
    rear_indert(12); 
rear_indert(47);
display();
front_Delete();
rear_Delete();
display();  
 return 0;  
}  