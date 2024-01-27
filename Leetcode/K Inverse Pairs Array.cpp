//Company Tags 	   : Google
//Leetcode Link 	 : https://leetcode.com/problems/k-inverse-pairs-array/

//Approach-1 (Reucr+Memo)
//T.C  : O(n*k*n)
//S.C  : O(n*k) for memo + Recursion call stack
class Solution {
public:
    const int M = 1e9+7;
    int t[1001][1001];
    int solve(int n, int k) {
        if(n == 0)
            return 0;
        
        if(k == 0)
            return 1;
        
        if(t[n][k] != -1)
            return t[n][k];

        int totalInversions = 0;
        
        //In an array of length n, We can't create inversions more than (n-1) -> min(n-1, k)
        for(int i = 0; i <= min(n-1, k); i++) {
            totalInversions = (totalInversions%M + kInversePairs(n-1, k-i)%M)%M;
        }
        
        return t[n][k] = totalInversions;
    }

    int kInversePairs(int n, int k) {
        memset(t, -1, sizeof(t));
        return solve(n, k);
    }
};





//Approach-2 (Bottom UP derived from Approach-1)
//T.C  : O(n*k*n)
//S.C  : O(n*k) for memo + Recursion call stack
class Solution {
public:
    const int M = 1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> t(n+1, vector<int>(k+1));

        for(int i = 0; i < n+1; i++) {
            t[i][0] = 1;
        }

        for(int i = 1; i<=n; i++) {
            
            for(int j = 1; j <= k; j++) {

                for(int inv = 0; inv <= min(i-1, j); inv++) {
                    t[i][j] = (t[i][j] + t[i-1][j-inv])%M;
                }

            }
        }
        return t[n][k];
    }
};





//Approach-3 (Improving on Approach-1 above) - DP with cumulative sum approach
//Time : O(n*k)
//S.C : O(n*k)
class Solution {
public:
    int M = 1e9+7;

    int kInversePairs(int n, int k) {
        vector<vector<int>> t(n+1, vector<int>(k+1));
        //t[i][j] = total number of arrays having (1 to i) and exactly j inversions

        //for j = 0, t[i][0] = 1
        for(int i = 0; i <= n; i++) {
            t[i][0] = 1;
        }

        //O(n*k)
        for(int i = 1; i <= n; i++) {
            long long cumSum = 1;
            for(int j = 1; j <= k; j++) {
                
                cumSum += t[i-1][j];
                if(j >= i) {
                    cumSum -= t[i-1][j-i];
                }
                t[i][j] = cumSum % M;
            }
        }


        return t[n][k];

    }
};

