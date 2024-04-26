class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& mat) {
        vector<pair<int,int>> p = {{0,1}, {1,0}, {0,-1}, {-1,0}};            // or vector<pair<int,int>> p = {make_pair(0,1), make_pair(1,0), make_pair(0,-1), make_pair(-1,0)};    
        int pi=0,i=0,j=0;
        while(true){
            if(mat[i][j]==1) {mat[i][j]=0;pi=(pi+1)%4;}
            i+=p[pi].first;
            j+=p[pi].second;
            if(i<0 || j<0 || i>=n || j>=m) {
                return {i-p[pi].first,j-p[pi].second};
            }
        }
    }
};
