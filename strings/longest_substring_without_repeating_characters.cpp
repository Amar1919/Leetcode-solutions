//Problem:Longest Substring Without Repeating Characters
//Link:https://leetcode.com/problems/longest-substring-without-repeating-characters/
//Approach:Used sliding window and a set to maintain unique characters in the current substring
//Time Complexity:O(n)
//Space Complexity:O(n)


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0;
        int len=0;
        unordered_set<int> st;

        for(int right=0;right<n;right++) {
            while(st.find(s[right])!=st.end()) {
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);
            len=max(len,right-left+1);
        }
        return len;
    }
};