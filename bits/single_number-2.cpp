// Problem: Single Number II

// Approach: Use two variables, ones and twos, to track bits appearing once and twice.

// Update ones using XOR and remove bits already present in twos.

// Update twos similarly; bits appearing three times are cleared from both.

// Time Complexity: O(n) | Space Complexity: O(1)



#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0,twos=0;

        for(int x:nums) {
            ones=(ones^x) & ~twos;
            twos=(twos^x) & ~ones;
        }
        return ones;
        
    }
};