// Problem: Delete the Middle Node of a Linked List

// Approach: Use slow and fast pointers to find the middle node.

// Find the node before the middle and update its next pointer.

// Delete the middle node from the linked list.

// Time Complexity: O(n)
// Space Complexity: O(1)



#include<bits/stdc++.h>
using namespace std;




//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=head;
        while(temp->next!=slow) {
            temp=temp->next;
        }
        temp->next=slow->next;
        delete slow;
        return head;
        
    }
};