#include <iostream>
#include <string>
using namespace std;

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
    current->next = temp->next;

    cout << temp->data << " deleted from position "
         << position << ".\n";

    delete temp;
}

// Free remaining nodes when the complete program exits.
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

        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            if (cin.eof())
                return;

            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter an integer.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;

                if (cin.fail()) {
                    if (cin.eof())
                        return;

                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input! Enter an integer.\n";
                    break;
                }

                singlyInsertBeginning(value);
                singlyDisplay();
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;

                if (cin.fail()) {
                    if (cin.eof())
                        return;

                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input! Enter an integer.\n";
                    break;
                }

                cout << "Valid positions: 1 to "
                     << singlyLength() + 1 << "\n";

                cout << "Enter position: ";
                cin >> position;

                if (cin.fail()) {
                    if (cin.eof())
                        return;

                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input! Enter an integer.\n";
                    break;
                }

                singlyInsertAtPosition(value, position);
                singlyDisplay();
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;

                if (cin.fail()) {
                    if (cin.eof())
                        return;

                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input! Enter an integer.\n";
                    break;
                }

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

                cout << "Enter position: ";
                cin >> position;

                if (cin.fail()) {
                    if (cin.eof())
                        return;

                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input! Enter an integer.\n";
                    break;
                }

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

// ==================== STACK ====================

class Stack {
private:
    static const int MAX = 5;
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool stackEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow! Stack is full. Cannot push "
                 << val << ".\n";
            return;
        }

        top++;
        arr[top] = val;

        cout << "Successfully pushed "
             << val << " onto the stack.\n";
    }

    int pop() {
        if (stackEmpty()) {
            cout << "Stack Underflow! Stack is empty. Cannot pop element.\n";
            return -1;
        }

        int poppedVal = arr[top];
        top--;

        cout << "Popped element: " << poppedVal << "\n";
        return poppedVal;
    }

    int peek() {
        if (stackEmpty()) {
            cout << "Stack is empty! No top element available.\n";
            return -1;
        }

        cout << "Top element: " << arr[top] << "\n";
        return arr[top];
    }

    void display() {
        if (stackEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "\nStack elements (Top to Bottom): ";

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << "\n";
    }
};

void stackMenu() {
    Stack s;
    int choice, val;

    do {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Return to Main Menu\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter an integer value to push: ";
                cin >> val;
                s.push(val);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                s.display();
                break;

            case 5:
                cout << "Exiting Stack Submenu...\n";
                break;

            default:
                cout << "\n[ERROR] Invalid choice! Please select an option between 1 and 5.\n";
        }

    } while (choice != 5);
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
        cout << "Queue OVERFLOW! The queue is full. Cannot add "
             << value << ".\n";
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

// ==================== DOUBLY LINKED LIST ====================

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

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

void insertEnd(int value) {
    if (head == NULL) {
        insertBeginning(value);
        return;
    }

    Node* newNode = new Node;
    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = temp;
    temp->next = newNode;
}

void insertMiddle(int value, int position) {
    if (position < 0) {
        return;
    }

    if (position == 0) {
        insertBeginning(value);
        return;
    }

    Node* temp = head;
    int count = 0;

    while ((temp != NULL) && (count < position - 1)) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        return;
    }

    if (temp->next == NULL) {
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
    if (head == NULL) {
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    delete temp;
}

void deleteEnd() {
    if (head == NULL) {
        return;
    }

    if (head->next == NULL) {
        deleteBeginning();
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;
}

void deleteMiddle(int position) {
    if (head == NULL) {
        return;
    }

    if (position < 0) {
        return;
    }

    Node* temp = head;
    int count = 0;

    while ((temp != NULL) && (count < position)) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        return;
    }

    if (temp->prev == NULL) {
        deleteBeginning();
        return;
    }

    if (temp->next == NULL) {
        deleteEnd();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
}

void forwardTraverse() {
    Node* current = head;

    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }

    cout << "NULL" << endl;
}

void backwardTraverse() {
    if (head == NULL) {
        cout << "NULL" << endl;
        return;
    }

    Node* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->prev;
    }

    cout << "NULL" << endl;
}

