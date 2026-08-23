
//Problem:Koko Eating Bananas
//Link:https://leetcode.com/problems/koko-eating-bananas/
//Approach:Used Binary Search on Answer to find the minimum eating speed.
//For each speed, calculated the total hours required to eat all the piles.
//Time Complexity:O(n * log(max(piles)))
//Space Complexity:O(1)





#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long fun(vector<int>& arr,int hrs) {
        long long total_time=0;
        for(int i=0;i<arr.size();i++) {
            total_time+=ceil((double)arr[i]/hrs);
        }
        return total_time;
    } 

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(),piles.end());
        int low=1;
        int high=maxi;
        int ans=high;
        while(low<=high) {
            int mid=low+(high-low)/2;
            long long required_time=fun(piles,mid);
            if(required_time<=h) {
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;

        
    }
};