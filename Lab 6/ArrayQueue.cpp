#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    static const int MAX_SIZE = 100;
    string arr[MAX_SIZE];
    int front;
    int rear;
    int count;

public:
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isFull() const {
        return count == MAX_SIZE;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void Enqueue(const string& name) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = name;
        count++;
    }

    void Dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        front = (front + 1) % MAX_SIZE;
        count--;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % MAX_SIZE;
            cout << arr[index] << " -> ";
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Queue queue;
    queue.Enqueue("Alice");
    queue.Enqueue("Bob");
    queue.Enqueue("Charlie");
    queue.Enqueue("Low Ren");

    queue.display();

    queue.Dequeue();
    queue.display();

    return 0;
}
