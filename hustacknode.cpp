#include <bits/stdc++.h>
using namespace std;

struct node{
    int coe;
    int index;
    struct node *next;
};
typedef struct node node;

int count(node *head){
    int cnt = 0;
    node *tmp = *head;
    while(tmp != NULL){
        if(tmp->coe != 0){
            ++cnt;
        }
        tmp = tmp->next;
    }
    return cnt;
}

node *makeNode(int a, int n){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->coe = a;
    newNode->index = n;
    newNode->next = NULL:
    return newNode;
}

void pushFront(node **head, int a, int n){
    node *newNode = makeNode(a, n);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

node *plusNode(node *head1, node *head2){
    node *sum = NULL;
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    node *vari1 = head1;
    node *vari2 = head2;
    while(vari1 != NULL && vari2 != NULL){
        if (vari1->index > vari2->index){
            sum->coe = vari1->coe;
            sum->index = vari1->index;
            vari1 = vari1->next;
        }
        else if (vari1->index < vari2->index){
            sum->coe = vari2->coe;
            sum->index = vari2->index;
            vari2 = vari2->next;
        }
        else (vari1->index == vari2->index){
            sum->coe = vari1->coe + vari2->coe;
            sum->index = vari1->index;
            vari1 = vari1->next;
            vari2 = vari2->next;
        }
        sum = sum->next;
    }
    return sum;
}
node *minusNode(node *head1, node *head2){
    node *sum = NULL;
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    node *vari1 = head1;
    node *vari2 = head2;
    while(vari1 != NULL && vari2 != NULL){
        if (vari1->index > vari2->index){
            sum->coe = vari1->coe;
            sum->index = vari1->index;
            vari1 = vari1->next;
        }
        else if (vari1->index < vari2->index){
            sum->coe = - vari2->coe;
            sum->index = vari2->index;
            vari2 = vari2->next;
        }
        else (vari1->index == vari2->index){
            sum->coe = vari1->coe - vari2->coe;
            sum->index = vari1->index;
            vari1 = vari1->next;
            vari2 = vari2->next;
        }
        sum = sum->next;
    }
    return sum;
}

int main(){
    node *head1 = NULL;
    node *head2 = NULL;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        pushFront(&head1, a, i);
    }
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int b; cin >> b;
        pushFront(&head2, b, i);
    }
    cin.ignore();
    string s;
    gets(cin, s);
    if (s == "plus") {
        node *res = plusNode(head1, head2);
    }
    if(s == "minus"){
        node *res = minusNode(head1, head2);
    }
    vector<int> v;
    int cnt = count(res);
    cout << cnt << " ";
    for(int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
    return 0;
}