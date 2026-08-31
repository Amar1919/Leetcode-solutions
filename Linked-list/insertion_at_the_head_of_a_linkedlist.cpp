// Problem: Insert Node at Head of Linked List
// Approach: Created a new node with the given value.
// Handled the empty-list case by making the new node the head.
// Linked the new node to the current head of the list.
// Updated the head pointer and returned the new head.
// Time Complexity: O(1)
// Space Complexity: O(1) auxiliary space


#include<bits/stdc++.h>
using namespace std;



// Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};


class Solution {
    public:
        ListNode* insertAtHead(ListNode* &head, int X) {
        ListNode* temp=new ListNode(X);
        if(head==NULL) {
            head=temp;
            return head;
        }
        temp->next=head;
        head=temp;
        return head;
        }
};