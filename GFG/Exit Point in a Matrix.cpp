//Approach - 1
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        pair<int,int> direction={0,1};
        int row=0, col=0;
        while(true){
            // cout<<matrix[row][col]<<" "<<row<<" "<<col<<" "<<direction.first<<" "<<direction.second<<endl;
            if(matrix[row][col]==1){
                if(direction.first==0 && direction.second==1){
                    direction.first=1;
                    direction.second=0;
                }
                else if(direction.first==1 && direction.second==0){
                    direction.first=0;
                    direction.second=-1;
                }
                else if(direction.first==0 && direction.second==-1){
                    direction.first=-1;
                    direction.second=0;
                }
                else if(direction.first==-1 && direction.second==0){
                    direction.first=0;
                    direction.second=1;
                }
                matrix[row][col]=0;
            }
            
            int nrow=row+direction.first;
            int ncol=col+direction.second;
            
            if(nrow>=n || nrow<0 || ncol>=m || ncol<0){
                return {row,col};   
            }
            
            row=nrow;
            col=ncol;
        }
    }
};



//Approach - 2
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
