// Problem: Delete Node in a Linked List
// Approach: Since the previous node and head are not given, copied the next node's value into the current node.
// Updated the current node's next pointer to skip the next node.
// This effectively removes the given node from the linked list.
// Time Complexity: O(1)
// Space Complexity: O(1)



#include<bits/stdc++.h>
using namespace std;



//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
        
    }
};
