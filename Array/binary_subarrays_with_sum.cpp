//Problem:Binary Subarrays With Sum
//Link:https://leetcode.com/problems/binary-subarrays-with-sum/
//Approach:Used sliding window to count subarrays with sum at most goal and subtracted subarrays with sum at most goal-1 to get subarrays with sum exactly equal to goal.
//Time Complexity:O(n)
//Space Complexity:O(1)


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int atMost(vector<int>& nums,int goal) {
        if(goal<0) return 0;
        int left=0;
        int count=0;
        int n=nums.size();
        int sum=0;

        for(int right=0;right<n;right++) {
            sum+=nums[right];
            while(sum>goal) {
                sum-=nums[left];
                left++;
            }
            count+=right-left+1;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal)-atMost(nums,goal-1);
        
    }
};