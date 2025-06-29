#include <iostream>
#include <string>
using namespace std;

class DoublyNode {
public:
    string name;
    DoublyNode* next;
    DoublyNode* prev;

    DoublyNode(string Name) {
        name = Name;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    DoublyNode* head;
    DoublyNode* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void addNode(string name) {
        DoublyNode* newNode = new DoublyNode(name);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayForward() {
        DoublyNode* temp = head;
        while (temp != nullptr) {
            cout << temp->name << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayBackward() {
        DoublyNode* temp = tail;
        while (temp != nullptr) {
            cout << temp->name << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    ~DoublyLinkedList() {
        DoublyNode* current = head;
        while (current != nullptr) {
            DoublyNode* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    DoublyLinkedList dList;
    dList.addNode("Alice");
    dList.addNode("Bob");
    dList.addNode("Charlie");

    cout << "Doubly Linked List (Forward): ";
    dList.displayForward();

    cout << "Doubly Linked List (Backward): ";
    dList.displayBackward();

    return 0;
}
