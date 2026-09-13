// Problem: Maximum Nesting Depth of Parentheses

// Approach: Track the current nesting depth and keep the maximum depth reached.

// For '(' increase the depth, and for ')' decrease the depth.

// Update the answer whenever the current depth increases.

// Time Complexity: O(n) | Space Complexity: O(1)




#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int ans=0;

        for(char c:s) {
            if(c=='(') {
                depth++;
                ans=max(ans,depth);
            } else if(c==')') {
                depth--;
            }
        }
        return ans;
    }
};