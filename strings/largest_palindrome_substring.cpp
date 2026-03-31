//Problem:Largest Palindromic Substring
//Link:https://leetcode.com/problems/longest-palindromic-substring/
// Approach:Expand around center of the string and check for the palindrome string
//Time complexity:O(n^2)
//Space Complexity:O(n)


#include<bits/stdc++.h>/
using namespace std;


class Solution {
public:
    int expandFromCenter(string &s,int left,int right) {
        while(left>=0 && right<s.size() && s[left]==s[right]) {
            left--;
            right++;
        }
        return right-left-1;
    }

    string longestPalindrome(string s) {
        int start=0;
        int maxLen=0;

        for(int i=0;i<s.size();i++) {
            int len1=expandFromCenter(s,i,i);
            int len2=expandFromCenter(s,i,i+1);
            int currMax=max(len1,len2);

            if(currMax>maxLen) {
                maxLen=currMax;
                start=i-(currMax-1)/2;
            }
            
        }
        return s.substr(start,maxLen);

        
    }
};