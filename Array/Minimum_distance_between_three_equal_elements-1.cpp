//Problem:Minimum Distance Between Three Equal Elements I
//Link:https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/
// Approach:Used hashmap to store the indices of the array elements 
//Time Complexity:O(n)
//Space Complexity:O(n)


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<nums.size();i++) {
            mp[nums[i]].push_back(i);
        }

        int ans=INT_MAX;

        for(auto &it:mp) {
            vector<int> v=it.second;

            if(v.size()>=3) {
                for(int i=0;i<=v.size()-3;i++) {
                    int i1=v[i];
                    int i2=v[i+1];
                    int i3=v[i+2];

                    int dis=i3-i1;
                    ans=min(ans,dis);

                }
            }
        }

        if(ans==INT_MAX) return -1;
        return ans*2;
  
    }
};

