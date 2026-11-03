// Problem: Next Greater Element II

// Approach: Traverse the circular array twice using 2*n iterations.

// Use modulo (%) to simulate circular traversal and access elements.

// Maintain a decreasing monotonic stack of indices to find the Next Greater Element.

// Push indices only during the first traversal and update answers when a greater element is found.

// Time Complexity: O(n) | Space Complexity: O(n)




#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;

        for(int i=0;i<2*n;i++) {
            int curr=nums[i%n];

            while(!st.empty() && nums[st.top()]<curr) {
                ans[st.top()]=curr;
                st.pop();
            }
            if(i<n) {
                st.push(i);
            }
        }
        return ans;
        
    }
};