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