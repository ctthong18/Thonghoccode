#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node node;
node *makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void push(node **head, int x){
    node *newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode; return;
    }
    newNode->next = *head;
    *head = newNode;
}
void pop(node **head){
    if(*head != NULL){
        node *tmp = *head;
        (*head) = tmp->next;
        free (tmp);
    }
}
int top(node *head){
    if(head != NULL){
        return head->data;
    }
}
void print(node *head){
    while(head != NULL){
        printf("%d", head->data); printf(" ");
        head = head->next;
    }
    printf("\n");
}
int back(node *head){
    if(head->next != NULL){
        head = head->next;
    }
    return head->data;
}
int count(node *head){
    int cnt = 0;
    while(head != NULL){
        ++cnt;
        head = head->next;
    }
    return cnt;
}
int main(){
    node *head = NULL;
    for(int i = 0; i < 7; i++){
        push(&head, i);
    }
    printf("%d\n", count(head));
    printf("%d\n", top(head));
    printf("%d\n", back(head));

    return 0;
}