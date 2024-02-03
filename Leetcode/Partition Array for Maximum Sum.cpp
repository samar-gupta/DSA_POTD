//Leetcode Link   : https://leetcode.com/problems/partition-array-for-maximum-sum/

//Approach-1 (Recursion + Memo)
//T.C : With Memoization - O(n*k) -> We visit only n states in dp array and everytime run a for loop of size k
//Without Memoization - We have 2 options at each index - O(k^n) - Since the recursion tree has a branching factor of k, and the depth of the recursion tree is at most n
//S.C : O(n)
class Solution {
public:
    int n;
    int t[501];

    int solve(int i, vector<int>& arr, int k) {
        if(i >= n) {
            return 0;
        }

        if(t[i] != -1) {
            return t[i];
        }

        int result = 0;
        int curr_max = -1;

        for(int j = i; j < n && (j-i+1) <= k; j++) {
            curr_max = max(curr_max, arr[j]);

            //current subarray = arr[i to j]  --->  (j-i+1)
            result = max(result, ((j-i+1)*curr_max) + solve(j+1, arr, k));
        }

        return t[i] = result;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(t, -1, sizeof(t));
        return solve(0, arr, k);
    }
};





//Approach-2 (Bottom Up)
//T.C : O(n*k)
//S.C : O(n)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> t(n+1, 0);
        //t[i] = max sum for partitioning an array of size i

        for(int size = 1; size <= n; size++) {

            int currmax = -1;
            for(int j = 1; j <= k && size - j >= 0; j++) {
                currmax = max(currmax, arr[size-j]);

                t[size] = max(t[size], currmax*j + t[size-j]);
            }

        }

        return t[n];
    }
};





//Approach-2.1 (Bottom Up) (with different state definition) 
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> t(n+1, 0);            //base case n+1 is 0 in dp!

        for(int i = n-1; i >= 0; i--) {

            int currmax = -1;

            for(int j = i; j < min(n, i+k); j++) {
                currmax = max(currmax, arr[j]);

                t[i] = max(t[i], (j-i+1)*currmax + t[j+1]);
            }
        }

        return t[0];
    }
};
