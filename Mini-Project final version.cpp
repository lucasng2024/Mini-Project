#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Shared input validation for all menus.
bool readNumber(const string& message, int& number) {
    string line;
    char extra;

    while (true) {
        cout << message;

        if (!getline(cin, line))
            return false;

        istringstream input(line);

        if ((input >> number) && !(input >> extra))
            return true;

        cout << "Invalid input. Enter one integer.\n";
    }
}

// ==================== QUEUE ====================

const int QUEUE_SIZE = 5;
int queueArray[QUEUE_SIZE];
int queueCount = 0;

bool queueIsEmpty() {
    return queueCount == 0;
}

bool queueIsFull() {
    return queueCount == QUEUE_SIZE;
}

void queueEnqueue(int value) {
    if (queueIsFull()) {
        cout << "Queue OVERFLOW! The queue is full. Cannot add "
             << value << ".\n";
    } else {
        queueArray[queueCount] = value;
        queueCount++;

        cout << value
             << " was added to the rear of the queue.\n";
    }
}

void queueDequeue() {
    if (queueIsEmpty()) {
        cout << "Queue UNDERFLOW! The queue is empty. "
             << "Nothing to remove.\n";
    } else {
        int removed = queueArray[0];

        for (int i = 0; i < queueCount - 1; i++) {
            queueArray[i] = queueArray[i + 1];
        }

        queueCount--;

        cout << removed
             << " was removed from the front of the queue.\n";
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
        cout << "Rear item: "
             << queueArray[queueCount - 1] << "\n";
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
    int choice, value;

    while (true) {
        cout << "\n===== QUEUE MENU =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Rear\n";
        cout << "5. Display\n";
        cout << "0. Back to Main Menu\n";

        if (!readNumber("Enter your choice: ", choice))
            return;

        if (choice == 1) {
            if (!readNumber("Enter a number to add: ", value))
                return;

            queueEnqueue(value);
            queueDisplay();

        } else if (choice == 2) {
            queueDequeue();
            queueDisplay();

        } else if (choice == 3) {
            queueFront();

        } else if (choice == 4) {
            queueRear();

        } else if (choice == 5) {
            queueDisplay();

        } else if (choice == 0) {
            return;

        } else {
            cout << "Invalid choice! Choose 0 to 5.\n";
        }
    }
}

// ==================== SINGLY LINKED LIST ====================

struct SinglyNode {
    int data;
    SinglyNode* next;
};

SinglyNode* singlyHead = nullptr;

int singlyLength() {
    int count = 0;
    SinglyNode* current = singlyHead;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

void singlyDisplay() {
    if (singlyHead == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    SinglyNode* current = singlyHead;

    cout << "List: ";

    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }

    cout << "NULL\n";
}

void singlyInsertBeginning(int value) {
    SinglyNode* newNode = new SinglyNode;

    newNode->data = value;
    newNode->next = singlyHead;
    singlyHead = newNode;

    cout << value << " inserted.\n";
}

void singlyInsertEnd(int value) {
    SinglyNode* newNode = new SinglyNode;

    newNode->data = value;
    newNode->next = nullptr;

    if (singlyHead == nullptr) {
        singlyHead = newNode;
    } else {
        SinglyNode* current = singlyHead;

        while (current->next != nullptr)
            current = current->next;

        current->next = newNode;
    }

    cout << value << " inserted.\n";
}

// Positions start at 1.
void singlyInsertAtPosition(int value, int position) {
    int length = singlyLength();

    if (position < 1 || position > length + 1) {
        cout << "Invalid position. Use 1 to "
             << length + 1 << ".\n";
        return;
    }

    if (position == 1) {
        singlyInsertBeginning(value);
        return;
    }

    SinglyNode* current = singlyHead;

    for (int i = 1; i < position - 1; i++)
        current = current->next;

    SinglyNode* newNode = new SinglyNode;
    newNode->data = value;

    // Connect the new node before changing the previous link.
    newNode->next = current->next;
    current->next = newNode;

    cout << value << " inserted at position "
         << position << ".\n";
}

void singlyDeleteBeginning() {
    if (singlyHead == nullptr) {
        cout << "Cannot delete: list is empty.\n";
        return;
    }

    SinglyNode* temp = singlyHead;
    singlyHead = singlyHead->next;

    cout << temp->data << " deleted.\n";

    delete temp;
}

void singlyDeleteEnd() {
    if (singlyHead == nullptr) {
        cout << "Cannot delete: list is empty.\n";
        return;
    }

    if (singlyHead->next == nullptr) {
        singlyDeleteBeginning();
        return;
    }

    SinglyNode* current = singlyHead;

    while (current->next->next != nullptr)
        current = current->next;

    SinglyNode* temp = current->next;
    current->next = nullptr;

    cout << temp->data << " deleted.\n";

    delete temp;
}

void singlyDeleteAtPosition(int position) {
    int length = singlyLength();

    if (length == 0) {
        cout << "Cannot delete: list is empty.\n";
        return;
    }

    if (position < 1 || position > length) {
        cout << "Invalid position. Use 1 to "
             << length << ".\n";
        return;
    }

    if (position == 1) {
        singlyDeleteBeginning();
        return;
    }

    SinglyNode* current = singlyHead;

    for (int i = 1; i < position - 1; i++)
        current = current->next;

    SinglyNode* temp = current->next;

    // Bypass the node before deleting it.
    current->next = temp->next;

    cout << temp->data << " deleted from position "
         << position << ".\n";

    delete temp;
}

// Free remaining nodes only when the complete program exits.
void singlyClear() {
    while (singlyHead != nullptr) {
        SinglyNode* temp = singlyHead;
        singlyHead = singlyHead->next;
        delete temp;
    }
}

void singlyMenu() {
    int choice, value, position;

    while (true) {
        cout << "\n===== SINGLY LINKED LIST MENU =====\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at position (middle)\n";
        cout << "3. Insert at end\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete at position (middle)\n";
        cout << "6. Delete from end\n";
        cout << "7. Traverse / Display\n";
        cout << "0. Back to Linked List Menu\n";

        if (!readNumber("Enter your choice: ", choice))
            return;

        switch (choice) {
            case 1:
                if (!readNumber("Enter value: ", value))
                    return;

                singlyInsertBeginning(value);
                singlyDisplay();
                break;

            case 2:
                if (!readNumber("Enter value: ", value))
                    return;

                cout << "Valid positions: 1 to "
                     << singlyLength() + 1 << "\n";

                if (!readNumber("Enter position: ", position))
                    return;

                singlyInsertAtPosition(value, position);
                singlyDisplay();
                break;

            case 3:
                if (!readNumber("Enter value: ", value))
                    return;

                singlyInsertEnd(value);
                singlyDisplay();
                break;

            case 4:
                singlyDeleteBeginning();
                singlyDisplay();
                break;

            case 5:
                if (singlyHead == nullptr) {
                    cout << "Cannot delete: list is empty.\n";
                    break;
                }

                cout << "Valid positions: 1 to "
                     << singlyLength() << "\n";

                if (!readNumber("Enter position: ", position))
                    return;

                singlyDeleteAtPosition(position);
                singlyDisplay();
                break;

            case 6:
                singlyDeleteEnd();
                singlyDisplay();
                break;

            case 7:
                singlyDisplay();
                break;

            case 0:
                return;

            default:
                cout << "Invalid choice! Choose 0 to 7.\n";
        }
    }
}

// ==================== LINKED LIST MENU ====================

void linkedListMenu() {
    int choice;

    while (true) {
        cout << "\n===== LINKED LIST MENU =====\n";
        cout << "1. Singly Linked List\n";
        cout << "2. Doubly Linked List\n";
        cout << "3. Circular Linked List\n";
        cout << "0. Back to Main Menu\n";

        if (!readNumber("Enter your choice: ", choice))
            return;

        switch (choice) {
            case 1:
                singlyMenu();
                break;

            case 2:
                // Replace with the doubly linked list menu call.
                cout << "Doubly Linked List has not been added yet.\n";
                break;

            case 3:
                // Replace with the circular linked list menu call.
                cout << "Circular Linked List has not been added yet.\n";
                break;

            case 0:
                return;

            default:
                cout << "Invalid choice! Choose 0 to 3.\n";
        }
    }
}

// ==================== MAIN MENU ====================

int main() {
    int choice;
    bool running = true;

    while (running) {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Stack\n";
        cout << "2. Queue\n";
        cout << "3. Linked List\n";
        cout << "0. Exit\n";

        if (!readNumber("Enter your choice: ", choice))
            break;

        switch (choice) {
            case 1:
                // Replace with the stack menu call.
                cout << "Stack has not been added yet.\n";
                break;

            case 2:
                queueMenu();
                break;

            case 3:
                linkedListMenu();
                break;

            case 0:
                running = false;
                break;

            default:
                cout << "Invalid choice! Choose 0 to 3.\n";
        }
    }

    singlyClear();

    cout << "Program closed.\n";

    return 0;
}