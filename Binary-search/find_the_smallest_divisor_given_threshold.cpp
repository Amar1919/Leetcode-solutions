//Problem:Find the Smallest Divisor Given a Threshold
//Link:https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
//Approach:Used binary search on the divisor. For each divisor, calculated the sum of all elements after ceiling division and searched for the smallest divisor whose sum is less than or equal to the threshold.
//Time Complexity:O(n log(max(nums)))
//Space Complexity:O(1)



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=0;

        while(low<=high) {
            int mid=low+(high-low)/2;
            int sum=0;
            for(int i=0;i<nums.size();i++) {
                float res=(float)nums[i]/mid;
                sum+=ceil(res);
            }
            if(sum<=threshold) {
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
};