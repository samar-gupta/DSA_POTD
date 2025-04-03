//Approach-1 : (Using queue)
class Solution {
  public:
    bool isSafe(int x,int y,vector<vector<int>>& mat){
        return x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size() && mat[x][y] == 1;
    }
    
    int orangesRotting(vector<vector<int>>& mat) {
        //code here
        int m = mat.size(),n = mat[0].size();
        int freshOrg = 0,time = 0;
        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};
        queue<pair<int,int>> pq;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 2)
                    pq.push({i,j});
                    
                if(mat[i][j] == 1)
                    freshOrg++;
            }
        }
        
        while(!pq.empty() && freshOrg){
            int size = pq.size();
            
            for(int sz=0;sz<size;sz++){
                auto idxs = pq.front();
                pq.pop();
                
                for(int k=0;k<4;k++){
                    int newi = idxs.first + dx[k];
                    int newj = idxs.second + dy[k];
                                
                    if(isSafe(newi,newj,mat)){
                        mat[newi][newj] = 2;
                        pq.push({newi,newj});
                        freshOrg--;
                    }
                }
            }
            time++;
            if(!freshOrg) break;
        }
        
        return freshOrg == 0 ? time : -1;
    }
};


//Approach-1 : (Using deque)
class Solution {
  public:
    bool isSafe(int x,int y,vector<vector<int>>& mat){
        return x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size() && mat[x][y] == 1;
    }
    
    int orangesRotting(vector<vector<int>>& mat) {
        //code here
        int m = mat.size(),n = mat[0].size();
        int freshOrg = 0,time = 0;
        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};
        deque<pair<int,int>> dq;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 2)
                    dq.push_back({i,j});
                    
                if(mat[i][j] == 1)
                    freshOrg++;
            }
        }
        
        while(!dq.empty() && freshOrg){
            int size = dq.size();
            
            for(int sz=0;sz<size;sz++){
                auto idxs = dq.front();
                dq.pop_front();
                
                for(int k=0;k<4;k++){
                    int newi = idxs.first + dx[k];
                    int newj = idxs.second + dy[k];
                                
                    if(isSafe(newi,newj,mat)){
                        mat[newi][newj] = 2;
                        dq.push_back({newi,newj});
                        freshOrg--;
                    }
                }
            }
            time++;
            if(!freshOrg) break;
        }
        
        return freshOrg == 0 ? time : -1;
    }
};
