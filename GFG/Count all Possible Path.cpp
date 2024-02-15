class Solution {
public:
int isPossible(vector<vector<int>>paths){
    int n = paths.size();
    int m = paths[0].size();
    int count = 0;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(paths[i][j] == 1){
                count++;
            }
        }
        if(count % 2 != 0){
            return 0;
        }
    }
    
    return 1;
}
};
