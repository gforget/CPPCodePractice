#include "FunWithTreesMaxSum.h"
#include <algorithm>

//https://www.codewars.com/kata/57e5279b7cf1aea5cf000359/train/cpp

int FunWithTreesMaxSum::maxSum(TreeNode* root)
{
    std::vector<int> AllSum;
    preorderTraversal(root, 0, AllSum);
    std::sort(AllSum.begin(), AllSum.end());
    
    return AllSum[AllSum.size()-1];
}

void FunWithTreesMaxSum::preorderTraversal(TreeNode* root, int CurrentSum, std::vector<int>& AllSum)
{
    CurrentSum += root->value;
    if (root->left)
    {
        preorderTraversal(root->left, CurrentSum, AllSum);
    }

    if (root->right)
    {
        preorderTraversal(root->right, CurrentSum, AllSum);
    }

    //Arrived at a leaf, record the sum
    if (root->right == nullptr && root->left == nullptr)
    {
        AllSum.push_back(CurrentSum);
    }
}

void FunWithTreesMaxSum::Execute()
{
    //Tree node lack the Join function to test this
}
