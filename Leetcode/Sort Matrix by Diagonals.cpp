//Leetcode Link : https://leetcode.com/problems/sort-matrix-by-diagonals/description

//Approach-1 (Without Map - Simulation)
//T.C : O(n^2 * logn)
//S.C : O(n)
class Solution {
public:
    int n;
    
    void sortDiagonal(int r, int c, vector<vector<int>>& grid, bool asc) {
        vector<int> vec; //diagonal elements starting from [r][c]

        int i = r;
        int j = c;

        while(i < n && j < n) {
            vec.push_back(grid[i][j]);
            i++;
            j++;
        }

        if(asc) {
            sort(begin(vec), end(vec));
        } else {
            sort(rbegin(vec), rend(vec));
        }

        i = r;
        j = c;
        for(int &val : vec) {
            grid[i][j] = val;
            i++;
            j++;
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        n = grid.size();

        //Bottom Left - Non-Increasing Order
        for(int row = 0; row < n; row++) {
            sortDiagonal(row, 0, grid, false);
        }


        //Top Right - Non-Decreasing Order
        for(int col = 1; col < n; col++) {
            sortDiagonal(0, col, grid, true);
        }

        return grid;
    }
};


//Approach-2 (Using Map - (i-j) as the key)
//T.C : O(n^2 * logn)
//S.C : O(n^2) map stores all elements
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_map<int, vector<int>> mp;
        //(i-j) -> diagonal elements

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int diag = i-j;
                mp[diag].push_back(grid[i][j]);       
            }
        }

        for(auto &it : mp) {
            if(it.first >= 0) { //Key
                sort(begin(it.second), end(it.second));
            } else {
                sort(rbegin(it.second), rend(it.second));
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int diag = i-j;
                grid[i][j] = mp[diag].back();
                mp[diag].pop_back();      
            }
        }

        return grid;
    }
};
