// Problem: Running Sum of 1D Array

// Approach: Initialize a variable to store the running sum.

// Traverse the array from left to right.

// Add each element to the running sum.

// Store the updated running sum in the result vector.

// Time Complexity: O(n) | Space Complexity: O(n)



#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int running_sum=0;
        for(int i=0;i<n;i++) {
            running_sum+=nums[i];
            ans.push_back(running_sum);
        }
        return ans;
    }
};