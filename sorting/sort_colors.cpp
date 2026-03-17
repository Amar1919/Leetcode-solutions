// Problem: Sort Colors
// Link: https://leetcode.com/problems/sort-colors/
// Approach: Counting Sort (Count 0s, 1s, 2s and overwrite)
// Data Structure: Array (vector)
// Space Complexity: O(1)
// Time Complexity: O(n)

#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0;
        int ones = 0;
        int twos = 0;

        // Count occurrences
        for(int x : nums) {
            if(x == 0) zeros++;
            if(x == 1) ones++;
            if(x == 2) twos++;
        }

        int i = 0;

        // Overwrite with 0s
        while(zeros) {
            nums[i] = 0;
            i++;
            zeros--;
        }

        // Overwrite with 1s
        while(ones) {
            nums[i] = 1;
            i++;
            ones--;
        }

        // Overwrite with 2s
        while(twos) {
            nums[i] = 2;
            i++;
            twos--;
        }
    }
};