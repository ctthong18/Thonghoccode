#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

int count(node *head){
    int cnt = 0;
    while(head != NULL){
        head = head->next;
    }
    return cnt;
}
node *makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void pushFront(node **head, int x){
    node *newNode = makeNode(x);
    newNode->next = (*head);
    if(*head != NULL) (*head)->prev = newNode;
    (*head) = newNode;
}
void pushBack(node **head, int x){
    node *newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode; return;
    }
    node *tmp = *head;
    while((tmp)->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->prev = tmp;

    *head = newNode;
}
void pushMid(node **head, int k, int x){
    int n = count(*head);
    node *newNode = makeNode(x);
    if(k < 1 || k > n) return;
    else if(k == 1){
        pushFront(head, x);
        return;
    }
    node *tmp = *head;
    for(int i = 1; i < k; i++){
        tmp = tmp->next;
    }
    newNode->next = tmp;
    tmp->prev->next = newNode;
    newNode->prev = tmp->prev;
    tmp->prev = newNode;
}
int main(){
    node *head = NULL;

    return 0;
}