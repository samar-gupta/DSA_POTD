//Leetcode Link : https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/

//Approach-1 (Recursion Memo) - TLE
//T.C : O(n^2 * k)
//S.C : O(n*K)
class Solution {
public:
    int M = 1e9+7;
    int t[1001][1001];
    //O(n * k * n)
    int solve(int n, int k, int i) {
        if (k == 0) 
            return 1;

        if (i >= n)
            return 0;

        if(t[k][i] != -1) {
            return t[k][i];
        }

        long long take = 0; //start segment from ith point
        for(int j = i+1; j <= n-1; j++) {
            take = (take + solve(n, k-1, j)) % M;
        }

        long long skip = solve(n, k, i+1) % M;

        return t[k][i] = take + skip;
    }

    int numberOfSets(int n, int k) {
        memset(t, -1, sizeof(t));
        return solve(n, k, 0) % M;
    }
};


//Approach-2 (Recursion Memo) - TLE
//T.C : O(n^2 * k)
//S.C : O(n*K)
class Solution {
public:
    int M = 1e9 + 7;
    int dp[1001][1001];

    int numberOfSets(int n, int K) {

        for (int i = 0; i <= n; i++) {
            dp[0][i] = (i < n) ? 1 : 0;
        }

        for (int k = 1; k <= K; k++) {

            for (int i = n - 1; i >= 0; i--) {
                
                int skip = dp[k][i + 1];

                int take = 0;
                for (int j = i + 1; j < n; j++) {
                    take = (take + dp[k - 1][j]) % M;
                }

                dp[k][i] = (take + skip) % M;
            }
        }

        return dp[K][0];
    }
};


//Approach-3 (Bottom Up + PrevRow Sum Precomputed)
//T.C : O(n * k)
//S.C : O(n * K)
class Solution {
public:
    int M = 1e9 + 7;
    int dp[1001][1001];

    int numberOfSets(int n, int K) {

        for (int i = 0; i <= n; i++) {
            dp[0][i] = (i < n) ? 1 : 0;
        }

        for (int k = 1; k <= K; k++) {

            vector<int> prevRowSum(n + 1, 0);

            //prevRowSum[x] = dp[k-1][x] + dp[k-1][x+1] + ... + dp[k-1][n-1]
            for (int x = n - 1; x >= 0; x--) {
                prevRowSum[x] = (prevRowSum[x + 1] + dp[k - 1][x]) % M;
            }

            for (int i = n - 1; i >= 0; i--) {
                
                int skip = dp[k][i + 1];

                int take = prevRowSum[i+1];
                //dp[k-1][i+1] + dp[k-1][i+2] ...... + dp[k-1][n-1]

                dp[k][i] = (take + skip) % M;
            }
        }

        return dp[K][0];
    }
};


//Approach-4 (Combinatorics + Binary Exponentiation + Fermat's Little Theorem) 
//T.C : O((n+k) * log(MOD)) ~= O(n+k)
//S.C : O(n + K)
#define ll long long
class Solution {
public:
    vector<ll> fact;
    vector<ll> invFact;
    const int MOD = 1e9+7;

    //Binary Exponentiation 
    ll findPower(ll a, ll b) {
        if(b == 0)
            return 1;
        
        ll half = findPower(a, b/2);
        ll result = (half * half) % MOD;

        if(b%2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }

    //nCr % MOD
    ll nCr(int n, int r) {
        //nCr = n! * inv(n-r)! * inv(r)!
        return (((fact[n] * invFact[r]) % MOD) * invFact[n-r]) % MOD;
    }

    int numberOfSets(int n, int k) {
        //Precompute factoriala and inverse factorials - required for Fermat's Little Theorem
        fact.assign(n+k, 1);
        invFact.assign(n+k, 1);

        for(int i = 2; i < n+k; i++) {
            fact[i] = (fact[i-1] * i) % MOD;
        }

        //Fermat's little theorem for inverse factorials
        for(int i = 0; i < n+k; i++) {
            invFact[i] = findPower(fact[i], MOD-2);
        }

        return nCr(n+k-1, 2*k);
    }
};
