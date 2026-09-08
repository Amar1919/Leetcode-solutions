// Problem: Longest Common Prefix

// Approach: Take the first string as the initial prefix and compare it with every other string.

// If the current string does not start with the prefix, keep removing the last character from the prefix.

// Continue until the prefix matches the current string; if it becomes empty, return "".

// Time Complexity: O(N * M) | Space Complexity: O(M)





#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix=strs[0];

        for(int i=1;i<strs.size();i++) {
            while(strs[i].find(prefix)!=0) {
                prefix=prefix.substr(0,prefix.size()-1);
            }
            if(prefix.empty()) return "";
        }
        return prefix;
    }
};