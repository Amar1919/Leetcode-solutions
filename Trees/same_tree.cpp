// Problem: Same Tree

// Approach: Recursively compare both trees node by node, checking their values and structure.

// If both nodes are NULL, return true; if one is NULL or their values differ, return false.

// Then recursively check whether both left subtrees and both right subtrees are identical.

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL || p->val!=q->val) return false;

        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        
    }
};