// Problem: Implement Stack Using Linked List

// Approach: Use a linked list with a top pointer to implement stack operations.

// Push inserts a new node at the beginning, and pop removes the top node.

// Top retrieves the top element, and isEmpty checks whether the stack is empty.

// Time Complexity: O(1) per operation | Space Complexity: O(n)




#include<bits/stdc++.h>
using namespace std;



class LinkedListStack {
    struct Node {
        int data;
        Node* next;

        Node(int x) {
            data=x;
            next=NULL;
        }
    };


Node* topNode;
public:
    LinkedListStack() {
        topNode=NULL;

    }
    
    void push(int x) {
        
        Node* newNode=new Node(x);
        newNode->next=topNode;
        topNode=newNode;
   
    }
    
    int pop() {
        if(topNode==NULL) return -1;
        if(topNode->next==NULL) {
            int val=topNode->data;
            delete topNode;
            return val;
        }
        Node* temp=topNode;
        int val=temp->data;
        topNode=topNode->next;
        delete temp;
        return val;
  
    }
    
    int top() {
        if(topNode==NULL) return -1;
        return topNode->data;
    }
    
    bool isEmpty() {
        return topNode==NULL;
  
    }
};