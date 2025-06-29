#include <iostream>
#include <string>
using namespace std;

class StackNode {
public:
    string data;
    StackNode* next;

    StackNode(string val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    StackNode* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(string val) {
        StackNode* newNode = new StackNode(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop.\n";
            return;
        }
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }

    string peek() {
        if (isEmpty()) {
            return "Stack is empty!";
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        StackNode* temp = top;
        cout << "Top -> ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack myStack;
    myStack.push("Apple");
    myStack.push("Banana");
    myStack.push("Cherry");
}