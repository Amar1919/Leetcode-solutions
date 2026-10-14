// Problem: Set the Rightmost Unset Bit
// Approach: Convert the decimal number to binary and find the rightmost unset bit.
// Change the rightmost 0 to 1 and convert the binary string back to decimal.
// Time Complexity: O(log n) | Space Complexity: O(log n)
// Here, log n is the number of bits in the binary representation of n.




#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    string decToBin(int n) {
        if (n == 0) return "0";

        string s = "";
        while (n > 0) {
            s += (n % 2) + '0';
            n /= 2;
        }

        reverse(s.begin(), s.end());
        return s;
    }

    int setRightmostUnsetBit(int n) {
        string s = decToBin(n);

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                s[i] = '1';
                break;
            }
        }

        int decimal = 0;
        for (int i = 0; i < s.size(); i++) {
            decimal = decimal * 2 + (s[i] - '0');
        }

        return decimal;
    }
};
