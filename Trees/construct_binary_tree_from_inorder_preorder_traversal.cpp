// Problem: Construct Binary Tree from Preorder and Inorder Traversal

// Approach: Use the first element of preorder as the root and find it in inorder.

// Calculate the left subtree size using the root's position in inorder.

// Recursively construct the left and right subtrees using the corresponding ranges.

// Time Complexity: O(n²) | Space Complexity: O(n)




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
    TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int ps,int pe,int is,int ie) {
        if(ps>pe || is>ie) return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        int rootIdx=is;

        while(inorder[rootIdx]!=root->val) {
            rootIdx++;

        }

            int leftSize=rootIdx-is;

            root->left=solve(preorder,inorder,ps+1,ps+leftSize,is,rootIdx-1);

            root->right=solve(preorder,inorder,ps+leftSize+1,pe,rootIdx+1,ie);

            
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return solve(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
        
    }
};