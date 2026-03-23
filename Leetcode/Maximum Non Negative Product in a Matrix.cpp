//Leetcode Link : https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/

//Approach - 1 (Recursion + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;
    typedef long long ll;
    int MOD = 1e9+7;

    vector<vector<pair<ll, ll>>> t;
    
    pair<ll, ll> solve(int i, int j, vector<vector<int>>& grid) {
        if(i == m-1 && j == n-1) {
            return {grid[i][j], grid[i][j]};
        }

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        if(t[i][j] != make_pair(LLONG_MIN, LLONG_MAX)) {
            return t[i][j];
        }

        //Down
        if(i+1 < m) {
            auto [downMax, downMin] = solve(i+1, j, grid);
            maxVal = max({maxVal, grid[i][j] * downMax, grid[i][j] * downMin});
            minVal = min({minVal, grid[i][j] * downMax, grid[i][j] * downMin});
        }


        //Right
        if(j+1 < n) {
            auto [rightMax, rightMin] = solve(i, j+1, grid);
            maxVal = max({maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
            minVal = min({minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }

        return t[i][j] = {maxVal, minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        t = vector<vector<pair<ll, ll>>>(m, vector<pair<ll, ll>>(n, {LLONG_MIN, LLONG_MAX}));
        auto [maxProd, minProd] = solve(0, 0, grid);

        return maxProd < 0 ? -1 : maxProd % MOD;
    }
};


//Approach - 2 (Bottom Up)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        

        //bottom up dp lena padega
        vector<vector<pair<ll, ll>>> t(m, vector<pair<ll, ll>>(n));
        //t[i][j] = {maxVal, minVal} to reach from (0, 0) to (i, j)

        t[0][0] = {grid[0][0], grid[0][0]};

        //filling the first row
        for(int j = 1; j < n; j++) {
            t[0][j].first  = t[0][j-1].first  * grid[0][j]; //maxVal
            t[0][j].second = t[0][j-1].second * grid[0][j]; //minVal
        }

        //filling the first column
        for(int i = 1; i < m; i++) {
            t[i][0].first  = t[i-1][0].first  * grid[i][0]; //max Val
            t[i][0].second = t[i-1][0].second * grid[i][0]; //min val
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                ll upMax = t[i-1][j].first;
                ll upMin = t[i-1][j].second;

                ll leftMax = t[i][j-1].first;
                ll leftMin = t[i][j-1].second;

                t[i][j].first  = max({upMax * grid[i][j], upMin * grid[i][j], leftMax * grid[i][j], leftMin * grid[i][j]});
                t[i][j].second = min({upMax * grid[i][j], upMin * grid[i][j], leftMax * grid[i][j], leftMin * grid[i][j]});
            }
        }

        auto [maxProd, minProd] = t[m-1][n-1];

        return maxProd < 0 ? -1 : maxProd % MOD;
    }
};
