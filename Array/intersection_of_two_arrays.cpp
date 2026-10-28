    // Problem: Intersection of Two Arrays

// Approach: Insert nums1 elements into a set to store unique elements.

// Iterate through nums2 and check if each element exists in the set.

// If found, add it to the result and erase it to avoid duplicates.

// Time Complexity: O(n log n + m log n) | Space Complexity: O(n)




#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        vector<int> res;
        for(int x:nums1) {
            s.insert(x);
        }

        for(int x:nums2) {
            if(s.find(x)!=s.end()) {
                res.push_back(x);
                s.erase(x);
            }
        }
        return res;
    }
};