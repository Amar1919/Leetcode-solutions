// Problem: Implement Stack Using Queue

// Approach: Use a single queue and rearrange elements to follow LIFO order.

// Push inserts an element and moves previous elements behind it.

// Pop removes and returns the front element; top retrieves it, and empty checks whether the stack is empty.

// Time Complexity: O(n) for push, O(1) for pop/top/empty | Space Complexity: O(n)




#include<bits/stdc++.h>
using namespace std;



class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);

        for(int i=0;i<q.size()-1;i++) {
            q.push(q.front());
            q.pop();
        }
        
    }
    
    int pop() {
        int val=q.front();
        q.pop();
        return val;
        
    }
    
    int top() {
        return q.front();
        
    }
    
    bool empty() {
        return q.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */