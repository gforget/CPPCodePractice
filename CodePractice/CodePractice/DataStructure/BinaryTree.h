#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <queue>

template <typename T>
class BinaryTree {
public:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    BinaryTree() : root(nullptr) {}
    ~BinaryTree() {
        clear(root);
    }

    void join(const T& value) {
        if (root == nullptr) {
            root = new Node(value);
        } else {
            joinHelper(root, value);
        }
    }

    void preOrder() const {
        preOrderHelper(root);
        std::cout << std::endl;
    }

    void inOrder() const {
        inOrderHelper(root);
        std::cout << std::endl;
    }

    void postOrder() const {
        postOrderHelper(root);
        std::cout << std::endl;
    }

    void levelOrder() const {
        levelOrderHelper(root);
        std::cout << std::endl;
    }

private:
    Node* root;

    void joinHelper(Node* node, const T& value) {
        if (value < node->data) {
            if (node->left) {
                joinHelper(node->left, value);
            } else {
                node->left = new Node(value);
            }
        } else {
            if (node->right) {
                joinHelper(node->right, value);
            } else {
                node->right = new Node(value);
            }
        }
    }

    void preOrderHelper(Node* node) const {
        if (node == nullptr) return;
        std::cout << node->data << " ";
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }

    void inOrderHelper(Node* node) const {
        if (node == nullptr) return;
        inOrderHelper(node->left);
        std::cout << node->data << " ";
        inOrderHelper(node->right);
    }

    void postOrderHelper(Node* node) const {
        if (node == nullptr) return;
        postOrderHelper(node->left);
        postOrderHelper(node->right);
        std::cout << node->data << " ";
    }

    void levelOrderHelper(Node* node) const {
        if (node == nullptr) return;

        std::queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            std::cout << current->data << " ";

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

    void clear(Node* node) {
        if (node == nullptr) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
    
};

#endif // BINARYTREE_H

//To Test the Tree
//BinaryTree<int> tree;
    
// Example usage:
//tree.join(10);
//tree.join(5);
//tree.join(15);
//tree.join(3);
//tree.join(7);
//tree.join(12);
//tree.join(18);
    
//std::cout << "PreOrder Traversal: ";
//tree.preOrder();
//std::cout << std::endl;

//std::cout << "InOrder Traversal: ";
//tree.inOrder();
//std::cout << std::endl;

//std::cout << "PostOrder Traversal: ";
//tree.postOrder();
//std::cout << std::endl;

//std::cout << "LevelOrder Traversal: ";
//tree.levelOrder();
//std::cout << std::endl;