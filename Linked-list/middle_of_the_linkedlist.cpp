// Problem: Middle of the Linked List
// Approach: Use two pointers, slow and fast.
// The slow pointer moves one step at a time, while the fast pointer
// moves two steps at a time.
// When the fast pointer reaches the end of the list, the slow pointer
// will be at the middle of the linked list.

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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
        
    }
};