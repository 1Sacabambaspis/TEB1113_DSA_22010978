
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

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void Enqueue(string name) {
        Node* newNode = new Node(name);

        if (front == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void Dequeue(){
        if(front == nullptr){
            cout<<"Queue is empty!!"<<endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    void display() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~Queue() {
        Node* current = front;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    Queue queue;
    queue.Enqueue("Alice");
    queue.Enqueue("Bob");
    queue.Enqueue("Charlie");
    queue.Enqueue("Low Ren");

    queue.display();  

    return 0;
}
