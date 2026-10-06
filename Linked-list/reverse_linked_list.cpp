// Problem: Reverse Linked List

// Approach: Use three pointers: prev, curr, and second.
// Store the next node, reverse the current node's next pointer, and move the pointers forward.

// Continue until curr becomes NULL, then prev becomes the new head of the reversed list.

// Time Complexity: O(n)

// Space Complexity: O(1)


#include<bits/stdc++.h>
using namespace std;



// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        if(head==NULL) return NULL;
        ListNode* curr=head;

        while(curr!=NULL) {
            ListNode* second=curr->next;
            curr->next=prev;
            prev=curr;
            curr=second;
        }
        return prev;
        
    }
};