#include <stdio.h>
#include <stdlib.h>


struct StackNode {
    int data;
    struct StackNode* next;
};


struct Stack {
    struct StackNode* top;
};


struct StackNode* createStackNode(int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}


void push(struct Stack* stack, int data) {
    struct StackNode* newNode = createStackNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}


int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return -1; 
    }

    int data = stack->top->data;
    struct StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);

    return data;
}

// Structure for a Queue using two stacks
struct Queue {
    struct Stack* stack1; // For enqueue operation
    struct Stack* stack2; // For dequeue operation
};

// Initialize a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = createStack();
    queue->stack2 = createStack();
    return queue;
}


void enqueue(struct Queue* queue, int data) {
    
    while (queue->stack2->top != NULL) {
        push(queue->stack1, pop(queue->stack2));
    }

    
    push(queue->stack1, data);
}


int dequeue(struct Queue* queue) {
    if (queue->stack1->top == NULL && queue->stack2->top == NULL) {
        printf("Queue is empty.\n");
        return -1; 
    }

 
    while (queue->stack1->top != NULL) {
        push(queue->stack2, pop(queue->stack1));
    }

    
    return pop(queue->stack2);
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue)); 

    return 0;
}


