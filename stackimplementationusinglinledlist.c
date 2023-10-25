#include <stdio.h>
#include <stdlib.h>
// we create stack 
struct Node {
    int data;
    struct Node* next;
};
// create top in stack
struct Stack {
    struct Node* top;
};
//we are create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// first of static value null
void initStack(struct Stack* stack) {
    stack->top = NULL;
}
//to ckeck our stack is empty or not
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}
// push element in stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}
//delete element 
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    int poppedData = stack->top->data;
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return poppedData;
}
// find peek element
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    return stack->top->data;
}
//display stack
void display(struct Stack* stack) {
    struct Node* current = stack->top;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Stack stack;
    initStack(&stack);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    display(&stack); // Output: 3 -> 2 -> 1 -> NULL
    printf("Peek: %d\n", peek(&stack)); // Output: Peek: 3
    int poppedItem = pop(&stack);
    printf("Popped: %d\n", poppedItem);
    push(&stack, 43);
    push(&stack, 376);
     display(&stack); 
     printf("Peek: %d\n", peek(&stack)); // Output: Peek: 3
 poppedItem = pop(&stack);
    printf("Popped: %d\n", poppedItem);
    push(&stack, 43);
}
//3 -> 2 -> 1 -> NULL
//Peek: 3
//Popped: 3
//376 -> 43 -> 2 -> 1 -> NULL
//Peek: 376
//Popped: 376

