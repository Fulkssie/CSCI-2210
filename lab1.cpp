#include <iostream>
#include <stdexcept>
using namespace std;

// Define stack class
class Stack {
    // Pointer to an array that stores elements of the stack
    int* arr;
    // Index of the top element of the stack
    int top;
    // Maximum size of the stack
    int capacity;

    void resize() {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];
        for (int i = 0; i <= top; ++i)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    // Constructor to initialize the stack
    Stack(int size){
        // Allocate memory for the stack
        arr = new int[size];
        // Set the maximum size of the stack
        capacity = size;
        // Initialize the top of the stack as -1, indicating that the stack is empty
        top = -1;
    }

    // Destructor to deallocate the memory
    ~Stack() { delete[] arr; }

    // Function to add element x to the stack
    void push(int x)
    {
        // Double the size of the stack if there is overflow
        if (isFull()) resize();
        // Add element and increment top
        arr[++top] = x;
    }

    // Function to remove an element from the stack
    int pop()
    {
        // Check if stack is empty
        if (isEmpty()) throw runtime_error("Stack is empty!");

        // Remove element and decrement top
        return arr[top--];
    }

    // Function to return the top element of the stack
    int peek()
    {
        if (!isEmpty()) 
            return arr[top];
        else
            throw runtime_error("Stack is empty!");
    }

    // Function to clear the stack
    void clear() 
    {
        top = -1;
    }

    // Function to return the count of the stack
    int count()
    {
        return top + 1;
    }

    // Function to return if stack is empty
    bool isEmpty() { return top == -1; }

    // Function to return if stack is full
    bool isFull() { return top == capacity - 1; }

    // Iterator
    class Iterator {
        int* ptr;
    public:
        Iterator(int* p) : ptr(p) {}
        int operator*() { return *ptr; }
        Iterator& operator++() { --ptr; return *this; }
        bool operator!=(const Iterator& other) { return ptr != other.ptr; }
    };

    Iterator begin() { return Iterator(arr + top);  }
    Iterator end() { return Iterator(arr - 1); }
};

// Implement the queue data structure
class Queue {
    // Pointer to an array that stores elements of the queue
    int* arr;
    // Index of the front element of the queue
    int front;
    // Index of the back element of the queue
    int back;
    // Maximum size of the queue
    int capacity;

    void resize()
    {
    int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];
        int j = 0;
        for (int i = front; i <= back; ++i)
            newArr[j++] = arr[i];
        back = j - 1;
        front = 0;
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    // Constructor to initialize the queue
    Queue(int size) 
    {
        // Allocate memory for the queue
        arr = new int[size];
        // Set the maximum size of the queue
        capacity = size;
        // Initialize the front and back as -1
        front = -1;
        back = -1;
    }

    // Destructor
    ~Queue() { delete[] arr; }

    // Add element to queue
    void enqueue(int val)
    {
        if (isFull()) resize();
        if (isEmpty()) 
            front = 0;

        back++;
        arr[back] = val;
    }

    // Remove element from queue
    int dequeue()
    {
        if (isEmpty()) throw runtime_error("Queue is empty!");

        int ans = arr[front];
        front++;

        if (isEmpty()) 
            front = back = -1;

        return ans;
    }

     int peek()
    {
        if (!isEmpty()) 
            return arr[front];
        else
            throw runtime_error("Queue is empty!");
    }

    void clear() 
    {
        front = -1;
        back = -1;
    }

    int count()
    {
        if (isEmpty()) return 0;
        return back - front + 1;
    }

    // Function to return if stack is empty
    bool isEmpty() { return front == -1 || front > back; }

    // Function to return if stack is full
    bool isFull() { return back == capacity - 1; }


    // Iterator
    class Iterator {
        int* ptr;
    public:
        Iterator(int* p) : ptr(p) {}
        int operator*() { return *ptr; }
        Iterator& operator++() { ++ptr; return *this; }
        bool operator!=(const Iterator& other) { return ptr != other.ptr; }
    };

    Iterator begin() { return Iterator(arr + front);  }
    Iterator end() { return Iterator(arr + back + 1); }
};

int main()
{
    cout << "===STACK===" << endl;
    // Create stack of size 3
    Stack stack(2);

    // Push elements into the stack
    stack.push(10);
    stack.push(20);
    // Third push triggers the resize
    stack.push(30);

    // Print the top element of the stack
    cout << "The top element is " << stack.peek() << endl;
    // Print the count of the stack
    cout << "Stack Count: " << stack.count() << endl;

    // Iterate through the stack
    cout << "Stack Elements: ";
    for (int val : stack)
    {
        cout << val << " ";
    }
    cout << endl;

    // Pop an element from the stack and print it
    cout << "Popping " << stack.pop() << endl;
    // Print the top element of the stack
    cout << "The top element is " << stack.peek() << endl;
    // Print the 
    cout << "Stack Count: " << stack.count() << endl;

    // Clear all elements from the stack
    stack.clear();
    cout << "Stack Count: " << stack.count() << endl;

    cout << "===QUEUE===" << endl;
    // Create a queue of size 5
    Queue queue(2);

    // Enqueue elements
    queue.enqueue(1);
    queue.enqueue(2);
    // Third enqueue triggers resize
    queue.enqueue(3);

    // Print the front element of the queue
    cout << "Front Element: " << queue.peek() << endl;
    // Print the count of the queue
    cout << "Queue Count: " << queue.count() << endl;

    // Iterate throught the queue elements
    cout << "Queue Elements: ";
    for (int val : queue)
    {
        cout << val << " ";
    }
    cout << endl;

    // Dequeue elements from queue
    cout << "Dequeued element: " << queue.dequeue() << endl;

    cout << "Front Element: " << queue.peek() << endl;
    cout << "Queue Count: " << queue.count() << endl;

    // Clear all elements from the queue
    queue.clear();
    cout << "Queue Count: " << queue.count() << endl;

    return 0;
}