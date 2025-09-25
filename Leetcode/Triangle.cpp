//Leetcode Link  : https://leetcode.com/problems/triangle/  
//Solve "Minimum Falling Path Sum" (Leetcode-931) before this question 

//Approach-1 Recursion with Memoization - TLE
//T.C : O(n^2) states in t[][]
//S.C : O(n^2)
class Solution {
public:
    int t[201][201];
    int n;
    int solve(vector<vector<int>>& triangle, int row, int col) {
        if (row == n-1)
            return triangle[row][col];

        if(t[row][col] != -1)
            return t[row][col];
        
        int minPath = triangle[row][col] + 
                      min(solve(triangle, row + 1, col),
                          solve(triangle, row + 1, col + 1));

        return t[row][col] = minPath;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        memset(t, -1, sizeof(t));
        return solve(triangle, 0, 0);
    }
};


//Approach-2 : Bottom Up - Just like "Minimum Falling Path Sum"
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> t = triangle;  // copy triangle for t

        // Start from second last row and move upwards
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) { //1st row me 1 column, 2nd Row me 2 Columns, and so on, that's why (col <= row)
                t[row][col] += min(t[row + 1][col], t[row + 1][col + 1]);
            }
        }

        return t[0][0];  // minimum path sum
    }
};


//Approach-3 : Bottom Up optimized - O(n) space
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> t = triangle.back();  // last row

        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                t[col] = triangle[row][col] + min(t[col], t[col + 1]);
            }
        }

        return t[0];
    }
};


//Approach-4 : You can also solve it from top to bottom direction
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> t(n, 0);

        t[0] = triangle[0][0];

        for (int row = 1; row < n; row++) {
            // go right → left to avoid overwriting
            for (int col = row; col >= 0; col--) {
                if (col == 0) {
                    t[col] = t[col] + triangle[row][col];  // only from above
                } else if (col == row) {
                    t[col] = t[col - 1] + triangle[row][col];  // only from above-left
                } else {
                    t[col] = min(t[col], t[col - 1]) + triangle[row][col];
                }
            }
        }

        return *min_element(t.begin(), t.end());
    }
};


//Approach-5 : Bottom Up optimized - manipulating the input
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        for(int row = 1; row < n; row++) {
            for(int col = 0; col<triangle[row].size(); col++) {
                int prev_up_val  = triangle[row-1][min(col, (int)triangle[row-1].size()-1)];
                int prev_up_left = triangle[row-1][max(col-1, 0)];
                
                triangle[row][col] += min(prev_up_val, prev_up_left);
            }
        }
        
        return *min_element(triangle[n-1].begin(), triangle[n-1].end());
        
    }
};
