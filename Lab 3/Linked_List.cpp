#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string Name) {
        name = Name;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void addNode(string name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;
    list.addNode("Alice");
    list.addNode("Bob");
    list.addNode("Charlie");

    list.display();  

    return 0;
}
