#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void insertBeginning(int value) {
    Node* newNode = new Node;
    
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;
    if(head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

void insertEnd(int value) {
    if(head == NULL) {
        insertBeginning(value);
        return;
    }

    Node* newNode = new Node;
    Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = temp;
    temp->next = newNode;
}

void insertMiddle(int value, int position) {
    if(position < 0) {
        return;
    }

    if(position == 0) {
        insertBeginning(value);
        return;
    }
    
    Node* temp = head;
    int count = 0;

    while((temp != NULL) && (count < position - 1)) {
        temp = temp->next;
        count++;
    }

    if(temp == NULL) {
        return;
    }

    if(temp->next == NULL) {
        insertEnd(value);
        return;
    }

    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteBeginning() {
    if(head == NULL) {
        return;
    }

    Node* temp = head;
    head = head->next;
    
    if(head != NULL) {
        head->prev = NULL;
    }
    
    delete temp;
}

void deleteEnd() {
    if(head == NULL) {
        return;
    }

    if(head->next == NULL) {
        deleteBeginning();
        return;
    }

    Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;
}

void deleteMiddle(int position) {
    if(head == NULL) {
        return;
    }

    if(position < 0) {
        return;
    }

    Node* temp = head;
    int count = 0;

    while((temp != NULL) && (count < position)) {
        temp = temp->next;
        count++;
    }

    if(temp == NULL) {
        return;
    }

    if(temp->prev == NULL) {
        deleteBeginning();
        return;
    }

    if(temp->next == NULL) {
        deleteEnd();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void forwardTraverse() {
    Node* current = head;

    while(current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void backwardTraverse() {
    if(head == NULL) {
        cout << "NULL" << endl;
        return;
    }

    Node* current = head;

    while(current->next != NULL) {
        current = current->next;
    }

    while(current != NULL) {
        cout << current->data << " -> ";
        current = current->prev;
    }
    cout << "NULL" << endl;
}

int main() {
    insertBeginning(11);
    insertBeginning(22);
    insertBeginning(33);
    insertEnd(40);
    insertMiddle(64, 2);
    
    deleteMiddle(1);
    deleteBeginning();
    deleteEnd();

    forwardTraverse();
    backwardTraverse();
}