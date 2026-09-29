// Problem: Maximum Width of Binary Tree

// Approach: Use BFS with a queue storing each node along with its position index.

// Normalize indices at every level to prevent integer overflow in deep trees.

// Calculate the width using the rightmost normalized index and update the maximum.

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
    int widthOfBinaryTree(TreeNode* root) {
        long long maxWidth=0;
        if(root==NULL) return maxWidth;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()) {
            int size=q.size();
            long long left=q.front().second;
            long long right;

            for(int i=0;i<size;i++) {
                auto [node,index]=q.front();
                q.pop();
                long long currIdx=index-left;
                right=currIdx;
                
                if(node->left) {
                    q.push({node->left,2*currIdx+1});
                } 
                if(node->right) {
                    q.push({node->right,2*currIdx+2});
                }
                
   
            }
            long long width=right+1;
            maxWidth=max(maxWidth,width);
        }

        return maxWidth;

        
    }
};