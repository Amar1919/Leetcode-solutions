// Problem: Add One to a Number Represented by a Linked List

// Approach: Reverse the linked list and add 1 starting from the least significant digit.

// Propagate the carry through the list and create a new node if a carry remains.

// Reverse the list again to restore the original order.

// Time Complexity: O(n) | Space Complexity: O(1)



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

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* second = curr->next;
            curr->next = prev;
            prev = curr;
            curr = second;
        }

        return prev;
    }

    ListNode* addOne(ListNode* head) {
        if (head == NULL) return head;

        
        head = reverse(head);

        int carry = 1;
        ListNode* temp = head;

        while (temp != NULL) {
            int sum = temp->val + carry;
            temp->val = sum % 10;
            carry = sum / 10;

            if (carry == 0) break;

            if (temp->next == NULL && carry) {
                temp->next = new ListNode(carry);
                carry = 0;
                break;
            }

            temp = temp->next;
        }

        
        head = reverse(head);

        return head;
    }
};