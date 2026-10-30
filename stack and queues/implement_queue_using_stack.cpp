// Problem: Implement Queue Using a  Stack

// Approach: Use one stack and recursion to implement FIFO queue operations.

// Push inserts an element; pop recursively removes and returns the oldest element.

// Peek retrieves the oldest element without removing it; empty checks whether the queue is empty.

// Time Complexity: O(1) for push, O(n) for pop/peek | Space Complexity: O(n) due to recursion.





#include<bits/stdc++.h>
using namespace std;


class MyQueue {
public:
    stack<int> s;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);

    }
    
    int pop() {
        if(s.empty()) return  -1;

        int x=s.top();
        s.pop();

        if(s.empty()) return x;

        int res=pop();

        s.push(x);
        return res;
        

          
    }
    
    int peek() {
        if(s.empty()) return -1;

        int x=s.top();
        s.pop();

        if(s.empty()) {
            s.push(x);
            return x;
        }

        int res=peek();  

        s.push(x);
        return res;
        
    }
    
    bool empty() {
        return s.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */