// Problem: Add Two Numbers represented by Linked Lists

// Approach: Traverse both lists while maintaining a carry from the previous addition.

// Add corresponding digits and create a new node with sum % 10.

// Continue until both lists and carry are exhausted.

// Time Complexity: O(max(n, m)) | Space Complexity: O(max(n, m))


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;

        int carry=0;

        while(l1 || l2 || carry) {
            int sum=carry;
            if(l1) sum+=l1->val;
            if(l2) sum+=l2->val;
            carry=sum/10;
            temp->next=new ListNode(sum%10);

            temp=temp->next;

            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }

        return dummy->next;
        
    }
};