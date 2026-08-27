// Problem: Capacity To Ship Packages Within D Days
// Approach: Applied binary search on ship capacity and checked how many days are required for each capacity.
// If the required days are within the limit, searched for a smaller capacity; otherwise, increased the capacity.
// Time Complexity: O(n * log(sum(weights)))
// Space Complexity: O(1)



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int findDays(vector<int>& weights,int cap) {
        int days=1;
        int load=0;
        for(int i=0;i<weights.size();i++) {
            if(weights[i]+load>cap) {
                days++;
                load=weights[i];
            } else {
                load+=weights[i];
            }
        }
        return days;

    }


    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int ans=0;

        while(low<=high) {
            int mid=low+(high-low)/2;
            int reqDays=findDays(weights,mid);
            if(reqDays<=days) {
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
        
    }
};