// Get the bottom-left and top-right coordinates of both rectangles.
// Check if their x-ranges overlap.
// Check if their y-ranges overlap.
// If both overlap, the rectangles overlap.
// Time: O(1), Space: O(1)



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1=rec1[0],y1=rec1[1],x2=rec1[2],y2=rec1[3];
        int x3=rec2[0],y3=rec2[1],x4=rec2[2],y4=rec2[3];

        if(x1<x4 && x3<x2 && y1<y4 && y3<y2) {
            return true;
        }
        return false;
        
    }
};