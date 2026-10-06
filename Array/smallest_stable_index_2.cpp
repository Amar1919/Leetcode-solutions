// Problem: Find the First Stable Index

// Approach: Build a suffix minimum array and maintain the prefix maximum while traversing.

// Calculate stability as prefixMax - suffixMin[i] and check if it is <= k.

// Return the first index satisfying the stability condition.

// Time Complexity: O(n) | Space Complexity: O(n)


#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=-1;
        int prefMax=nums[0];
        vector<int> suffMin(n);
        suffMin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) {
            suffMin[i]=min(nums[i],suffMin[i+1]);
        }
        
        for(int i=0;i<n;i++) {
            prefMax=max(nums[i],prefMax);
            int stability=prefMax-suffMin[i];

            if(stability<=k) {
                ans=i;
                break;
            }
            
        }
        return ans;
        
    }
};
