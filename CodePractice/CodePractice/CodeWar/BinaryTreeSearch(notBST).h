#pragma once

struct Node{
    int val;
    Node *left = nullptr;
    Node *right = nullptr;
};

class BinaryTreeSearch_notBST_
{
    
public:
    bool search(int n, Node *root);
    void Execute();
};
