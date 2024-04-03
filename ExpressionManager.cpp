#include "ExpressionManager.h"
#include <iostream>

ExpressionManager::ExpressionManager() {}

// Function to check if the input expression has balanced parentheses
bool ExpressionManager::isBalanced(const std::string& expression) {
    std::stack<char> s; // Stack to store opening parentheses and brackets

    // Iterate through each character in the input expression
    for (char c : expression) {
        if (c == '{' || c == '(' || c == '[') {
            // If an opening brace/parenthesis/bracket is encountered, push it onto the stack
            s.push(c);
        } else if (c == '}' || c == ')' || c == ']') {
            // If a closing brace/parenthesis/bracket is encountered
            // Check if the stack is empty (no corresponding opening symbol)
            if (s.empty()) return false;

            // Pop the top element from the stack and compare with the current closing symbol
            char top = s.top();
            s.pop();

            // If the opening and closing symbols do not match, the expression is unbalanced
            if ((c == '}' && top != '{') || (c == ')' && top != '(') || (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    // If the stack is empty after processing the expression, it is balanced
    return s.empty();
}

// Function to convert an infix expression to postfix notation
std::string ExpressionManager::infixToPostfix(const std::string& infix) {
    std::string postfix; // String to store the postfix expression
    std::stack<char> operators; // Stack to store operators during conversion

    // Helper function to determine the precedence of operators
    auto getPrecedence = [](char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/' || op == '%') return 2;
        return 0;
    };

    // Iterate through each character in the infix expression
    for (char c : infix) {
        if (isalnum(c)) {
            // If the character is an operand, add it to the postfix expression
            postfix += c;
        } else if (c == '(') {
            // If an opening parenthesis is encountered, push it onto the stack
            operators.push(c);
        } else if (c == ')') {
            // If a closing parenthesis is encountered
            // Pop operators from the stack and add to postfix until an opening parenthesis is found
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            // Pop the opening parenthesis from the stack (if present)
            if (!operators.empty() && operators.top() == '(') {
                operators.pop();
            } else {
                // Unbalanced parentheses
                return "Invalid expression";
            }
        } else {
            // If an operator is encountered
            // Pop operators from the stack and add to postfix if they have higher or equal precedence
            while (!operators.empty() && getPrecedence(c) <= getPrecedence(operators.top())) {
                postfix += operators.top();
                operators.pop();
            }
            // Push the current operator onto the stack
            operators.push(c);
        }
    }

    // Pop any remaining operators from the stack and add to postfix
    while (!operators.empty()) {
        if (operators.top() == '(') {
            // Unbalanced parentheses
            return "Invalid expression";
        }
        postfix += operators.top();
        operators.pop();
    }

    // Return the final postfix expression
    return postfix;
}
