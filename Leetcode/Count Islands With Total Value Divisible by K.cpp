//Leetcode Link : https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/

//Approach-1 (Simple DFS)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    long long dfs(int i, int j, vector<vector<int>>& grid) {
        long long sum = grid[i][j];
        grid[i][j] = 0;

        for(vector<int>& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0) {
                sum += dfs(i_, j_, grid);
            }
        }

        return sum;
    }

    long long bfs() {
        //queue
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int count=  0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) {
                    long long sum = dfs(i, j, grid);
                    if(sum % k == 0)
                        count++;
                }
            }
        }

        return count;
    }
};



//Approach-2 (Simple BFS)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    long long bfs(int i, int j, vector<vector<int>>& grid) {
        long long sum = grid[i][j];
        grid[i][j] = 0;

        queue<pair<int, int>> que;
        que.push({i, j});

        while (!que.empty()) {
            auto [r, c] = que.front();
            que.pop();

            for (vector<int>& dir : directions) {
                int i_ = r + dir[0];
                int j_ = c + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0) {
                    sum += grid[i_][j_];
                    grid[i_][j_] = 0;
                    que.push({i_, j_});
                }
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = bfs(i, j, grid);
                    if (sum % k == 0)
                        count++;
                }
            }
        }

        return count;
    }
};
