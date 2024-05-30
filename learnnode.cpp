#include <bits/stdc++.h>
using namespace std;

struct node {
    int coe;
    int index;
    struct node *next;
};
typedef struct node node;

int count(node *head) {
    int cnt = 0;
    while (head != NULL) {
        if (head->coe != 0) {
            ++cnt;
        }
        head = head->next;
    }
    return cnt;
}

node *makeNode(int a, int n) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->coe = a;
    newNode->index = n;
    newNode->next = NULL;
    return newNode;
}

void pushFront(node **head, int a, int n) {
    node *newNode = makeNode(a, n);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

void appendNode(node **head, int a, int n) {
    node *newNode = makeNode(a, n);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

node *plusNode(node *head1, node *head2) {
    node *sum = NULL;
    node *vari1 = head1;
    node *vari2 = head2;
    while (vari1 != NULL || vari2 != NULL) {
        if (vari1 == NULL) {
            appendNode(&sum, vari2->coe, vari2->index);
            vari2 = vari2->next;
        } else if (vari2 == NULL) {
            appendNode(&sum, vari1->coe, vari1->index);
            vari1 = vari1->next;
        } else if (vari1->index > vari2->index) {
            appendNode(&sum, vari1->coe, vari1->index);
            vari1 = vari1->next;
        } else if (vari1->index < vari2->index) {
            appendNode(&sum, vari2->coe, vari2->index);
            vari2 = vari2->next;
        } else {
            appendNode(&sum, vari1->coe + vari2->coe, vari1->index);
            vari1 = vari1->next;
            vari2 = vari2->next;
        }
    }
    return sum;
}

node *minusNode(node *head1, node *head2) {
    node *sum = NULL;
    node *vari1 = head1;
    node *vari2 = head2;
    while (vari1 != NULL || vari2 != NULL) {
        if (vari1 == NULL) {
            appendNode(&sum, -vari2->coe, vari2->index);
            vari2 = vari2->next;
        } else if (vari2 == NULL) {
            appendNode(&sum, vari1->coe, vari1->index);
            vari1 = vari1->next;
        } else if (vari1->index > vari2->index) {
            appendNode(&sum, vari1->coe, vari1->index);
            vari1 = vari1->next;
        } else if (vari1->index < vari2->index) {
            appendNode(&sum, -vari2->coe, vari2->index);
            vari2 = vari2->next;
        } else {
            appendNode(&sum, vari1->coe - vari2->coe, vari1->index);
            vari1 = vari1->next;
            vari2 = vari2->next;
        }
    }
    return sum;
}

int main() {
    node *head1 = NULL;
    node *head2 = NULL;
    node *res;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        pushFront(&head1, a, i);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        pushFront(&head2, b, i);
    }
    cin.ignore();
    string s;
    getline(cin, s);
    if (s == "plus") {
        res = plusNode(head1, head2);
    }
    if (s == "minus") {
        res = minusNode(head1, head2);
    }
    vector<int> v;
    node *temp = res;
    int cnt0 = 0;
    while (temp != NULL) {
        v.push_back(temp->coe);
        if(temp->coe != 0) ++cnt0;
        temp = temp->next;
    }
    if(cnt0 == 0) cout << 1 << " " << 0;
    else {
    	int cnt = count(res);
        cout << cnt << " ";
        for (int i = v.size() - 1; i >= 0; i--) {
            cout << v[i] << " ";
        }
    }
    return 0;
}
