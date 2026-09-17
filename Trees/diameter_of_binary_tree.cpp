// Problem: Diameter of Binary Tree

// Approach: Use recursion to calculate the height of each subtree and update the diameter at every node.

// The diameter passing through a node is the sum of the heights of its left and right subtrees.

// Keep track of the maximum diameter found and return the height of the current subtree.

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
    int diameter=0;

    int height(TreeNode* root) {
        if(root==NULL) return 0;
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        diameter=max(diameter,leftHeight+rightHeight);
        return 1+max(leftHeight,rightHeight);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
        
    }
};