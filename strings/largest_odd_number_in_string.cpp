// Problem: Largest Odd Number in String

// Approach: Find the rightmost odd digit in the string.

// Return the substring from the start up to that digit, as it forms the largest odd number.

// If no odd digit exists, return an empty string.

// Time Complexity: O(n) | Space Complexity: O(1)



#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        for(int i=n-1;i>=0;i--) {
            if((num[i]-'0')%2==1) {
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};