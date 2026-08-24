//Problem:Longest Repeating Character Replacement
//Link:https://leetcode.com/problems/longest-repeating-character-replacement/
//Approach:Used sliding window and a frequency array to track the most frequent character in the current window. If the number of characters that need to be replaced exceeds k, shrink the window.
//Time Complexity:O(n)
//Space Complexity:O(1)


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int left=0;
        int maxFreq=0;
        int ans=0;

        vector<int> freq(26,0);

        for(int right=0;right<n;right++) {
            freq[s[right]-'A']++;
            maxFreq=max(maxFreq,freq[s[right]-'A']);

            int windowSize=right-left+1;

            if(windowSize-maxFreq>k) {
                freq[s[left]-'A']--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;

        
    }
};