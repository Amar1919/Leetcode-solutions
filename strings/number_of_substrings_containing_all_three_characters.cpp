//Problem: Number of Substrings Containing All Three Characters
//Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
//Approach: Used last seen indices of 'a', 'b', and 'c'. For every position, if all three characters have appeared, the minimum last seen index determines the number of valid starting positions.
//Time Complexity: O(n)
//Space Complexity: O(1)



#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3,-1);
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++) {
            lastSeen[s[i]-'a']=i;

            if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1) {
                count=count+1+min({lastSeen[0],lastSeen[1],lastSeen[2]});
            }
        }
        return count;
        
    }
};