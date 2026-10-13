// Problem: Number of 1 Bits
// Approach: Use Brian Kernighan's algorithm to remove the rightmost set bit.
// Increment count for each set bit removed until n becomes 0.
// Time Complexity: O(k) | Space Complexity: O(1)
// Here, k is the number of set bits in n.



#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n>0) {
            n=n&(n-1);
            count++;
            n/=2;
        }
        return count;
        
    }
};