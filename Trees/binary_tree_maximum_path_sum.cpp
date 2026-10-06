// Problem: Binary Tree Maximum Path Sum

// Approach: Recursively calculate the maximum path sum that can be extended
// from each node to its parent. At each node, calculate left + right + node->val
// as a complete path through the node and update maxi. Return only
// max(left, right) + node->val because a parent can extend through only one side.

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
    int maxPathDown(TreeNode* root,int &maxi) {
        if(root==NULL) return 0;
        int left=max(0,maxPathDown(root->left,maxi));
        int right=max(0,maxPathDown(root->right,maxi));
        maxi=max(maxi,right+left+root->val);
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxPathDown(root,maxi);
        return maxi;
        
    }
};