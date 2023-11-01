#include <stdio.h>
#define MAX 5
int front = -1;
int rear = -1;
int arr[5];
// Function to add an element into the circular queue
void add(int value) {
    if ((rear + 1) % MAX == front) {
        printf("\n Queue is full. Cannot add element \n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    arr[rear] = value;
}
// Function to dequeue an element from the circular queue
void delete( ) {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    if (front == rear) {
      front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}
// Function to check if the circular queue is empty
void isEmpty() {
    if (front == -1 && rear == -1) {
        printf("\n Queue is Empty\n");
        return;
    }
    printf("\n Queue is not Empty \n");
}
// Function to check if the circular queue is full
void isFull() {
    if ((rear + 1) % MAX == front)
        printf("\n Queue is full\n");
    else {
        printf("\n Queue is not full \n");
    }
}
// Function to display the elements of the circular queue
void display() {
    if (front == -1 && rear == -1) {
        printf("\n Queue is empty.\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d \t", arr[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {
    printf("We added element in Queue \n");
    add(1);
    add(2);
    add(3);
    add(4);
 printf("We added Four Element in our Queue \n") ;  
 display();
 printf("We added an other Element in our Queue \n") ;  
 add(5);
 display();
 printf("\n We check our queue is empty or not and full or not \n");
 isEmpty();
 isFull();
 printf("After deleting one element our queue \n");
 delete();
 display();
  printf("After deleting two element our queue \n");
 delete();
 delete();
 display();
 printf("\n We check our queue is empty or not and full or not \n");
 isEmpty();
 isFull();
 printf("We added an other Element in our Queue \n") ;  
 add(23);
  add(19);
   add(56);
    display();
     printf("\n We check our queue is empty or not and full or not \n");
     isEmpty();
 isFull();
    return 0;
}
// We added element in Queue 
// We added Four Element in our Queue
// 1       2       3       4
// We added an other Element in our Queue
// 1       2       3       4       5

//  We check our queue is empty or not and full or not 

//  Queue is not Empty

//  Queue is full
// After deleting one element our queue
// 2       3       4       5
// After deleting two element our queue
// 4       5

//  We check our queue is empty or not and full or not 

//  Queue is not Empty

//  Queue is not full
// We added an other Element in our Queue
// 4       5       23      19      56

//  We check our queue is empty or not and full or not 

//  Queue is not Empty

//  Queue is full