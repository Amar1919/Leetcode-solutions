// Problem: Single Number-1

// Approach: Use XOR to find the element that appears only once.

// XOR of the same numbers is 0, and XOR with 0 gives the number itself.

// Traverse the array and XOR each element to get the unique number.

// Time Complexity: O(n) | Space Complexity: O(1)



#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int x:nums) {
            ans=ans^x;
        }
        return ans;
        
    }
};