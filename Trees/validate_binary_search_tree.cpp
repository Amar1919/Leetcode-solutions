// Problem: Validate a Binary Search Tree

// Approach: Perform inorder traversal, which should produce values in strictly increasing order.

// Maintain the previous visited value and compare it with the current node's value.

// If current value is <= previous value, the tree is not a valid BST.

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
    long prev=LONG_MIN;
    bool inorder(TreeNode* root) {
        if(root==NULL) return true;
        if(!inorder(root->left)) return false;

        if(root->val<=prev) {
            return false;
        }
        prev=root->val;

        return inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        return inorder(root);
        
    }
};