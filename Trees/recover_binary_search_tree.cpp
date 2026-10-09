// Problem: Recover Binary Search Tree
// Approach: Use inorder traversal to detect misplaced nodes.
// Compare each node with the previous node to find violations.
// Swap the identified nodes' values to restore the BST.
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
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    void inorder(TreeNode* root) {
        if(root==NULL) return;
        inorder(root->left);

        if(prev!=NULL && (root->val<prev->val)) {
            if(first==NULL) {
                first=prev;
                middle=root;
            } else {
                last=root;
            }
        }
        prev=root;
        inorder(root->right);

    }
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        TreeNode* prev=new TreeNode(INT_MIN);
        inorder(root); 
        if(first && last) {
            swap(first->val,last->val);
        } else if(first && middle) {
            swap(first->val,middle->val);
        }
        
        
    }
};