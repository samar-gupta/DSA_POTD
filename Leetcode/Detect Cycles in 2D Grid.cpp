//Leetcode Link : https://leetcode.com/problems/detect-cycles-in-2d-grid

//Approach-1 (Using DFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    bool cycleDetectDFS(int r, int c, int prev_r, int prev_c, 
                    vector<vector<char>>& grid, vector<vector<bool>>& visited ) {

        if(visited[r][c]) {
            return true;
        }

        visited[r][c] = true;

        //explore neighbours
        for(auto &dir : directions) {
            int new_r = r + dir[0]; 
            int new_c = c + dir[1];

            if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n
                && grid[new_r][new_c] == grid[r][c]) {
                    if(new_r == prev_r && new_c == prev_c)
                        continue;
                    
                    if(cycleDetectDFS(new_r, new_c, r, c, grid, visited)) {
                        return true;
                    }
                }
        }

        return false;

    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && cycleDetectDFS(i, j, i, j, grid, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};



//Approach-2 (Using BFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    bool cycleDetectBFS(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        //r, c, prev_r, prev_c
        queue<tuple<int, int, int, int>> que;

        que.push({r, c, -1, -1});
        visited[r][c] = true;

        while(!que.empty()) {
            auto [curr_r, curr_c, prev_r, prev_c] = que.front();
            que.pop();

            //explore neighbours
            for(auto &dir : directions) {
                int new_r = curr_r + dir[0];
                int new_c = curr_c + dir[1];

                if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n
                && grid[new_r][new_c] == grid[curr_r][curr_c]) {
                    
                    if(new_r == prev_r && new_c == prev_c)
                        continue;
                    
                    if(visited[new_r][new_c])
                        return true;
                    
                    visited[new_r][new_c] = true;

                    que.push({new_r, new_c, curr_r, curr_c});
                }

            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && cycleDetectBFS(i, j, grid, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};
