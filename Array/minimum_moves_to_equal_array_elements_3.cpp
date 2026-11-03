// Problem: Minimum Moves to Equal Array Elements 3

// Approach: Find the maximum element using max_element().

// Calculate the absolute difference between the maximum element and each element.

// Sum all differences to get the total minimum moves.

// Time Complexity: O(n) | Space Complexity: O(1)




#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int max=*max_element(nums.begin(),nums.end());
        int min_moves=0;

        for(int i=0;i<n;i++) {
            min_moves+=abs(max-nums[i]);
        }
        return min_moves;
        
    }
};