int doublyLength() {
    int count = 0;
    Node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void doublyClear() {
    while (head != NULL)
        deleteBeginning();
}

void doublyMenu() {
    int choice, value, position;

    while (true) {
        cout << "\n===== DOUBLY LINKED LIST MENU =====\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at position (middle)\n";
        cout << "3. Insert at end\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete at position (middle)\n";
        cout << "6. Delete from end\n";
        cout << "7. Forward traverse\n";
        cout << "8. Backward traverse\n";
        cout << "0. Back to Linked List Menu\n";
        cout << "Positions in this list start at 0.\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            if (cin.eof())
                return;

            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter an integer.\n";
            continue;
        }

        if (choice == 0)
            return;

        if (choice < 1 || choice > 8) {
            cout << "Invalid choice! Choose 0 to 8.\n";
            continue;
        }

        if (choice >= 4 && choice <= 6 && head == NULL) {
            cout << "Cannot delete: list is empty.\n";
            continue;
        }

        if (choice >= 1 && choice <= 3) {
            cout << "Enter value: ";
            cin >> value;

            if (cin.fail()) {
                if (cin.eof())
                    return;

                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Enter an integer.\n";
                continue;
            }
        }

        if (choice == 2 || choice == 5) {
            int lastPosition = doublyLength();

            if (choice == 5)
                lastPosition--;

            cout << "Valid positions: 0 to "
                 << lastPosition << "\n";

            cout << "Enter position: ";
            cin >> position;

            if (cin.fail()) {
                if (cin.eof())
                    return;

                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Enter an integer.\n";
                continue;
            }

            if (position < 0 || position > lastPosition) {
                cout << "Invalid position.\n";
                continue;
            }
        }

        switch (choice) {
            case 1:
                insertBeginning(value);
                cout << value << " inserted.\n";
                break;

            case 2:
                insertMiddle(value, position);
                cout << value << " inserted at position "
                     << position << ".\n";
                break;

            case 3:
                insertEnd(value);
                cout << value << " inserted.\n";
                break;

            case 4:
                deleteBeginning();
                cout << "First node deleted.\n";
                break;

            case 5:
                deleteMiddle(position);
                cout << "Node at position "
                     << position << " deleted.\n";
                break;

            case 6:
                deleteEnd();
                cout << "Last node deleted.\n";
                break;

            case 7:
                cout << "Forward: ";
                forwardTraverse();
                break;

            case 8:
                cout << "Backward: ";
                backwardTraverse();
                break;
        }

        if (choice >= 1 && choice <= 6) {
            cout << "List: ";
            forwardTraverse();
        }
    }
}

// ==================== CIRCULAR LINKED LIST ====================

// Separate names from the Doubly Linked List code.
namespace CircularList {

struct Node {
    int data;
    Node* Next;
    Node* Previous;
};

Node* head = NULL;
Node* tail = NULL;
Node* current = NULL;
Node* auxiliar = NULL;

int readInt(string message) {
    string text;

    while (true) {
        cout << message;
        cin >> text;

        bool valid = true;
        int start = 0;

        if (text[0] == '-') {
            start = 1;
        }

        if (text.length() == start || text.length() > start + 9) {
            valid = false;
        }

        for (int i = start; i < text.length(); i++) {
            if (text[i] < '0' || text[i] > '9') {
                valid = false;
            }
        }

        if (valid) {
            int number = 0;

            for (int i = start; i < text.length(); i++) {
                number = number * 10 + (text[i] - '0');
            }

            if (start == 1) {
                number = -number;
            }

            return number;
        }

        cout << "Invalid input. Please enter a whole number.\n";
    }
}

// Counts how many nodes the list has.
int countNodes() {
    if (head == NULL) {
        return 0;
    }

    int count = 0;
    current = head;

    do {
        count++;
        current = current->Next;
    } while (current != head);

    return count;
}

void insertBeginning(int element) {
    Node* node = new Node();
    node->data = element;

    if (head == NULL) {
        head = node;
        tail = node;
        node->Next = node;
        node->Previous = node;
    } else {
        node->Previous = tail;
        node->Next = head;
        tail->Next = node;
        head->Previous = node;
        head = node;
    }

    cout << "Inserted " << element << " at the beginning.\n";
}

void insertEnd(int element) {
    Node* node = new Node();
    node->data = element;

    if (head == NULL) {
        head = node;
        tail = node;
        node->Next = node;
        node->Previous = node;
    } else {
        node->Next = head;
        node->Previous = tail;
        tail->Next = node;
        head->Previous = node;
        tail = node;
    }

    cout << "Inserted " << element << " at the end.\n";
}

void insertMiddle(int element, int position) {
    int size = countNodes();

    if (position < 1 || position > size + 1) {
        cout << "Invalid position. Valid range: 1 to "
             << size + 1 << ".\n";
        return;
    }

    if (position == 1) {
        insertBeginning(element);
        return;
    }

    if (position == size + 1) {
        insertEnd(element);
        return;
    }

    current = head;
    int count = 1;

    while (count < position - 1) {
        current = current->Next;
        count++;
    }

    Node* node = new Node();
    node->data = element;
    node->Next = current->Next;
    node->Previous = current;

    current->Next->Previous = node;
    current->Next = node;

    cout << "Inserted " << element
         << " at position " << position << ".\n";
}

void deleteBeginning() {
    if (head == NULL) {
        cout << "The list is empty. Nothing to delete.\n";
        return;
    }

    auxiliar = head;

    cout << "Deleted " << auxiliar->data
         << " from the beginning.\n";

    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        head = head->Next;
        head->Previous = tail;
        tail->Next = head;
    }

