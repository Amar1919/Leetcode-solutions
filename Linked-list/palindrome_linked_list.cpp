// Problem: Palindrome Linked List

// Approach: Use slow and fast pointers to find the middle of the list.

// Reverse the second half in-place and compare it with the first half.

// If all corresponding values match, the linked list is a palindrome.

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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=NULL;
        ListNode* curr=slow;
        while(curr!=NULL) {
            ListNode* second=curr->next;
            curr->next=prev;
            prev=curr;
            curr=second;

        }
        ListNode* one=head;
        ListNode* two=prev;

        while(two) {
            if(one->val!=two->val) {
                return false;
            }
            one=one->next;
            two=two->next;
        }
        return true;

        
    }
};
