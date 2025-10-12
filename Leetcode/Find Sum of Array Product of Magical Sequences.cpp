//Leetcode Link : https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences

//Approach-1 (Recursion + Memoization with Brute Force)
//T.C : O(m*N) after memoization but sum value becomes extremely high - Not feasible
//S.C : O(M*2^N)
class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9+7;
    int N, M, K;
    unordered_map<string, int> mp;

    ll solve(int count, ll sum, vector<int>& nums) {
        if(count == M) {
            return (__builtin_popcountll(sum) == K) ? 1 : 0;
        }

        string key = to_string(count) + "_" + to_string(sum);
        if(mp.count(key)) {
            return mp[key];
        }


        ll totalSum = 0;
        for(int i = 0; i < N; i++) {
            ll newSum = sum + (1LL << i);

            ll prod = (nums[i] * solve(count+1, newSum, nums)) % MOD;

            totalSum = (totalSum + prod) % MOD;
        }

        return mp[key] = totalSum;
    }

    int magicalSum(int m, int k, vector<int>& nums) {
        M = m;
        K = k;
        N = nums.size();

        return (int)(solve(0, 0, nums) % MOD);
    }
};


//Approach-2 : Usin Recursion + Memo with Bit Memoization (Digit DP)
//T.C : O(N* M^2 * K)
//S.C : O(N*M*K)
class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9+7;
    int N, K;

    map<tuple<ll, int , int, int>, ll> memo;

    vector<ll> fact;
    vector<ll> invFact;

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

    ll solve(ll binarySum, int m, int k, int i, vector<int>& nums) {
        auto key = make_tuple(binarySum, m, k, i);

        if(memo.count(key)) {
            return memo[key];
        }

        if(m == 0 && __builtin_popcount(binarySum) == k) {
            return 1;
        }

        if(m == 0 || i >= N) {
            return 0;
        }

        ll totalSum = 0;

        //Skip index i
        totalSum = (totalSum + solve((binarySum >> 1), m, k - (binarySum & 1), i+1, nums)) % MOD;

        //Take index i freq number of times
        for(int freq = 1; freq <= m; freq++) {
            ll newBinarySum = binarySum + freq;

            ll prod = solve((newBinarySum >> 1), m - freq, k - (newBinarySum & 1), i+1, nums);

            prod = (findPower(nums[i], freq) % MOD * prod % MOD) % MOD;

            prod = (prod * nCr(m, freq)) % MOD;

            totalSum = (totalSum + prod) % MOD;
        }

        return memo[key] = totalSum;
    }

    int magicalSum(int m, int k, vector<int>& nums) {
        K = k;
        N = nums.size();

        //Precompute factorials and inverse factorials
        fact.assign(m+1, 1);
        invFact.assign(m+1, 1);

        for(int i = 2; i <= m; i++) {
            fact[i] = (fact[i-1] * i) % MOD;
        }

        //Fermat's little theorem for inverse factorials
        for(int i = 0; i <= m; i++) {
            invFact[i] = findPower(fact[i], MOD-2);
        }

        return (int)(solve(0, m, k, 0, nums) % MOD);

    }
};
