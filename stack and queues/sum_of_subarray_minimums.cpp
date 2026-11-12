// Problem: Sum of Subarray Minimums

// Approach: Use a monotonic stack to find the previous smaller and next smaller or equal elements.

// Calculate the number of possible starting and ending positions for each element.

// Find each element's contribution using arr[i] * left[i] * right[i].

// Add all contributions modulo 1e9+7 to get the final answer.

// Time Complexity: O(n) | Space Complexity: O(n)




#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        const int MOD= 1e9+7;

        vector<int> left(n),right(n);
        stack<int> st;

        for(int i=0;i<n;i++) {
            while(!st.empty() && arr[st.top()]>=arr[i]) {
                st.pop();
            }
            left[i]=st.empty()?i+1:i-st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && arr[st.top()]>arr[i]) {
                st.pop();
            }
            right[i]=st.empty()?n-i:st.top()-i;
            st.push(i);
        }

        long long ans=0;
        for(int i=0;i<n;i++) {
            long long contribution=(1LL * arr[i] * left[i] * right[i])%MOD;
            ans=(ans+contribution)%MOD;

        }
        
        return ans;
        
    }
};