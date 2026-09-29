// Problem: Maximum Width of Binary Tree

// Approach: Use BFS with a queue storing each node along with its position index.

// Normalize indices at every level to prevent integer overflow in deep trees.

// Calculate the width using the difference between the rightmost and leftmost normalized indices.

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