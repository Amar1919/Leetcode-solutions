// Problem: Linked List Cycle II

// Approach: Use slow and fast pointers to detect a cycle.
// After they meet, reset slow to head and move both one step at a time.
// The point where they meet again is the starting point of the cycle.

// Time Complexity: O(n)

// Space Complexity: O(1)



#include<bits/stdc++.h>
using namespace std;



// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(slow && fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast) {
                slow=head;
                while(slow!=fast) {
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
        
    }
};