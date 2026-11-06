// Problem: Asteroid Collision

// Approach: Use a stack to process asteroids.

// Check collisions when stack top is positive and current asteroid is negative.

// Compare absolute values to determine which asteroid survives.

// Use a while loop to handle multiple consecutive collisions.

// Time Complexity: O(n) | Space Complexity: O(n)




#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int i=0;i<asteroids.size();i++) {
            int curr=asteroids[i];
            bool alive=true;

            while(!st.empty() && st.top()>0 && curr<0) {
                if(abs(st.top())<abs(curr)) {
                    st.pop();
                } else if(abs(st.top())==abs(curr)) {
                    st.pop();
                    alive=false;
                    break;
                } else {
                    alive=false;
                    break;
                }
            }
            if(alive) {
                st.push(curr);
                
            }
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};