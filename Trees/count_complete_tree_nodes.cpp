// Problem: Count Complete Tree Nodes

// Approach: Use the height of the leftmost and rightmost paths to identify perfect subtrees.

// If both heights are equal, calculate the number of nodes directly using 2^h - 1.

// Otherwise, recursively count the nodes in the left and right subtrees.

// Time Complexity: O(log² n) | Space Complexity: O(log n)



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
    int leftHeight(TreeNode* root) {
        int h=0;
        while(root) {
            h++;
            root=root->left;
        }
        return h;
    }

    int rightHeight(TreeNode* root) {
        int h=0;
        while(root) {
            h++;
            root=root->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        int lh=leftHeight(root);
        int rh=rightHeight(root);

        if(lh==rh) {
            return (1<<lh)-1;
        }

        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};