// Problem: Zigzag Level Order Traversal

// Approach: Use BFS with a queue to process the tree level by level.

// Store each level separately and reverse alternate levels using levelNum.

// Even levels are stored normally, while odd levels are reversed.

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        int levelNum=0;
        while(!q.empty()) {
            int size=q.size();
            vector<int> level;


            
            for(int i=0;i<size;i++) {
                TreeNode* node=q.front();
                q.pop();
                level.push_back(node->val);      
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(levelNum%2==1) {
                reverse(level.begin(),level.end());
            }
            ans.push_back(level);
            levelNum++;
            
        }
        return ans;
    }
};