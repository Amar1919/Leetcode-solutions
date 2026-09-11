// Problem: Reverse Words in a String

// Approach: First remove leading, trailing, and multiple spaces using two pointers.

// Use i to traverse the string and j to write the cleaned string in-place,
// keeping exactly one space between words.

// Reverse the entire string to reverse the order of the words.

// Then reverse each individual word to restore the characters in their
// original order.

// Time Complexity: O(n) | Space Complexity: O(1)



#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    string reverseWords(string s) {
        int j = 0;

        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (j != 0) {
                    s[j++] = ' ';
                }

                while (i < s.size() && s[i] != ' ') {
                    s[j++] = s[i++];
                }
            }
        }

        s.resize(j);

        
        reverse(s.begin(), s.end());

        
        int start = 0;

        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
};