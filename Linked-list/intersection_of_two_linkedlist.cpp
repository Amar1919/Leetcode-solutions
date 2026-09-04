// Problem: Intersection of Two Linked Lists

// Approach: Use two pointers to traverse both linked lists.

// When a pointer reaches the end, switch it to the head of the other list.

// Both pointers will meet at the intersection node or NULL if no intersection exists.

// Time Complexity: O(n + m)

// Space Complexity: O(1)



#include<bits/stdc++.h>
using namespace std;



//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;

        while(tempA!=tempB) {
            if(tempA==NULL) {
                tempA=headB;
            } else {
                tempA=tempA->next;
            }

            if(tempB==NULL) {
                tempB=headA;
            } else {
                tempB=tempB->next;
            }
        }

        return tempA;
        
        
    }
};