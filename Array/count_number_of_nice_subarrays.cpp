//Problem:Count Number of Nice Subarrays
//Link:https://leetcode.com/problems/count-number-of-nice-subarrays/
//Approach:Used a sliding window to count subarrays with at most k odd numbers. The number of subarrays with exactly k odd numbers is calculated as atMost(k)-atMost(k-1).
//Time Complexity:O(n)
//Space Complexity:O(1)


#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int nice(vector<int>& nums,int k) {
        int n=nums.size();
        int left=0;
        int count=0;
        int sum=0;

        for(int right=0;right<n;right++) {
            sum+=nums[right]%2;

            while(sum>k) {
                sum-=nums[left]%2;
                left++;
            }
            count+=right-left+1;
         }        
         return count;

    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return nice(nums,k)-nice(nums,k-1);
    }
};