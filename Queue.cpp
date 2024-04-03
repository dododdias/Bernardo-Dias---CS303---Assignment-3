#include "Queue.h"

// Constructor initializes an empty queue with null front and rear pointers and size 0
Queue::Queue() : front(nullptr), rear(nullptr), size(0) {}

// Enqueues a new element with the given value into the queue
void Queue::enqueue(int val) {
    // Create a new node with the given value
    Node* newNode = new Node(val);

    // If the queue is empty, set both front and rear to the new node
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        // If the queue is not empty, append the new node to the end of the queue
        rear->next = newNode;
        rear = newNode;
    }

    // Increase the size of the queue
    size++;
}

// Dequeues the front element from the queue and returns its value
int Queue::dequeue() {
    // Check if the queue is empty
    if (isEmpty()) {
        std::cerr << "Queue is empty, cannot dequeue.\n";
        return -1; // Return -1 to indicate an error
    }

    // Store the front node in a temporary pointer
    Node* temp = front;

    // Get the value of the front element
    int val = front->data;

    // Update front to the next node, delete the original front node, and decrease the size
    front = front->next;
    delete temp;
    size--;

    // Return the value of the dequeued element
    return val;
}

// Returns the value of the front element without removing it from the queue
int Queue::peek() {
    // Check if the queue is empty
    if (isEmpty()) {
        std::cerr << "Queue is empty, no front element.\n";
        return -1; // Return -1 to indicate an error
    }

    // Return the value of the front element
    return front->data;
}

// Moves the element currently at the front of the queue to the rear of the queue
void Queue::move_to_rear() {
    if (!isEmpty()) {
        // If the queue is not empty, move the front element to the rear
        int frontValue = peek();
        dequeue();
        enqueue(frontValue);
    }
}

// Checks if the queue is empty and returns true if it is, false otherwise
bool Queue::isEmpty() {
    return size == 0;
}

// Returns the current size of the queue
int Queue::getSize() {
    return size;
}

// Destructor dequeues all elements in the queue to free memory
Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}