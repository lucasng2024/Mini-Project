#include <iostream>
using namespace std;   
 
const int QUEUE_SIZE = 5;       
int queueArray[QUEUE_SIZE];      
int queueCount = 0;               
 
bool queueIsEmpty() {
    return queueCount == 0;
}
 
bool queueIsFull() {
    return queueCount == QUEUE_SIZE;
}
 
int queueGetNumber(string message) {
    int number;
    cout << message;
    cin >> number;
 
    while (cin.fail()) {     
        cin.clear();          
        cin.ignore(1000, '\n');
        cout << "Invalid input! Please enter a number: ";
        cin >> number;
    }
    cin.ignore(1000, '\n');  
    return number;
}
 
void queueEnqueue(int value) {
    if (queueIsFull()) {               
        cout << "Queue OVERFLOW! The queue is full. Cannot add " << value << ".\n";
    } else {
        queueArray[queueCount] = value; 
        queueCount++;                    
        cout << value << " was added to the rear of the queue.\n";
    }
}
 
void queueDequeue() {
    if (queueIsEmpty()) {                   
        cout << "Queue UNDERFLOW! The queue is empty. Nothing to remove.\n";
    } else {
        int removed = queueArray[0];       
 
        for (int i = 0; i < queueCount - 1; i++) {
            queueArray[i] = queueArray[i + 1];
        }
        queueCount--;                     
        cout << removed << " was removed from the front of the queue.\n";
    }
}
 
void queueFront() {
    if (queueIsEmpty()) {
        cout << "The queue is empty. There is no front item.\n";
    } else {
        cout << "Front item: " << queueArray[0] << "\n";
    }
}
 
void queueRear() {
    if (queueIsEmpty()) {
        cout << "The queue is empty. There is no rear item.\n";
    } else {
        cout << "Rear item: " << queueArray[queueCount - 1] << "\n";
    }
}
 
void queueDisplay() {
    if (queueIsEmpty()) {
        cout << "The queue is empty.\n";
    } else {
        cout << "Queue (front -> rear): ";
        for (int i = 0; i < queueCount; i++) {
            cout << queueArray[i] << " ";
        }
        cout << "\n";
    }
}
 
void queueMenu() {
    int choice;
 
    do {
        cout << "\n===== QUEUE MENU =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Rear\n";
        cout << "5. Display\n";
        cout << "0. Back to Main Menu\n";
 
        choice = queueGetNumber("Enter your choice: ");
        cout << "\n";
 
        if (choice == 1) {
            int value = queueGetNumber("Enter a number to add: ");
            queueEnqueue(value);
        } else if (choice == 2) {
            queueDequeue();
        } else if (choice == 3) {
            queueFront();
        } else if (choice == 4) {
            queueRear();
        } else if (choice == 5) {
            queueDisplay();
        } else if (choice == 0) {
            cout << "Going back to the main menu...\n";
        } else {
            cout << "Invalid choice! Please choose a number from 0 to 5.\n";
        }
 
    } while (choice != 0);
}
 
// ------------------------------------------------------------
// For testing this file alone only. Do NOT paste this part into
// the group's file (they already have their own main()).
// Test it with:  g++ -DQUEUE_STANDALONE queue_simple.cpp
// ------------------------------------------------------------
#ifdef QUEUE_STANDALONE
int main() {
    queueMenu();
    return 0;
}
#endif

