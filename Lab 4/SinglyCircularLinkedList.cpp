#include <iostream>
#include <string>
using namespace std;

class CircularNode {
public:
    string name;
    CircularNode* next;

    CircularNode(string Name) {
        name = Name;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    CircularNode* head;
    CircularNode* tail;

public:
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void addNode(string name) {
        CircularNode* newNode = new CircularNode(name);
        if (head == nullptr) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        CircularNode* temp = head;
        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to " << head->name << ")" << endl;
    }

    ~CircularLinkedList() {
        if (head == nullptr) return;

        CircularNode* current = head;
        do {
            CircularNode* next = current->next;
            delete current;
            current = next;
        } while (current != head);
        head = nullptr;
    }
};

int main() {
    CircularLinkedList cList;
    cList.addNode("Xavier");
    cList.addNode("Yvonne");
    cList.addNode("Zack");

    cout << "Singly Circular Linked List: ";
    cList.display();

    return 0;
}
