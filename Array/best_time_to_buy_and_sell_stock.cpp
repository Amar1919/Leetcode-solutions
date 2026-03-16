// Problem: Best Time to Buy and Sell Stock
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Approach: Track minimum price and calculate maximum profit
// Data Structure: Array (vector)
// Space Complexity: O(1)
// Time Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=0;

        for(int i=0;i<prices.size();i++) {
            if(prices[i]<minPrice) {
                minPrice=prices[i];
            }

            int profit=prices[i]-minPrice;

            if(profit>maxProfit) {
                maxProfit=profit;
            }
        }

        return maxProfit;
    }
};