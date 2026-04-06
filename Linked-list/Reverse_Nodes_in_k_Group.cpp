// Problem: Reverse Nodes in k-Group
// Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
// Approach: Linked List + Recursion (reverse k nodes and connect recursively)
// Data Structure: Singly Linked List
// Space Complexity: O(n/k) (recursive stack)
// Time Complexity: O(n)


#include<bits/stdc++.h>
using namespace std;



 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:

    ListNode* reverseList(ListNode* head,int k) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* second=NULL;
        int count=0;

        while(curr!=NULL && count<k) {
            second=curr->next;
            curr->next=prev;
            prev=curr;
            curr=second;
            count++;
        }
        return prev;

    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL && count<k) {
            temp=temp->next;
            count++;
        }

        if(count<k) return head;

        ListNode* newHead=reverseList(head,k);

        head->next=reverseKGroup(temp,k);

        return newHead;
   
        
    }
};