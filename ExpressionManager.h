#include <string>
#include <stack>

class ExpressionManager {
public:
    ExpressionManager();  // Constructor declaration
    bool isBalanced(const std::string& expression);  // Function to check balanced parentheses
    std::string infixToPostfix(const std::string& infix);  // Function to convert infix to postfix notation
};
