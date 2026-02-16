#include <iostream>
#include <stdexcept>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
    Node *top;
    int count;

public:
    Stack() {
        top = NULL;
        count = 0;
    }

    void Push(int data) {
        Node *newNode = new Node(data);

        newNode->next = top;
        top = newNode;
        count++;
    }

    int Pop() {
        if(top == NULL) throw runtime_error("Stack is empty!");

        Node* temp = top;
        int popValue = temp->data;

        top = top->next;
        delete temp;
        count--;

        return popValue;
    }

    int Peek() {
        if(top == NULL) throw runtime_error("Stack is empty!");

        return top->data;
    }

    void Clear() {
        Node* current = top;
        while(current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        top = NULL;
        count = 0;
    }

    int Count() {
        return this->count;
    }
};

class Queue
{
    Node *front;
    Node *back;
    int count;

public:
    Queue() {
        front = back = NULL;
        count = 0;
    }

    void Enqueue(int data) {
        Node *newNode = new Node(data);

        if(front == NULL && back == NULL) {
            front = back = newNode;
        }
        else {
            back->next = newNode;
            back = newNode;
        }
        count++;
    }

    int Dequeue() {
        if(front == NULL) throw runtime_error("Queue is empty!");

        Node* temp = front;
        int nodeVal = temp->data;

        front = front->next;

        if(front == NULL) {
            back = NULL;
        } 

        delete temp;
        count--;

        return nodeVal;
    }

    int Peek() {
        if(front == NULL) throw runtime_error("Queue is empty!");

        return front->data;
    }

    void Clear() {
        Node* current = front;

        while(current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        front = back = NULL;
        count = 0;
    }

    int Count() {
        return this->count;
    }
};

int main()
{
    cout << "===STACK===" << endl;

    Stack s;

    s.Push(10);
    cout << s.Peek() << endl;
    s.Push(20);
    cout << s.Peek() << endl;
    cout << s.Count() << endl;

    cout << s.Pop() << endl;
    cout << s.Peek() << endl;
    cout << s.Count() << endl;

    s.Clear();
    cout << s.Count() << endl;

    cout << "\n===QUEUE===" << endl;

    Queue q;

    q.Enqueue(10);
    cout << q.Peek() << endl;
    cout << q.Count() << endl;
    q.Enqueue(20);
    cout << q.Count() << endl;
    cout << q.Dequeue() << endl;
    cout << q.Peek() << endl;
    cout << q.Count() << endl;

    q.Clear();
    q.Count();
}
