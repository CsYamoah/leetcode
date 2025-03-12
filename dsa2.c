#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node *front, *rear;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->front = obj->rear = NULL;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = x;
    newNode->next = NULL;
    if (!obj->rear) obj->front = obj->rear = newNode;
    else obj->rear->next = newNode, obj->rear = newNode;
}

int myQueuePop(MyQueue* obj) {
    if (!obj->front) return -1;
    int val = obj->front->val;
    Node* temp = obj->front;
    obj->front = obj->front->next;
    if (!obj->front) obj->rear = NULL;
    free(temp);
    return val;
}

int myQueuePeek(MyQueue* obj) {
    return obj->front ? obj->front->val : -1;
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->front == NULL;
}

void myQueueFree(MyQueue* obj) {
    while (!myQueueEmpty(obj)) myQueuePop(obj);
    free(obj);
}



