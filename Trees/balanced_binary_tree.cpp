// Problem: Balanced Binary Tree

// Approach: Recursively check whether the height difference between the left and right subtrees is at most 1.

// Use maxDepth() to calculate the height of both subtrees and check abs(left height - right height) <= 1.

// Then recursively check whether both the left and right subtrees are balanced.

// Time Complexity: O(n²) | Space Complexity: O(h)



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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;

        int left=maxDepth(root->left);
        int right=maxDepth(root->right);

        return 1+max(left,right);
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);

        if(abs(lh-rh)>1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
        
    }
};