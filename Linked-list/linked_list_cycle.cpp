// Problem: Linked List Cycle

// Approach: Use two pointers, slow and fast.
// Slow moves one step while fast moves two steps at a time.
// If they meet, a cycle exists; otherwise, fast reaches NULL.

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
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(slow && fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast) {
                return true;
            }
        }
        return false;
    }
};