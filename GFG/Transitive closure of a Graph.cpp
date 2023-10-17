class Solution{
public:
    vector<vector<int>> transitiveClosure(int n, vector<vector<int>> grid)
    {
        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(i == j) grid[i][j]=1;
                    if(grid[i][k]==1 && grid[k][j]==1) grid[i][j]=1;
                }
            }
        }
        return grid;
    }
};
