#include <iostream>
#include <string>
using namespace std;

class DCNode {
public:
    string name;
    DCNode* next;
    DCNode* prev;

    DCNode(string Name) {
        name = Name;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyCircularLinkedList {
private:
    DCNode* head;

public:
    DoublyCircularLinkedList() {
        head = nullptr;
    }

    void addNode(string name) {
        DCNode* newNode = new DCNode(name);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            DCNode* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        DCNode* temp = head;
        do {
            cout << temp->name << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to " << head->name << ")" << endl;
    }

    void displayBackward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        DCNode* tail = head->prev;
        DCNode* temp = tail;
        do {
            cout << temp->name << " <-> ";
            temp = temp->prev;
        } while (temp != tail);
        cout << "(back to " << tail->name << ")" << endl;
    }

    ~DoublyCircularLinkedList() {
        if (head == nullptr) return;

        DCNode* current = head->next;
        while (current != head) {
            DCNode* next = current->next;
            delete current;
            current = next;
        }
        delete head;
        head = nullptr;
    }
};

int main() {
    DoublyCircularLinkedList dcList;
    dcList.addNode("Liam");
    dcList.addNode("Mia");
    dcList.addNode("Noah");

    cout << "Doubly Circular Linked List (Forward): ";
    dcList.displayForward();

    cout << "Doubly Circular Linked List (Backward): ";
    dcList.displayBackward();

    return 0;
}
