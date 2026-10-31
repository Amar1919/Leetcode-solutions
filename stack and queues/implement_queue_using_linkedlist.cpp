// Problem: Implement Queue Using Linked List

// Approach: Use a linked list with front and rear pointers to implement queue operations.

// Push inserts a new node at the rear, and pop removes the front node.

// Peek retrieves the front element, and isEmpty checks whether the queue is empty.

// Time Complexity: O(1) per operation | Space Complexity: O(n)




#include<bits/stdc++.h>
using namespace std;



class LinkedListQueue {
    struct Node {
        int data;
        Node* next;

        Node(int x) {
            data=x;
            next=NULL;
        }
    };
    Node* front;
    Node* rear;
public:
    LinkedListQueue() {
        front=NULL;
        rear=NULL;
    }
    
    void push(int x) {
        Node* newNode=new Node(x);
        if(front==NULL) {
            front=rear=newNode;
            return;
        }
        rear->next=newNode;
        rear=newNode;
   
    }
    
    int pop() {
        if(front==NULL) {
            return -1;
        }
        Node* temp=front;
        int val=temp->data;

        front=front->next;

        if(front==NULL) {
            rear=NULL;
        }
        delete temp;
        return val;

    }
    
    int peek() {
        if(front==NULL) return -1;
        return front->data;
    
    }
    
    bool isEmpty() {
        return front==NULL;
  
    }
};