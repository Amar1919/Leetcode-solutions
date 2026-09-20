// Problem: Symmetric Tree

// Approach: Recursively compare the left and right subtrees as mirror images.

// If both nodes are NULL, return true; if one is NULL or their values differ, return false.

// Recursively compare left->left with right->right and left->right with right->left.

// Time Complexity: O(n) | Space Complexity: O(h)



#include<bits/stdc++.h>
using namespace std;



//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    bool isMirror(TreeNode* left,TreeNode* right) {
        if(left==NULL && right==NULL) return true;
        if(left==NULL || right==NULL) return false;
        if(left->val!=right->val) return false;

        return isMirror(left->left,right->right) && isMirror(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;

        return isMirror(root->left,root->right);
        
    }
};