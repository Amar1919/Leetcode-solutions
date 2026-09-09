// Problem: Valid Anagram

// Approach: Use a frequency array to count the occurrences of each character.

// Increment the frequency for every character in s and decrement it for every character in t.

// If any frequency becomes negative, the strings cannot be anagrams.

// Time Complexity: O(n) | Space Complexity: O(1)




#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;

        vector<int> freq(26,0);

        for(char c:s) {
            freq[c-'a']++;
        }

        for(char c:t) {
            freq[c-'a']--;
            if(freq[c-'a']<0) {
                return false;
            } 
        }
        return true;
    }
};