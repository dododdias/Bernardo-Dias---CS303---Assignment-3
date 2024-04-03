#include <iostream>

// Definition of the Queue class
class Queue {
private:
    // Node structure representing elements in the queue
    struct Node {
        int data; // Data of the node
        Node* next; // Pointer to the next node in the queue
        Node(int val) : data(val), next(nullptr) {} // Constructor to initialize node with a value
    };

    Node* front; // Pointer to the front node of the queue
    Node* rear; // Pointer to the rear node of the queue
    int size; // Current size of the queue

public:

    Queue(); // Constructor: Initializes an empty queue with null front and rear pointers and size 0
    void enqueue(int val);// Function to enqueue a new element with the given value into the queue
    int dequeue(); // Function to dequeue the front element from the queue and return its value 
    int peek(); // Function to peek and return the value of the front element without removing it from the queue
    void move_to_rear(); // Function to move the element currently at the front of the queue to the rear of the queue
    bool isEmpty(); // Function to check if the queue is empty and return true if it is, false otherwise
    int getSize(); // Function to return the current size of the queue
    ~Queue(); // Destructor: Dequeues all elements in the queue to free memory
};