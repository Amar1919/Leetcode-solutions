// Problem: Remove Duplicates from a Sorted Doubly Linked List

// Approach: Traverse the list and compare each node with its next node.

// If duplicate, skip the next node and update the new node's prev pointer.

// Otherwise, move curr to the next node.

// Time Complexity: O(n) | Space Complexity: O(1)



#include<bits/stdc++.h>
using namespace std;



//Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};


class Solution {
public:
    ListNode * removeDuplicates(ListNode *head) {
        if(head==NULL) return head;
        ListNode* curr=head;
        while(curr!=NULL && curr->next!=NULL) {
            if(curr->val==curr->next->val) {
                ListNode* duplicate=curr->next;
                curr->next=duplicate->next;

                if(curr->next!=NULL) {
                    curr->next->prev=curr;
                }
            } else {
                curr=curr->next;
            }
        }
        return head;
    }
};