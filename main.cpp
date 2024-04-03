#include <iostream>
#include <vector> // Include vector header

#include "ExpressionManager.h"
#include "Queue.h"

// Recursive linear search function to find the last occurrence of a target in a vector
int recursive_linear_search_last_occurrence(const std::vector<int>& vec, int target, int index) {
    if (index < 0)
        return -1; // Base case: target not found
    if (vec[index] == target)
        return index; // Base case: target found at index
    return recursive_linear_search_last_occurrence(vec, target, index - 1); // Recursive call
}

// Modified insertion sort function to sort a list of integers
void insertion_sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    // Testing ExpressionManager class
    ExpressionManager expressionManager;
    std::string infixExpression;
    std::cout << "Enter an infix expression: ";
    std::cin >> infixExpression;

    // Check if the input infix expression has balanced parentheses using ExpressionManager class
    if (expressionManager.isBalanced(infixExpression)) {
        // If the expression is balanced, convert it to postfix notation
        std::string postfixExpression = expressionManager.infixToPostfix(infixExpression);
        std::cout << "Postfix Expression: " << postfixExpression << std::endl;
    } else {
        // If the expression is not balanced, display an error message
        std::cout << "Invalid expression. Unbalanced parentheses detected.\n";
    }

    // Testing Queue class
    Queue queue;
    queue.enqueue(1); // Enqueue element 1 into the queue
    queue.enqueue(2); // Enqueue element 2 into the queue
    queue.enqueue(3); // Enqueue element 3 into the queue

    std::cout << "Front element: " << queue.peek() << std::endl; // Display the front element of the queue
    std::cout << "Dequeuing: " << queue.dequeue() << std::endl; // Dequeue an element from the queue
    std::cout << "Front element after dequeue: " << queue.peek() << std::endl; // Display the front element after dequeue
    std::cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl; // Check if the queue is empty
    std::cout << "Queue size: " << queue.getSize() << std::endl; // Display the size of the queue

    return 0;
}