// Problem: Odd Even Linked List

// Approach: Maintain separate pointers for odd and even positioned nodes.

// Rearrange the next pointers to group all odd nodes followed by even nodes.

// Connect the odd list to the head of the even list.

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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenHead=even;

        while(even && even->next) {
            odd->next=even->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenHead;

        return head;

        
    }
};
