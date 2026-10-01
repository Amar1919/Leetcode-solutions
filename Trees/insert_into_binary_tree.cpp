// Problem: Insert into a Binary Search Tree

// Approach: Recursively traverse the BST based on the value to be inserted.

// If the value is smaller, move to the left subtree.

// If the value is greater, move to the right subtree.

// Insert the new node when a NULL position is reached.

// Time Complexity: O(h) | Space Complexity: O(h)



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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) {
            return new TreeNode(val);
        }
        if(val<root->val) {
            root->left=insertIntoBST(root->left,val);
        } else {
            root->right=insertIntoBST(root->right,val);
        }

        return root;

        
    }
};