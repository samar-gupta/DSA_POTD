//Approach-1 : Recursion (Brute Force) (TLE)
class Solution {
public:

    long long solve(int i, int j, int n, int k, vector<vector<int>> &arr, int currSum) {
        if(i < 0 || j < 0 || i >= n || j >= n) {
            return 0;
        }
        
        if(currSum > k)
            return 0;
            
        currSum = currSum + arr[i][j];
        
        if(k == currSum && i == n-1 && j == n-1) {
            return 1;
        }
        
        long long count = 0;
        
        count = count + solve(i+1, j, n, k, arr, currSum);
        count += solve(i, j+1, n, k, arr, currSum);
        
        return count;
    }
    
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){

        return solve(0, 0, n, k, arr, 0);
    }
};


//Approach-2 (Recursion + Memoization)
class Solution {
public:

    long long t[101][101][101];

    long long solve(int i, int j, int n, int k, vector<vector<int>> &arr, int currSum) {
        if(i < 0 || j < 0 || i >= n || j >= n) {
            return 0;
        }
        
        if(currSum > k)
            return 0;
            
        currSum = currSum + arr[i][j];
        
        if(t[i][j][currSum] != -1) {
            return t[i][j][currSum];
        }
        
        if(k == currSum && i == n-1 && j == n-1) {
            return 1;
        }
        
        long long count = 0;
        
        count = count + solve(i+1, j, n, k, arr, currSum);
        count += solve(i, j+1, n, k, arr, currSum);
        
        return t[i][j][currSum] = count;
    }
    
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        memset(t, -1, sizeof(t));
        return solve(0, 0, n, k, arr, 0);
    }
};


//updated
//Approach-2 : (Recursion + Memoization)
class Solution {
public:
    int n, m;
    int dp[101][101][101]; // dp[row][col][coins]

    int solve(int i, int j, int k, vector<vector<int>>& mat) {
        if (i >= n || j >= m || k < 0) return 0;

        // subtract current cell value
        k -= mat[i][j];
        if (k < 0) return 0;

        // reached destination
        if (i == n - 1 && j == m - 1) 
            return (k == 0);

        // memo check
        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        // move down or right
        int down = solve(i + 1, j, k, mat);
        int right = solve(i, j + 1, k, mat);

        return dp[i][j][k] = down + right;
    }

    int numberOfPath(vector<vector<int>>& mat, int k) {
        n = mat.size();
        m = mat[0].size();

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, k, mat);
    }
};
