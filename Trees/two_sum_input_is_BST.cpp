// Problem: Two Sum IV - Input is a BST

// Approach: Traverse the tree and store visited node values in an unordered_set.

// For each node, check whether (k - node value) already exists in the set.

// If found, a pair with sum k exists; otherwise, insert the current value and continue.

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
    unordered_set<int> s;
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        if(s.find(k-root->val)!=s.end()) {
            return true;
        }
        s.insert(root->val);

        return findTarget(root->left,k) || findTarget(root->right,k);
        
    }
};