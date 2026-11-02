// Problem: Minimum Moves to Equal Array Elements II

// Approach: Use sorting to find the median of the array.

// Select the middle element as the target value.

// Calculate the absolute difference between each element and the median.

// Sum all differences to get the minimum number of moves.

// Time Complexity: O(n log n) | Space Complexity: O(1)




#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int median=nums[n/2];
        int min_moves=0;

        for(int i=0;i<n;i++) {
            min_moves+=abs(nums[i]-median);
        }
        return min_moves;
        
    }
};