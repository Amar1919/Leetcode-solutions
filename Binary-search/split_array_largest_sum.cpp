// Problem: Split Array Largest Sum
// Approach: Applied binary search on the maximum allowed subarray sum and counted the subarrays needed.
// If the array can be split into at most k subarrays, searched for a smaller maximum sum; otherwise increased it.
// Time Complexity: O(n * log(sum(nums)))
// Space Complexity: O(1)


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int countSubarrays(vector<int>& nums,int maxSum) {
        int sum=0;
        int subArrays=1;

        for(int i=0;i<nums.size();i++) {
            if(sum+nums[i]>maxSum) {
                subArrays++;
                sum=nums[i];
            } else {
                sum+=nums[i];
            }
        }
        return subArrays;
    }

    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=0;

        while(low<=high) {
            int mid=low+(high-low)/2;

            int parts=countSubarrays(nums,mid);

            if(parts<=k) {
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
        
    }
};