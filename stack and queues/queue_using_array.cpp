// Problem: Implement Queue Using Array
// Approach: Use an array with front and rear indices to implement queue operations.
// Push inserts an element at the rear, pop removes the front element, and peek retrieves it.
// isEmpty checks whether the queue is empty; overflow and underflow are handled.
// Time Complexity: O(1) per operation | Space Complexity: O(1)




#include<bits/stdc++.h>
using namespace std;




class ArrayQueue {
    int arr[100];
    int front;
    int rear;
public:
    ArrayQueue() {
        front=-1;
        rear=-1;
    }
    
    void push(int x) {
        if(rear==99) {
            return;
        }
        if(front==-1 && rear==-1) {
            front=0;
            rear=0;
            arr[rear]=x;
        } else {
            arr[++rear]=x;
        }
        
   
    }
    
    int pop() {
        if(front==-1 || front>rear) {
            return -1;
        }

        int popped=arr[front];

        if(front==rear) {
            front=-1;
            rear=-1;
        } else {
            front++;
        }
        return popped;

  
    }
    
    int peek() {
        if(front==-1 || front>rear) {
            return -1;
        }
        return arr[front];

    
    }
    
    bool isEmpty() {
        return front==-1 && rear==-1;
  
    }
};