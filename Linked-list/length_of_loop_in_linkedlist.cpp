// Problem: Find Length of Loop in Linked List

// Approach: Use slow and fast pointers to detect a cycle.

// After they meet, traverse from the meeting point until reaching it again.

// Count the nodes visited to get the length of the loop.

// Time Complexity: O(n)
// Space Complexity: O(1)



#include<bits/stdc++.h>
using namespace std;



// Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};


class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(slow && fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast) {
                int count=1;
                ListNode* temp=slow->next;
                while(temp!=slow) {
                    temp=temp->next;
                    count++;
                }
                return count;
            }
        }
        return 0;

    }
};
