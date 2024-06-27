//Approach-1 : (From 0th index to last index)
bool isToeplitz(vector<vector<int>>& mat) {
  //code here
  int n=mat.size();
    int m=mat[0].size();
    
    int i=0;
    int j=0;
    while(j<m){
        int x=0;
        int y=j;
        int val=mat[x][y];
        while(x<n and y<m){
            if(mat[x][y]!=val) return false;
            x++;
            y++;
        }
        j++;
    }
    
    i=1;
    while(i<n){
        int x=i;
        int y=0;
        int val=mat[x][y];
        while(x<n and y<m){
            if(mat[x][y]!=val) return false;
            x++;
            y++;
        }
        i++;
    }
    return true;
    
}



//Approach-2 : (Trick) (starting from 1st index to compare with previous diagonal) 
bool isToeplitz(vector<vector<int>>& mat) {
    // code here
    int n = mat.size();
    int m = mat[0].size();
    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[i][j]!=mat[i-1][j-1]) 
                return false;
       }
    }
    return true;
}
