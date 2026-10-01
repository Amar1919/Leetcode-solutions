// Problem: Delete a Node from a Binary Search Tree

// Approach: Search for the node using BST properties and handle 0, 1, or 2 children.

// For two children, replace the node with its inorder successor (minimum of right subtree).

// Recursively delete the successor and reconnect the updated subtree.

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
    TreeNode* findMin(TreeNode* root) {
        while(root->left!=NULL) {
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;

        if(key<root->val) {
            root->left=deleteNode(root->left,key);
        } else if(key>root->val) {
            root->right=deleteNode(root->right,key);
        } else {
            if(root->left==NULL && root->right==NULL) {
                delete root;
                return NULL;
            } else if(root->left==NULL) {
                TreeNode* temp=root->right;
                delete root;
                return temp;
            } else if(root->right==NULL) {
                TreeNode* temp=root->left;
                delete root;
                return temp;
            } else {
                TreeNode* temp=findMin(root->right);
                root->val=temp->val;
                root->right=deleteNode(root->right,temp->val);

            }
        }
        return root;
        
    }
};