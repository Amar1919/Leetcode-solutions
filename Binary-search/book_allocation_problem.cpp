// Problem: Book Allocation Problem

// Approach: Check if books can be allocated to at most m students with each student getting at most the given barrier pages.

// Greedily allocate books to the current student until adding the next book exceeds the barrier, then assign it to a new student.

// If students required exceed m, the barrier is not possible; otherwise, it is possible.

// Time Complexity: O(n log(sum)) | Space Complexity: O(1)



#include<bits/stdc++.h>
using namespace std;



class Solution {
public:


    bool isPossible(vector<int> &nums,int barrier,int m) {
        int allocatedStu=1;
        int pages=0;

        for(int i=0;i<nums.size();i++) {
            if(nums[i]>barrier) return false;
            if(pages+nums[i]>barrier) {
                allocatedStu++;
                pages=nums[i];
            } else {
                pages+=nums[i];
            }
            if(allocatedStu>m) return false;
        }
        return true;
    }

    int findPages(vector<int> &nums, int m)  {
        int low=*min_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;

        while(low<=high) {
            int mid=low+(high-low)/2;
            if(isPossible(nums,mid,m)==true) {
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
};