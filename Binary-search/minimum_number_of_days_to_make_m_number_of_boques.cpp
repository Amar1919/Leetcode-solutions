//Problem: Minimum Number of Days to Make m Bouquets
//Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
//Approach: Used binary search on days and checked whether at least m bouquets of k adjacent flowers can be made by a given day.
//Time Complexity: O(n log(max(bloomDay) - min(bloomDay)))
//Space Complexity: O(1)



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int possible(vector<int>& bloomDay,int day,int m,int k) {
        int count=0;
        int noBoques=0;

        for(int i=0;i<bloomDay.size();i++) {
            if(bloomDay[i]<=day) {
                count++;
            } else {
                noBoques+=(count/k);
                count=0;
            }
        }
        noBoques+=count/k;
        return noBoques>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k>n) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;

        while(low<=high) {
            int mid=low+(high-low)/2;

            if(possible(bloomDay,mid,m,k)) {
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }

        }
        return ans;
    }
};