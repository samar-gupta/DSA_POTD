//Leetcode Link : https://leetcode.com/problems/length-of-longest-fibonacci-subsequence

//Approach-1 (Recursion + Memoization)
//T.C : O(n^3) without Memoization, and O(n^2) with memoization
//S.C : O(n^2)
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        vector<vector<int>> t(n, vector<int>(n, -1));
        
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }
        
        int max_length = 0;
        for (int j = 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int length = solve(j, k, arr, mp, t);
                if (length >= 3) {
                    max_length = max(max_length, length);
                }
            }
        }
        return max_length >= 3 ? max_length : 0;
    }
    
private:
    int solve(int j, int k, const vector<int>& arr, const unordered_map<int, int>& mp, vector<vector<int>>& t) {
        if (t[j][k] != -1) return t[j][k];
        
        int target = arr[k] - arr[j];
        if (mp.count(target) && mp.at(target) < j) {
            int i = mp.at(target);
            t[j][k] = solve(i, j, arr, mp, t) + 1;
            return t[j][k];
        }
        
        return t[j][k] = 2;
    }
};


//Approach-2 (Bottom Up)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        vector<vector<int>> t(n, vector<int>(n, 2));
        //t[j][k] = length of the longest Fibonacci-like subsequence that ends at indices j and k in the array arr.

        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }
        
        int max_length = 0;
        for (int j = 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int target = arr[k] - arr[j];
                if (mp.count(target) && mp[target] < j) {
                    int i = mp[target];
                    t[j][k] = t[i][j] + 1;
                }
                max_length = max(max_length, t[j][k]);
            }
        }
        return max_length >= 3 ? max_length : 0;
    }
};
