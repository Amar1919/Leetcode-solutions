// Problem: Number of Sub-arrays With Odd Sum

// Approach: Use Prefix Sum + Parity to count odd-sum subarrays efficiently.

// Maintain counts of even and odd prefix sums, initializing even = 1 for the empty prefix sum (0).

// If the current prefix sum is odd, add the number of previous even prefix sums to count; otherwise, add the number of previous odd prefix sums.

// Update the corresponding parity count and return the answer modulo 1e9 + 7.

// Time Complexity: O(n) | Space Complexity: O(1)




#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD=1e9+7;

        long long even=1;
        long long odd=0;
        long long sum=0;
        long long count=0;

        for(int i=0;i<arr.size();i++) {
            sum+=arr[i];

            if(sum%2==1) {
                count=(count+even)%MOD;
                odd++;
            } else {
                count=(count+odd)%MOD;
                even++;
            }
        }
        return count;
    }
};