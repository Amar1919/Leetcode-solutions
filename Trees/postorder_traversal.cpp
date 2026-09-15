// Problem: Binary Tree Postorder Traversal

// Approach: Use recursion to visit both subtrees before the current node.

// Recursively traverse the left subtree, then the right subtree, and finally process the root.

// Follow the order: Left → Right → Root.

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
    void postorder(TreeNode* root,vector<int>& ans) {
        if(root==NULL) return;

        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};

        vector<int> ans;
        postorder(root,ans);

        return ans;
        
    }
};