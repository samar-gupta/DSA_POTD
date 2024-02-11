//Company Tags    : Microsoft, Amazon, Google
//Leetcode Link   : https://leetcode.com/problems/cherry-pickup-ii

//Approach-1 (Using Recursion + Memoization)
//T.C : O(row*col*col * 9) -> 9 is from the double for loop for every single move {-1,0,1} of Robot1 for {-1,0,1} of Robot2 {3*3}
//S.C : O(row * col * col)

class Solution {
public:
    int n, m;
    int t[71][71][71];

    int solve(vector<vector<int>>& grid, int row, int c1, int c2) {
        if(row >= m) {
            return 0;          //no cherry as we are out of bound
        }

        if(t[row][c1][c2] != -1) {
            return t[row][c1][c2];
        }

        int cherry = grid[row][c1];
        if(c1 != c2) {                   //same cell can be taken only once
            cherry += grid[row][c2];
        }

        int ans = 0;
        for(int i = -1; i <= 1; i++) {        //R1
            for(int j = -1; j <= 1; j++) {      //R2

                int newRow = row + 1;
                int new_c1 = c1 + i;
                int new_c2 = c2 + j;

                if(new_c1 >= 0 && new_c1 < n && new_c2 >=0 && new_c2 < n)     //safe column
                    ans = max(ans, solve(grid, newRow, new_c1, new_c2));

            }
        }

        return t[row][c1][c2] = cherry + ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t, -1, sizeof(t));
        return solve(grid, 0, 0, n-1);
    }
};





//Approach-2 (Bottom Up - 3D Array)
//T.C : O(row*col*col * 9)
//S.C : O(row * col * col)
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int t[71][71][71] = {0};                      //t[m][n][n]    //t[row][c1][c2] =  max cherries that can be collected till (row, c1) by robot1 and (row, c2) by robot2       //return max in last row 

        t[0][0][n-1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n-1];            //For first row (robot1 is in 0th column) and robot2 is in (n-1)th column


        for(int row = 1; row < m; row++) {

            for(int c1 = 0; c1 <= min(n-1, row); c1++) {

                for(int c2 = max(0, n-row-1); c2 < n; c2++) {

                    int prevRowMax = 0;

                    for(int prevCol1 = max(0, c1-1); prevCol1 <= min(n-1, c1+1); prevCol1++) {            //A Robot can come to current column from either column-1, column, or column+1 of prev row (row-1)

                        for(int prevCol2 = max(0, c2-1); prevCol2 <= min(n-1, c2+1); prevCol2++) {

                                prevRowMax = max(prevRowMax, t[row-1][prevCol1][prevCol2]);

                        }

                    }

                    
                    if(c1 == c2) {                                                //t[row][c1][c2]
                        t[row][c1][c2] = prevRowMax + grid[row][c1];
                    } else {
                        t[row][c1][c2] = prevRowMax + grid[row][c1] + grid[row][c2];
                    }


                }

            }

        }

        int result = 0;
        for(int i = 0; i < n; i++) {                   //return max in last row 
            for(int j = 0; j < n; j++) {
                result = max(result, t[m-1][i][j]);
            }
        }

        return result; 
    }
}; 





//Approach-3 (Bottom Up - 2D Array) We only need previous row
//T.C : O(row*col*col * 9)
//S.C : O(col * col)
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> prev(71, vector<int>(71, 0));                

        prev[0][n-1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n-1];            


        for(int row = 1; row < m; row++) {

            vector<vector<int>> curr(71, vector<int>(71, 0));   

            for(int c1 = 0; c1 <= min(n-1, row); c1++) {

                for(int c2 = max(0, n-row-1); c2 < n; c2++) {

                    int prevRowMax = 0;

                    for(int prevCol1 = max(0, c1-1); prevCol1 <= min(n-1, c1+1); prevCol1++) {           

                        for(int prevCol2 = max(0, c2-1); prevCol2 <= min(n-1, c2+1); prevCol2++) {

                                prevRowMax = max(prevRowMax, prev[prevCol1][prevCol2]);

                        }

                    }

                    
                    if(c1 == c2) {                                                
                        curr[c1][c2] = prevRowMax + grid[row][c1];
                    } else {
                        curr[c1][c2] = prevRowMax + grid[row][c1] + grid[row][c2];
                    }


                }

            }

            prev = curr;

        }

        int result = 0;
        for(int i = 0; i < n; i++) {                   
            for(int j = 0; j < n; j++) {
                result = max(result, prev[i][j]);
            }
        }

        return result; 
    }
}; 
