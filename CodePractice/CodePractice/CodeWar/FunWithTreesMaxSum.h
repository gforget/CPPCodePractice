#pragma once
#include <vector>

class TreeNode
{
public:
    TreeNode* left;
    TreeNode* right;
    int value;
};

class FunWithTreesMaxSum
{
public:
    
    int maxSum(TreeNode* root);
    void preorderTraversal(TreeNode* root, int CurrentSum, std::vector<int>& AllSum);
    void Execute();
};
