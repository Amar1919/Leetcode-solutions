// Problem: Construct Binary Tree from Preorder and Inorder Traversal
// Approach: Use preorder to select the root and inorder to divide left and right subtrees.
// Use a hash map to find the root index in inorder efficiently.
// Recursively construct left and right subtrees using index ranges.
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
    TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int ps,int pe,int is,int ie,unordered_map<int,int>& mp) {
        if(ps>pe || is>ie) {
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[ps]);
        int rootIdx=mp[root->val];
        int leftsize=rootIdx-is;

        root->left=solve(preorder,inorder,ps+1,ps+leftsize,is,rootIdx-1,mp);

        root->right=solve(preorder,inorder,ps+leftsize+1,pe,rootIdx+1,ie,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;

        for(int i=0;i<inorder.size();i++) {
            mp[inorder[i]]=i;
        }
        return solve(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,mp);
        
    }
};