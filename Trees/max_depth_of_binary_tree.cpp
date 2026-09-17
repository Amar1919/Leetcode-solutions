// Problem: Maximum Depth of Binary Tree

// Approach: Use recursion to find the maximum depth of both subtrees.

// Recursively find the depth of the left subtree and the right subtree,
// then take the maximum of the two and add 1 for the current node.

// For an empty tree, return 0.

// Formula: 1 + max(left subtree depth, right subtree depth).

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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);

        return 1+max(left,right);

        
        
    }
};