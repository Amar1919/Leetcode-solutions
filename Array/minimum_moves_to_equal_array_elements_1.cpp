// Problem: Minimum Moves to Equal Array Elements 1

// Approach: Find the minimum element using min_element().

// Calculate the difference between each element and the minimum element.

// Sum all differences to get the total minimum moves.

// Time Complexity: O(n) | Space Complexity: O(1)



#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int min_moves=0;
        int min=*min_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++) {
            min_moves+=abs(nums[i]-min);
        }
        return min_moves;
        
    }
};