// Problem: Binary Tree Preorder Traversal

// Approach: Use recursion to visit each node in preorder.

// Process the root first, then recursively visit the left and right subtrees.

// Follow the order: Root → Left → Right.

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

    void preorder(TreeNode* root,vector<int>& ans) {
        if(root==NULL) return;

        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return {};

        vector<int> ans;
        preorder(root,ans);

        return ans;
    }
};