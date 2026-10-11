// Problem: Lowest Common Ancestor of a Binary Tree
// Approach: Use recursion to search both left and right subtrees.
// Return root if it is NULL, p, or q.
// If both subtrees return non-NULL, root is the LCA; otherwise return the non-NULL result.
// Time Complexity: O(n) | Space Complexity: O(h)



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
        if(root==NULL || root==p || root==q) {
            return root;
        }

        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left!=NULL && right!=NULL) {
            return root;
        }

        return left!=NULL?left:right;
        
        
    }
};