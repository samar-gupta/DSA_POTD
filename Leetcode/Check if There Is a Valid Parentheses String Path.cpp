//Leetcode Link : https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path

//Approach-1 (Recursion Memo)
//T.C : O(m*n*(m+n))
//S.C : O(m*n*(m+n))
class Solution {
public:
    int m, n;
    int t[101][101][201];

    bool solve(int i, int j, int openCount, vector<vector<char>>& grid) {
        openCount += (grid[i][j] == '(') ? 1 : -1;

        if(openCount < 0)
            return false;

        if(t[i][j][openCount] != -1) {
            return t[i][j][openCount];
        }
        
        if(i == m-1 && j == n-1)
            return t[i][j][openCount] = (openCount == 0);

        //mode down
        if(i+1 < m) {
            if(solve(i+1, j, openCount, grid)) 
                return t[i][j][openCount] = true;
        }

        //mode right
        if(j+1 < n) {
            if(solve(i, j+1, openCount, grid)) 
                return t[i][j][openCount] = true;
        }

        return t[i][j][openCount] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if((m+n-1) % 2 == 1) 
            return false;
        
        if(grid[0][0] == ')' || grid[m-1][n-1] == '(')
            return false;
        
        memset(t, -1, sizeof(t));

        return solve(0, 0, 0, grid);

    }
};


//Approach-2 (Bottom Up)
//T.C : O(m*n*(m+n))
//S.C : O(m*n*(m+n))
class Solution {
public:
    int m, n;
    bool t[101][101][201];

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if((m+n-1) % 2 == 1)
            return false;

        if (grid[0][0] != '(' || grid[m - 1][n - 1] != ')') {
            return false;
        }

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {

                for(int openCount = 0; openCount <= i+j+1; openCount++) {
                    if(i == m-1 && j == n-1) {
                        t[i][j][openCount] = (openCount == 0);
                        continue;
                    }

                    t[i][j][openCount] = false;

                    //mode down
                    if(i+1 < m) {
                        int newOpCount = (grid[i+1][j] == '(') ? openCount + 1 : openCount-1;
                        if(newOpCount >= 0 && t[i+1][j][newOpCount] == true) {
                            t[i][j][openCount] = true;
                        }
                    }

                    //mode right
                    if(j+1 < n) {
                        int newOpCount = (grid[i][j+1] == '(') ? openCount + 1 : openCount-1;
                        if(newOpCount >= 0 && t[i][j+1][newOpCount] == true) {
                            t[i][j][openCount] = true;
                        }
                    }

                }

            }
        }

        return t[0][0][1];

        
    }
};
