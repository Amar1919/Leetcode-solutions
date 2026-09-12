// Problem: Remove Outermost Parentheses

// Approach: Track the nesting depth of parentheses and skip the outermost pair.

// For '(' add it only when depth > 0, then increase depth.

// For ')' decrease depth first, then add it only when depth > 0.

// This removes the outermost parentheses from every primitive group.

// Time Complexity: O(n) | Space Complexity: O(n)



#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int depth=0;

        for(char c:s) {
            if(c=='(') {
                if(depth>0) {
                    ans+=c;
                }
                depth++;
            } else {
                depth--;
                if(depth>0) {
                    ans+=c;
                }
            }

            
        }
        return ans;
        
    }
};