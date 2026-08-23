// Problem: Container With Most Water
// Link: https://leetcode.com/problems/container-with-most-water/
// Approach: Two Pointer Technique
// Data Structure: Array (vector)
// Space Complexity: O(1)
// Time Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        long long maxArea = 0;   

        while (left < right) {
            long long h = min(height[left], height[right]);
            long long w = right - left;
            maxArea = max(maxArea, h * w);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return (int)maxArea; 
    }
};
