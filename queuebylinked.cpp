#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

node *makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void push(node **queue, int x){
    node *newNode = makeNode(x);
    if(*queue == NULL){
        *queue = newNode;
        return;
    }
    node *tmp = *queue;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}
void pop(node **queue){
    if(*queue == NULL) return;
    node *tmp = *queue;
    (*queue) = tmp->next;
    free(tmp);
}
int size(node *queue){
    int cnt = 0;
    while(queue != NULL){
        ++cnt;
        queue = queue->next;
    }
    return cnt;
}
int front(node *queue){
    return queue->data;
}
bool checkempty(node *queue){
    return queue == NULL;
}
void duyet(node *queue){
    while(queue != NULL){
        printf("%d", queue->data);
        printf(" ");
        queue = queue->next;
    }
}
int main(){
    node *queue = NULL;
    for(int i = 0; i < 9; i++){
        push(&queue, i);
    }
    printf("%d\n", front(queue));
    duyet(queue);
    pop(&queue);
    pop(&queue);
    pop(&queue);
    duyet(queue);
    return 0;
}