//Problem:Max Consecutive Ones III
//Link:https://leetcode.com/problems/max-consecutive-ones-iii/
//Approach:Used sliding window to maintain a window containing at most k zeros.
//Moved the left pointer when the number of zeros exceeded k.
//Time Complexity:O(n)
//Space Complexity:O(1)


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        int ans=INT_MIN;
        int zeros=0;

        for(int right=0;right<n;right++) {
            if(nums[right]==0) {
                zeros++;
            }
            while(zeros>k) {
                if(nums[left]==0) {
                    zeros--;
                }
                left++;
            }
            ans=max(ans,right-left+1);

            
        }
        return ans;
        
    }
};