//Leetcode Link : https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/

//Approach-1 (Using BFS) - TLE
//T.C : O(Q * m * n)
//S.C : O(m * n)
class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int bfs(vector<vector<int>>& grid, int val, int m, int n) {
        queue<pair<int, int>> que;
        que.push({0, 0});

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;

        int points = 0;
        while(!que.empty()) {
            int N = que.size();

            while(N--) {
                auto [i, j] = que.front();
                que.pop();

                if(grid[i][j] > val) {
                    continue;
                }

                points++;

                for(auto &dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_] && grid[i_][j_] < val) {
                        que.push({i_, j_});
                        visited[i_][j_] = true;
                    }
                }
            }
        }

        return points;
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();

        int Q = queries.size();
        vector<int> result(Q, 0);
        for(int i = 0; i < Q; i++) {
            result[i] = bfs(grid, queries[i], m, n);
        }

        return result;
    }
};


//Approach-2 (Using DFS) - TLE
//T.C : O(Q * m * n)
//S.C : O(m * n)
class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dfs(vector<vector<int>>& grid, int i, int j, int val, vector<vector<bool>>& visited, int m, int n) {
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] >= val) {
            return 0;
        }

        visited[i][j] = true;
        int points = 1;

        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            points += dfs(grid, i_, j_, val, visited, m, n);
        }

        return points;
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();

        int Q = queries.size();
        vector<int> result(Q, 0);
        for(int i = 0; i < Q; i++) {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            result[i] = dfs(grid, 0, 0, queries[i], visited, m, n);
        }

        return result;
    }
};


//Approach-3 (Optimal Approach using sorting and min-heap)
//T.C : O(QlogQ + m*nlog(m*n)) - Notice that we won't visit any cell more than once (we mark them visited). Total cells = m*n and heap can have m*n cells in worst case
//S.C : O(m*n)
class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();

        int Q = queries.size();
        vector<int> result(Q, 0);

        vector<pair<int, int>> sortedQ;
        for(int i = 0; i < Q; i++) {
            sortedQ.push_back({queries[i], i});
        }

        sort(begin(sortedQ), end(sortedQ));

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int points = 0;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;


        for(int i = 0; i < Q; i++) {
            int queryValue = sortedQ[i].first;
            int idx        = sortedQ[i].second;
            while(!pq.empty() && pq.top()[0] < queryValue) {
                int i = pq.top()[1];
                int j = pq.top()[2];
                pq.pop();
                points++;

                for(auto &dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
                        pq.push({grid[i_][j_], i_, j_});
                        visited[i_][j_] = true;
                    }
                }
            }
            result[idx] = points;
        }
        
        return result;
    }
};
