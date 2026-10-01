// Problem: Floor and Ceil of a Binary Search Tree

// Approach: Traverse the BST iteratively while comparing the key with each node.

// If node value < key, update floor and move to the right subtree.

// If node value > key, update ceil and move to the left subtree.

// Time Complexity: O(h) | Space Complexity: O(1)




#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution { 
public:
    vector<int> floorCeilOfBST(TreeNode* root, int key) {

        int floor = -1;
        int ceil = -1;

        while(root != NULL) {

            if(key == root->data) {
                floor = root->data;
                ceil = root->data;
                break;
            }

            if(root->data < key) {
                floor = root->data;
                root = root->right;
            }
            else {
                ceil = root->data;
                root = root->left;
            }
        }

        return {floor, ceil};
    }
};