//Leetcode Link : https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii

//Approach-1 (Recursion + Memoization - Derived from Part-I)
//T.C : O(one * zero)
//S.C : O(one * zero)
class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<vector<int>>> t;

    int solve(int i, int j, int last, int limit) {

        // Base: no elements
        if (i == 0 && j == 0) 
            return 0;

        // Base: only zeros left
        if (j == 0) {
            if (last == 1) return 0; 
            return (i <= limit) ? 1 : 0;
        }

        // Base: only ones left
        if (i == 0) {
            if (last == 0) return 0; 
            return (j <= limit) ? 1 : 0;
        }

        if (t[i][j][last] != -1)
            return t[i][j][last];

        int result = 0;

        if (last == 0) {
            result = (solve(i-1, j, 0, limit) + solve(i-1, j, 1, limit)) % M;

            if (i-1 >= limit)
                result = (result - solve(i-1-limit, j, 1, limit) + M) % M;

        } else {
            result = (solve(i, j-1, 0, limit) + solve(i, j-1, 1, limit)) % M;

            if (j-1 >= limit)
                result = (result - solve(i, j-1-limit, 0, limit) + M) % M;
        }

        return t[i][j][last] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        t.assign(zero+1, vector<vector<int>>(one+1, vector<int>(2, -1)));

        return (solve(zero, one, 0, limit) + solve(zero, one, 1, limit)) % M;
    }
};


//Approach-2 (Bottom Up - Derived from Part-I)
//T.C : O(one * zero)
//S.C : O(one * zero)
class Solution {
public:
    int M = 1e9+7;
    int numberOfStableArrays(int zero, int one, int limit) {
        //t[zero+1][one+1][2] 
        vector<vector<vector<int>>> t(zero+1, vector<vector<int>>(one+1, vector<int>(2, 0)));

        for(int i = 0; i <= min(zero, limit); i++)
            t[i][0][0] = 1;
        
        for(int j = 0; j <= min(one, limit); j++) {
            t[0][j][1] = 1;
        }

        for(int i = 0; i <= zero; i++) { //i = # 0s
            for(int j = 0; j <= one; j++) { //j = # 1s

                if(i == 0 || j == 0)
                    continue;

                t[i][j][1] = (t[i][j-1][0] + t[i][j-1][1]) % M;
                
                if(j-1 >= limit) {
                    t[i][j][1] = (t[i][j][1] - t[i][j-1-limit][0] + M) % M;
                }

                t[i][j][0] = (t[i-1][j][0] + t[i-1][j][1]) % M;
                
                if(i-1 >= limit) {
                    t[i][j][0] = (t[i][j][0] - t[i-1-limit][j][1] + M) % M;
                }
            }
        }

        return (t[zero][one][0] + t[zero][one][1]) % M;
    }
};
