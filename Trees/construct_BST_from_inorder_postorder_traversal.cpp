// Problem: Construct Binary Tree from Inorder and Postorder Traversal
// Approach: Use the last element of postorder as the root and inorder to divide subtrees.
// Use a hash map to find the root index and calculate left and right subtree sizes.
// Recursively construct left and right subtrees using their respective index ranges.
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
    TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int is,int ie,int ps,int pe,unordered_map<int,int>& mp) {
        if(is>ie || ps>pe) return NULL;

        TreeNode* root=new TreeNode(postorder[pe]);

        int rootIdx=mp[root->val];
        int leftsize=rootIdx-is;
        int rightsize=ie-rootIdx;

        root->left=solve(inorder,postorder,is,rootIdx-1,ps,ps+leftsize-1,mp);
        root->right=solve(inorder,postorder,rootIdx+1,ie,ps+leftsize,pe-1,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;

        for(int i=0;i<inorder.size();i++) {
            mp[inorder[i]]=i;
        }

        return solve(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,mp);
        
    }
};