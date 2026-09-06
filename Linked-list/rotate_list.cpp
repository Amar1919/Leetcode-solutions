// Problem: Rotate a Linked List to the Right

// Approach: Find the length and connect the last node to the head to form a circular list.

// Move to the new tail at position n-k and break the circular link.

// The node after the new tail becomes the new head.

// Time Complexity: O(n) | Space Complexity: O(1)



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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        int n=1;
        while(temp->next!=NULL) {
            temp=temp->next;
            n++;
        }
        k=k%n;
        
        if(k==0) return head;
        temp->next=head;
        int steps=n-k;
        ListNode* newTail=head;
        for(int i=1;i<steps;i++) {
            newTail=newTail->next;
        }
        ListNode* newHead=newTail->next;
        newTail->next=NULL;

        return newHead;
        
        
    }
};