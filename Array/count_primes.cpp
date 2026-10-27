// Problem: Count Primes

// Approach: Use the Sieve of Eratosthenes to mark multiples of each prime as non-prime, starting from i*i.
// Count all remaining prime numbers strictly less than n.

// Time Complexity: O(n log log n)

// Space Complexity: O(n)




#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        int count=0;

        vector<int> prime(n,1);
        prime[0]=0;
        prime[1]=0;

        for(int i=2;i*i<n;i++) {
            if(prime[i]) {
                for(int j=i*i;j<n;j+=i) {
                    prime[j]=0;
                }
            }
        }

        for(int i=0;i<n;i++) {
            if(prime[i]) count++;
        }

        return count;
        
    }
};