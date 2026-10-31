#include <iostream>
using namespace std;

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
            cout << "Stack Overflow! Stack is full. Cannot push " << val << ".\n";
            return;
        }
        top++;
        arr[top] = val;
        cout << "Successfully pushed " << val << " onto the stack.\n";
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

int main() {
    stackMenu();
    return 0;
}