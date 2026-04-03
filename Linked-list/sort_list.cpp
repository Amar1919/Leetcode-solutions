// Problem: Sort List
// Link: https://leetcode.com/problems/sort-list/
// Approach: Apply Merge Sort using slow-fast pointer to find middle,
//           recursively sort both halves, and merge them
// Time Complexity: O(n log n)
// Space Complexity: O(log n)   // recursion stack



#include<bits/stdc++.h>
using namespace std;



struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
public:


    ListNode* merge(ListNode* list1,ListNode* list2) {
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;

        while(list1 && list2) {
            if(list1->val<list2->val) {
                temp->next=list1;
                list1=list1->next;
            } else {
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }

        if(list1) temp->next=list1;
        if(list2) temp->next=list2;

        return dummy->next;

    }


    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;

        while(fast && fast->next) {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        prev->next=NULL;

        ListNode* list1=head;
        ListNode* list2=slow;

        list1=sortList(list1);
        list2=sortList(list2);

        return merge(list1,list2);


        
    }
};