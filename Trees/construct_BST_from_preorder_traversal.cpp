// Problem: Construct BST from Preorder Traversal
// Approach: Use recursion with an upper bound to construct each subtree.
// Create a node from preorder and recursively build its left and right subtrees.
// The upper bound ensures each value is placed in the correct BST position.
// Time Complexity: O(n) | Space Complexity: O(n)



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
    TreeNode* build(vector<int>& preorder,int& i,int upper) {
        if(i==preorder.size() || preorder[i]>upper) {
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=build(preorder,i,root->val);
        root->right=build(preorder,i,upper);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MAX);
    }
};