// Problem: Two Sum
// Link: https://leetcode.com/problems/two-sum/
//Approach:Hash map
//Space complexity: O(n)
// Time Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums,int target) {
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++) {
            int need=target-nums[i];

            if(mp.find(need)!=mp.end()) {
                return {mp[need],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};