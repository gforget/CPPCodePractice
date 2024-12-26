#include <iostream>

#include "BinaryTreeSearch(notBST).h"

bool BinaryTreeSearch_notBST_::search(int n, Node* root)
{
    bool isFoundLeft = false;
    bool isFoundRight = false;
    
    //pre order traversal
    if (root != nullptr)
    {
        if (root->val == n)
        {
            return true;
        }
        else
        {
            isFoundLeft = search(n, root->left);
            isFoundRight = search(n, root->right);
        }
    }

    return isFoundLeft || isFoundRight;
}

void BinaryTreeSearch_notBST_::Execute()
{
    std::cout<<search(2, new Node{2})<<std::endl;
}
