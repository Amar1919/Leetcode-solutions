// Problem: Find All Pairs with a Given Sum in a Sorted Doubly Linked List

// Approach: Use two pointers, left at the head and right at the tail.

// If sum equals target, store the pair and move both pointers inward.

// If sum is smaller, move left forward; otherwise move right backward.

// Time Complexity: O(n) | Space Complexity: O(1) excluding the output



#inlcude<bits/stdc++.h>
using namespace std;



class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev; 

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};


class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        vector<vector<int>> ans;
        if(head==NULL) return ans;
        ListNode* left=head;
        ListNode* right=head;
        while(right->next!=NULL) {
            right=right->next;
        }

        while(left!=right && left->prev!=right) {
            if(left->val+right->val==target) {
                ans.push_back({left->val,right->val});
                left=left->next;
                right=right->prev;
            } else if(left->val+right->val<target) {
                left=left->next;
            } else {
                right=right->prev;
            }
        }
        return ans;
    }
};