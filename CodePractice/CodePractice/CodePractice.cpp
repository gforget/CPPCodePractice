#include <iostream>
#include <stack>

struct Node {
    Node* left;
    Node* right;
    int val;
    
    // Constructor for convenience
    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

void inOrderTraversal(Node* root) {
    std::stack<Node*> stack;
    Node* current = root;
    
    while (current != nullptr || !stack.empty()) {
        // Reach the leftmost node of the current subtree
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }
        
        // Current is null, pop from stack
        current = stack.top();
        stack.pop();
        
        std::cout << current->val << " ";
        
        // Move to the right subtree
        current = current->right;
    }
}

int main()
{
    // Create a sample binary tree
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    
    std::cout << "In-Order Traversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;
    
    // Free memory (in a real application, use proper memory management)
    // This is simplified cleanup for the example
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
}