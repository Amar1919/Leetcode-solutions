// Problem: Implement Stack Using Array

// Approach: Use an array and a top index to implement stack operations.

// Push inserts an element, pop removes and returns the top element, and top retrieves it.

// isEmpty checks whether the stack is empty; overflow and underflow are handled.

// Time Complexity: O(1) per operation | Space Complexity: O(1)



#include<bits/stdc++.h>
using namespace std;




class ArrayStack {
    int arr[100];
    int topIdx;
public:
    ArrayStack() {
        topIdx=-1;
    }
    
    void push(int x) {
        if(topIdx==99) {
            return;
        }
        arr[++topIdx]=x;
   
    }
    
    int pop() {
        if(topIdx==-1) {
            return -1;
        }
        int popped=arr[topIdx];
        topIdx--;
        return popped;
  
    }
    
    int top() {
        if(topIdx==-1) {
            return -1;
        }
        return arr[topIdx];
    
    }
    
    bool isEmpty() {
        return topIdx==-1;
  
    }
};