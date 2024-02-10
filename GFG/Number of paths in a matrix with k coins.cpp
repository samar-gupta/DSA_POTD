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
