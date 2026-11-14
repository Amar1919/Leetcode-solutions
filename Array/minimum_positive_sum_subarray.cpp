// Problem: Minimum Positive Sum Subarray

// Approach: Generate subarrays starting from each index using nested loops.

// Maintain a running sum by adding elements one by one up to length r.

// Consider only subarrays with lengths between l and r and positive sums.

// Update the minimum positive sum; return -1 if no valid subarray exists.

// Time Complexity: O(n * r) | Space Complexity: O(1)




#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int minSum=INT_MAX;

        for(int i=0;i<n;i++) {
            int sum=0;
            for(int len=1;len<=r;len++) {
                int j=i+len-1;

                if(j>=n) break;

                sum+=nums[j];

                if(len>=l && sum>0) {
                    minSum=min(minSum,sum);
                }
            }
        }

        return (minSum==INT_MAX)?-1:minSum;
        
    }
};