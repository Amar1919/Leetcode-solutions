// Problem: Contains Duplicate

// Approach: Use an unordered_set to store encountered elements.

// Iterate through nums and check if each element already exists in the set.

// If found, return true; otherwise, insert it and return false after the loop.

// Time Complexity: O(n) average | Space Complexity: O(n)



#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int x:nums) {
            if(s.find(x)!=s.end()) {
                return true;
            }
            s.insert(x);
        }
        return false;

        
    }
};