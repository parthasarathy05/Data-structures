#include <stdio.h>
#include <stdlib.h>

// Structure for a Queue Node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Structure for a Queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Create a new QueueNode
struct QueueNode* createQueueNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Initialize a new Queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Enqueue an element into the Queue
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = createQueueNode(data);
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Dequeue an element from the Queue
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return -1; // You can choose a different value to represent an empty queue
    }

    int data = queue->front->data;
    struct QueueNode* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

// Stack structure using two queues
struct Stack {
    struct Queue* q1;
    struct Queue* q2;
};

// Initialize a new stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

// Push an element onto the stack
void push(struct Stack* stack, int data) {
    enqueue(stack->q1, data);
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->q1->front == NULL) {
        printf("Stack is empty.\n");
        return -1; // You can choose a different value to represent an empty stack
    }

    // Move elements from q1 to q2, leaving the last element in q1
    while (stack->q1->front->next != NULL) {
        enqueue(stack->q2, dequeue(stack->q1));
    }

    // Pop the last element from q1
    int data = dequeue(stack->q1);

    // Swap q1 and q2 to maintain the original state
    struct Queue* temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;

    return data;
}

int main() {
    struct Stack* stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack)); // Stack is empty now

    return 0;
}
