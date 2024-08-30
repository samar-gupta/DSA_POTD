class Solution{
public:
    bool check2(vector<int> &temp, int r, int c){
    for(int i=0; i<temp.size(); i++){
        int x = abs(temp[i] - r);
        int y= abs(i+1 - c);
        if(x==y) return false;
    }
    return true;
}
    void fun(int i, int n, vector<int> &temp, vector<vector<int>> &ans, vector<int> &vis){
        if(i>n){
            ans.push_back(temp);
            return;
        }
        
        for(int j=1; j<=n; j++){
            if(vis[j]==0 && check2(temp,j,i)){
                vis[j]=1;
                temp.push_back(j);
                fun(i+1,n,temp,ans,vis);
                temp.pop_back();
                vis[j]=0;
            }
        }
        return;
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<int> temp;
        vector<vector<int>> ans;
        vector<int> vis(n+1,0);
        fun(1,n,temp,ans,vis);
        return ans;
    }
};
