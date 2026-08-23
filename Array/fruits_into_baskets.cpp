//Problem:Fruit Into Baskets
//Link:https://leetcode.com/problems/fruit-into-baskets/
//Approach:Used sliding window and hashmap to find the longest subarray containing at most 2 distinct fruit types.
//Time Complexity:O(n)
//Space Complexity:O(1)


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int n=fruits.size();
        int left=0;
        int ans=0;

        for(int right=0;right<n;right++) {
            mp[fruits[right]]++;

            while(mp.size()>2) {
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0) {
                    mp.erase(fruits[left]);
                }
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
        
    }
};