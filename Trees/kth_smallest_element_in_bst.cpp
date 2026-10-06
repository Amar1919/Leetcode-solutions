// Problem: Find the Kth Smallest Element in a Binary Search Tree

// Approach: Perform inorder traversal because BST inorder traversal gives nodes in sorted order.

// Count each visited node and store its value when count becomes k.

// Stop processing once the kth element is found.

// Time Complexity: O(h + k) | Space Complexity: O(h)



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
    int ans=0;
    void inorder(TreeNode* root,int k,int &count) {
        if(root==NULL) return;
        inorder(root->left,k,count);
        count++;
        if(count==k) {
            ans=root->val;
            return;
        }
        inorder(root->right,k,count);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        inorder(root,k,count);

        return ans;
        
    }
};