//Company Tags   : Google, Salesforce, Microsoft, Meta, Amazon
//Frequency      : 74%
//Leetcode Link  : https://leetcode.com/problems/perfect-squares/

//Approach-1 (Recursion with Memoizatin)
//T.C : O(n * sqrt(n))
//S.C : O(n)
class Solution {
public:
    int t[10001];
    
    int minSquares(int n) {
        if(n == 0)
            return 0;
        
        if(t[n] != -1)
            return t[n];
        
        int minCount = INT_MAX;             //we can select only those perfect squares which can contribute to sum up to n
        for(int i = 1; i*i<=n; i++) {
            minCount = min(minCount, 1 + minSquares(n-i*i));      //1 is for selectcing one quare number
        }
        
        return t[n] = minCount;
    }
    
    int numSquares(int n) {
        memset(t, -1, sizeof(t));
        
        return minSquares(n);
    }
};





//Approach-2 (Bottom UP DP) 
//T.C : O(n*n) ~ O(n*sqrt(n))
//S.C : O(n) 
class Solution {
public:
    int numSquares(int n) {
        vector<int> t(n+1, INT_MAX);     //as we are finding minimun so we fill it with bigger value 
                                        //t[i] = min number of perfect squares to get i
        t[0] = 0;                      

        for(int i = 1; i <= n ; i++) {         // For each i, it must be the sum of some number (i - j*j) and a perfect square number (j*j).

            for(int j = 1; j*j <= i; j++) {
                int remain = i-j*j;

                t[i] = min(t[i], 1 + t[remain]);     //t[remain] = t[i - j*j]

            }

        }

        return t[n];
    }
};
