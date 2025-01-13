
#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
    node(int value) {
        data = value;
        next = NULL;
    }
};

void addnode(node*& head, int value) {
    if (head == NULL) {
        head = new node(value);
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new node(value);
    }
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    node* head = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        addnode(head, value);
        cout << "Linked List: ";
        display(head);
    }
    return 0;
}

