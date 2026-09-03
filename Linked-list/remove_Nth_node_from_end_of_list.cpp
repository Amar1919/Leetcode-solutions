// Problem: Remove Nth Node From End of List

// Approach: First calculate the length of the linked list.

// Find the node just before the Nth node from the end.

// Handle the case where the head itself needs to be removed.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        int length=0;
        ListNode* temp=head;
        while(temp!=NULL) {
            length++;
            temp=temp->next;
        }

        if(length==n) {
            ListNode* del=head;
            head=head->next;
            delete del;
            return head;
        }
        ListNode* del=head;
        for(int i=1;i<length-n;i++) {
            del=del->next;
        }
        ListNode* nodeTodelete=del->next;
        del->next=nodeTodelete->next;
        delete nodeTodelete;
        return head;
    }
};