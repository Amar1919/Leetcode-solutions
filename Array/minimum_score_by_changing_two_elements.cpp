// Problem: Minimum Score by Changing Two Elements

// Approach: Use Sorting + Greedy to minimize the difference between maximum and minimum elements.

// Sort the array in ascending order to easily identify the smallest and largest elements.

// Consider three cases: changing the two smallest, smallest and largest, or two largest elements.

// Return the minimum of the three possible ranges after changing two elements.

// Time Complexity: O(n log n) | Space Complexity: O(1)




#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        int ans=INT_MAX;

        ans=min(ans,nums[n-1]-nums[2]);
        ans=min(ans,nums[n-2]-nums[1]);
        ans=min(ans,nums[n-3]-nums[0]);

        return ans;

        
    }

};