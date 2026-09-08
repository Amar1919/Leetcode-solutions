// Problem: Isomorphic Strings

// Approach: Maintain two maps to ensure a one-to-one mapping between characters of both strings.

// For each character, check whether an existing mapping conflicts with the current mapping.

// Store both forward (s → t) and reverse (t → s) mappings to prevent duplicate mappings.

// Time Complexity: O(n) | Space Complexity: O(1)






#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,char> mp1;
        unordered_map<char,char> mp2;
    
        for(int i=0;i<s.size();i++) {

            if(mp1.count(s[i]) && mp1[s[i]]!=t[i]) {
                return false;
            }

            if(mp2.count(t[i]) && mp2[t[i]]!=s[i]) {
                return false;
            }

            mp1[s[i]]=t[i];
            mp2[t[i]]=s[i];

        }
        return true;
        
    }
};