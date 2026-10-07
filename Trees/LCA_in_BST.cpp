// Problem: Lowest Common Ancestor (LCA) of Two Nodes in a BST

// Approach: Traverse the BST while comparing p and q with the current node.

// If both p and q are smaller, move to the left subtree.

// If both are larger, move to the right; otherwise, current node is the LCA.

// Time Complexity: O(h) | Space Complexity: O(1)



#include<bits/stdc++.h>
using namespace std;




//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!=NULL) {
            if(p->val<root->val && q->val<root->val) {
                root=root->left;
            } else if(p->val>root->val && q->val>root->val) {
                root=root->right;
            } else {
                return root;
            }
        }
        return NULL;

        
    }
};