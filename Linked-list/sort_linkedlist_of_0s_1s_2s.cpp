// Problem: Sort a Linked List of 0s, 1s and 2s

// Approach: Create three separate lists for 0s, 1s and 2s using dummy nodes.

// Traverse the original list and attach each node to its corresponding list.

// Connect the three lists in the order 0 -> 1 -> 2 and terminate the final list.

// Time Complexity: O(n) | Space Complexity: O(1)


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
        ListNode* sortList(ListNode* &head) {
            ListNode zeroDummy(0);
            ListNode oneDummy(0);
            ListNode twoDummy(0);

            ListNode* zero=&zeroDummy;
            ListNode* one=&oneDummy;
            ListNode* two=&twoDummy;


            ListNode* temp=head;
            while(temp!=NULL) {
                if(temp->data==0) {
                    zero->next=temp;
                    zero=zero->next;
                } else if(temp->data==1) {
                    one->next=temp;
                    one=one->next;
                } else {
                    two->next=temp;
                    two=two->next;
                }
                temp=temp->next;
            }

            if(oneDummy.next!=NULL) {
                zero->next=oneDummy.next;
            } else {
                zero->next=twoDummy.next;
            }
            one->next=twoDummy.next;
            two->next=NULL;

            return zeroDummy.next;
        }
};