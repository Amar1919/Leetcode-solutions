//Problem:Find the Smallest Missing Multiple of K
//Link:https://leetcode.com/problems/smallest-missing-multiple-of-k/
//Approach:Used an unordered_set to store all elements for fast lookup. Started from k and checked k, 2k, 3k... until finding the first multiple that was not present.
//Time Complexity:O(n) average
//Space Complexity:O(n)



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(),nums.end());
        int multiple=k;
        while(true) {
            if(st.find(multiple)==st.end()) {
                return multiple;
            } else {
                multiple+=k;
            }

        }
        
        
    }
};