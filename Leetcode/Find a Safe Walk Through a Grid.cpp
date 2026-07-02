//Leetcode Link : https://leetcode.com/problems/find-a-safe-walk-through-a-grid

//Appoach-1 Using Dijkstra's
//T.C : O(E · log V) = O(m·n · log(m·n))
//S.C : O(m*n)
class Solution {
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    typedef pair<int, pair<int,int>> P;

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        priority_queue<P, vector<P>, greater<P>> pq;

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        result[0][0] = grid[0][0]; //Source = {0, 0}
        pq.push({result[0][0], {0, 0}});

        while (!pq.empty()) {
            auto [d, cell] = pq.top();
            auto [r, c] = cell;
            pq.pop();

            if (d > result[r][c]) continue;

            for (auto &dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                if (d + grid[nr][nc] < result[nr][nc]) {
                    result[nr][nc] = d + grid[nr][nc];
                    pq.push({d + grid[nr][nc], {nr, nc}});
                }
            }
        }

        return health - result[m-1][n-1] >= 1;
    }
};


//Appoach-2 (Using 0-1 BFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        deque<pair<int,int>> dq;

        result[0][0] = grid[0][0]; //source {0, 0}
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            for (auto &dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                if (result[r][c] + grid[nr][nc] < result[nr][nc]) {

                    result[nr][nc] = result[r][c] + grid[nr][nc];

                    if (grid[nr][nc] == 0) 
                        dq.push_front({nr, nc});
                    else
                        dq.push_back({nr, nc});
                }
            }
        }

        return health - result[m-1][n-1] >= 1;
    }
};
