// Problem: Delete All Occurrences of a Target from a Doubly Linked List

// Approach: Traverse the list and delete every node whose value equals the target.

// Update the previous node's next pointer and the next node's prev pointer.

// If the target is at the head, update head to the next node.

// Time Complexity: O(n) | Space Complexity: O(1) excluding deleted nodes



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
    ListNode * deleteAllOccurrences(ListNode* head, int target) {
        if(head==NULL) return NULL;

        ListNode* temp=head;
        while(temp!=NULL) {
            if(temp->val==target) {
                ListNode* toDelete=temp;

                if(temp->prev!=NULL) {
                    temp->prev->next=temp->next;
                } else {
                    head=temp->next;
                }
                if(temp->next!=NULL) {
                    temp->next->prev=temp->prev;
                }
                temp=temp->next;
                delete toDelete;
                
            } else {
                temp=temp->next;
                
            }
        }
        return head;

    }
};