    delete auxiliar;
}

void deleteEnd() {
    if (head == NULL) {
        cout << "The list is empty. Nothing to delete.\n";
        return;
    }

    auxiliar = tail;

    cout << "Deleted " << auxiliar->data
         << " from the end.\n";

    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        tail = tail->Previous;
        tail->Next = head;
        head->Previous = tail;
    }

    delete auxiliar;
}

void deleteMiddle(int position) {
    int size = countNodes();

    if (size == 0) {
        cout << "The list is empty. Nothing to delete.\n";
        return;
    }

    if (position < 1 || position > size) {
        cout << "Invalid position. Valid range: 1 to "
             << size << ".\n";
        return;
    }

    if (position == 1) {
        deleteBeginning();
        return;
    }

    if (position == size) {
        deleteEnd();
        return;
    }

    current = head;
    int count = 1;

    while (count < position) {
        current = current->Next;
        count++;
    }

    auxiliar = current;

    auxiliar->Previous->Next = auxiliar->Next;
    auxiliar->Next->Previous = auxiliar->Previous;

    cout << "Deleted " << auxiliar->data
         << " from position " << position << ".\n";

    delete auxiliar;
}

void circularTraverse() {
    if (head == NULL) {
        cout << "The list is empty.\n";
        return;
    }

    current = head;

    do {
        cout << current->data;
        current = current->Next;

        if (current != head) {
            cout << " -> ";
        }

    } while (current != head);

    cout << " -> (back to head " << head->data << ")\n";
}

void circularMenu() {
    int option;

    do {
        cout << "\n=== CIRCULAR LINKED LIST ===\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at middle (position)\n";
        cout << "3. Insert at end\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from middle (position)\n";
        cout << "6. Delete from end\n";
        cout << "7. Circular traverse\n";
        cout << "0. Back\n";

        option = readInt("Choose an option: ");

        switch (option) {
            case 1:
                insertBeginning(readInt("Value: "));
                break;

            case 2: {
                int value = readInt("Value: ");
                int position = readInt("Position: ");
                insertMiddle(value, position);
                break;
            }

            case 3:
                insertEnd(readInt("Value: "));
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteMiddle(readInt("Position: "));
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                circularTraverse();
                break;

            case 0:
                break;

            default:
                cout << "Invalid option. Try again.\n";
        }

        if (option >= 1 && option <= 6) {
            cout << "Current list: ";
            circularTraverse();
        }

    } while (option != 0);
}

// Cleanup added for the combined application.
void circularClear() {
    // Break the circle so nodes can be deleted in a normal loop.
    if (tail != NULL)
        tail->Next = NULL;

    while (head != NULL) {
        Node* temp = head;
        head = head->Next;
        delete temp;
    }

    tail = NULL;
    current = NULL;
    auxiliar = NULL;
}

} // namespace CircularList

// ==================== LINKED LIST MENU ====================

void linkedListMenu() {
    int choice;

    while (true) {
        cout << "\n===== LINKED LIST MENU =====\n";
        cout << "1. Singly Linked List\n";
        cout << "2. Doubly Linked List\n";
        cout << "3. Circular Linked List\n";
        cout << "0. Back to Main Menu\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            if (cin.eof())
                return;

            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter an integer.\n";
            continue;
        }

        switch (choice) {
            case 1:
                singlyMenu();
                break;

            case 2:
                doublyMenu();
                break;

            case 3:
                CircularList::circularMenu();
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

        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            if (cin.eof())
                break;

            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter an integer.\n";
            continue;
        }

        switch (choice) {
            case 1:
                stackMenu();
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
    doublyClear();
    CircularList::circularClear();

    cout << "Program closed.\n";

    return 0;
}