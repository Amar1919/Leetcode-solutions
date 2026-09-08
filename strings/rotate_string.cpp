// Problem: Rotate String

// Approach: A string is a rotation of another if it appears as a substring in s + s.

// First check if both strings have the same length; otherwise, return false.

// Concatenate s with itself and check whether goal exists inside it.

// Time Complexity: O(n) | Space Complexity: O(n)



#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;

        s=s+s;

        if(s.find(goal)!=string::npos) {
            return true;
        } 
        return false;
        
    }
};