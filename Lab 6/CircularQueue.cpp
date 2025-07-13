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

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = nullptr;
        rear = nullptr;
    }

    void Enqueue(string name) {
        Node* newNode = new Node(name);

        if (front == nullptr) {
            front = newNode;
            rear = newNode;
            rear->next = front;  // Circular link
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;  // Maintain circular link
        }
    }

    void Dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        if (front == rear) {
            // Only one element
            cout << "Dequeued: " << front->name << endl;
            delete front;
            front = nullptr;
            rear = nullptr;
        } else {
            Node* temp = front;
            cout << "Dequeued: " << temp->name << endl;
            front = front->next;
            rear->next = front;  // Update circular link
            delete temp;
        }
    }

    void display() {
        if (front == nullptr) {
            cout << "[Queue is empty]" << endl;
            return;
        }

        Node* temp = front;
        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != front);

        // Show that rear points back to front
        cout << front->name << " (back to front)" << endl;
    }

    ~CircularQueue() {
        if (front == nullptr)
            return;

        rear->next = nullptr;  // Break the loop first
        Node* current = front;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    CircularQueue queue;

    
    queue.Enqueue("Alice");
    queue.Enqueue("Bob");
    queue.Enqueue("Charlie");
    queue.Enqueue("Low Ren");

    cout << "\nInitial Circular Queue:\n";
    queue.display();

    
    queue.Dequeue();
    cout << "\nAfter one Dequeue:\n";
    queue.display();

    
    queue.Dequeue();
    queue.Dequeue();
    queue.Dequeue();  

    cout << "\nFinal State:\n";
    queue.display();

    return 0;
}
