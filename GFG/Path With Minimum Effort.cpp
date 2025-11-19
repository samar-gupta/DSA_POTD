//Approach-1 : 
class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>> > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [cost, cell] = pq.top();
            pq.pop();

            int r = cell.first;
            int c = cell.second;

            if (r == n - 1 && c == m - 1)
                return cost;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int diff = abs(mat[r][c] - mat[nr][nc]);
                    int newCost = max(cost, diff);

                    if (newCost < dist[nr][nc]) {
                        dist[nr][nc] = newCost;
                        pq.push({newCost, {nr, nc}});
                    }
                }
            }
        }

        return -1;
    }
};



//old
class Solution {
  public:
    int MinimumEffort(int n, int m, vector<vector<int>> &heights) {
        // code here
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>>dist(n, vector<int>(m,INT_MAX));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            int step=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            
            pq.pop();
            
            if(row==n-1 && col==m-1){
                return step;
            }
            
            int nrow, ncol;
            
            nrow=row-1; ncol=col;
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                int val=max(step, abs(heights[nrow][ncol]-heights[row][col]));
                if(val<dist[nrow][ncol]){
                    dist[nrow][ncol]=val;
                    pq.push({val, {nrow,ncol}});
                }
            }
            nrow=row+1; ncol=col;
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                int val=max(step, abs(heights[nrow][ncol]-heights[row][col]));
                if(val<dist[nrow][ncol]){
                    dist[nrow][ncol]=val;
                    pq.push({val, {nrow,ncol}});
                }
            }
            nrow=row; ncol=col-1;
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                int val=max(step, abs(heights[nrow][ncol]-heights[row][col]));
                if(val<dist[nrow][ncol]){
                    dist[nrow][ncol]=val;
                    pq.push({val, {nrow,ncol}});
                }
            }
            nrow=row; ncol=col+1;
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                int val=max(step, abs(heights[nrow][ncol]-heights[row][col]));
                if(val<dist[nrow][ncol]){
                    dist[nrow][ncol]=val;
                    pq.push({val, {nrow,ncol}});
                }
            }
        }
      
        return dist[n-1][m-1];
    }
};
