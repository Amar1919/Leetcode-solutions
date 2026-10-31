// Problem: Valid Parentheses

// Approach: Use a stack to check whether brackets are properly balanced.

// Push opening brackets and pop them when matching closing brackets are encountered.

// Return false if brackets mismatch or the stack is empty before popping.

// Time Complexity: O(n) | Space Complexity: O(n)



#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s) {
            if(c=='(' || c=='[' || c=='{') {
                st.push(c);
            } else {
                if(st.empty()) return false;
                char t=st.top();
                st.pop();
                
                if((c==')' && t!='(') || (c==']' && t!='[') || (c=='}' && t!='{')) {
                    return false;
                }

                
            }
        }
        return st.empty();
        
    }
};