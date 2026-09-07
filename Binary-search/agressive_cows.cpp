// Problem: Aggressive Cows

// Approach: Sort the stalls and use binary search on the minimum possible distance.

// For each distance, greedily place cows in the earliest possible stalls to check if all k cows can be placed.

// If possible, increase the distance; otherwise decrease it.

// Time Complexity: O(n log n + n log(maxDistance)) | Space Complexity: O(1) excluding sorting



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:


    bool canWePlace(vector<int>& stalls,int dist,int cows) {
        int countCows=1;
        int last=stalls[0];

        for(int i=1;i<stalls.size();i++) {
            if(stalls[i]-last>=dist) {
                countCows++;
                last=stalls[i];
            }
            if(countCows>=cows) return true;
        }
        return false;
    }


    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=1;
        int high=nums[n-1]-nums[0];

        while(low<=high) {
            int mid=low+(high-low)/2;
            if(canWePlace(nums,mid,k)==true) {
                low=mid+1;
            } else {
                high=mid-1;
            }
        }
        return high;
    }
};