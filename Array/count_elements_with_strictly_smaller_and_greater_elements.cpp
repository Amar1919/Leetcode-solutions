// Problem: Count Elements With Strictly Smaller and Greater Elements

// Approach: Find the minimum and maximum elements in the array.

// Traverse the array and check whether each element equals min or max.

// Count elements that are either minimum nor maximum.

// Return n - count of minimum and maximum elements.

// Time Complexity: O(n) | Space Complexity: O(1)





#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int countElements(vector<int>& nums) {
        int n=nums.size();
        int max=*max_element(nums.begin(),nums.end());
        int min=*min_element(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<n;i++) {
            if(nums[i]==max || nums[i]==min) {
                count++;
            }
        }
        return n-count;
        
    }
};