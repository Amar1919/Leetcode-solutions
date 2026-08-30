// Problem: Median of Two Sorted Arrays
// Approach: Applied binary search on the smaller array to find the correct partition.
// Calculated the partition in the second array so both left halves contain half of the total elements.
// Checked partition validity using boundary elements and calculated the median without merging the arrays.
// Time Complexity: O(log(min(n1, n2)))
// Space Complexity: O(1)



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);

        int n1=nums1.size();
        int n2=nums2.size();

        int low=0;
        int high=n1;

        while(low<=high) {
            int cut1=low+(high-low)/2;

            int cut2=(n1+n2+1)/2-cut1;

            int left1=(cut1==0)?INT_MIN:nums1[cut1-1];
            int right1=(cut1==n1)?INT_MAX:nums1[cut1];

            int left2=(cut2==0)?INT_MIN:nums2[cut2-1];
            int right2=(cut2==n2)?INT_MAX:nums2[cut2];

            if(left1<=right2 && left2<=right1) {
                if((n1+n2)%2==1) {
                    return max(left1,left2);
                } 
                return (max(left1,left2)+min(right1,right2))/2.0;
                
            } else if(left1>right2) {
                high=cut1-1;
            } else {
                low=cut1+1;
            }
        }
         return 0.0;
    }
};