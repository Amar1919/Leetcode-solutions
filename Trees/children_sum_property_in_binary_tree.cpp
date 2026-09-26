// Problem: Children Sum Property
// Approach: Recursively check that every non-leaf node equals the sum of its children.
// Treat a missing left or right child as having value 0.
// If any node violates the children-sum property, return false.
// Time Complexity: O(n) | Space Complexity: O(h)




#include<bits/stdc++.h>
using namespace std;



class TreeNode {
public:
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };


class Solution {
public:
    bool checkChildrenSum(TreeNode* root) {
        if(root==NULL) return true;
        if(root->left==NULL && root->right==NULL) return true;
        int left=root->left!=NULL?root->left->val:0;
        int right=root->right!=NULL?root->right->val:0;
        if(root->val!=left+right) return false;
        return checkChildrenSum(root->left) && checkChildrenSum(root->right);
    }
};
