class Solution{
public:
    int mod = 1003;
    int t[101][101][2];
    
    int solve(int i, int j, int isTrue, string &s){
        if(i==j){
            if(s[i]=='T' && isTrue == 1) return 1;
            else if(s[i] == 'F' && isTrue == 0) return 1;
            else return 0;
        }
        
        if(t[i][j][isTrue]!=-1) return t[i][j][isTrue];
        
        int count = 0;
        
        for(int idx = i+1; idx<=j-1; idx+=2){
            
            int lt = solve(i,idx-1,1,s), rt = solve(idx+1,j,1,s);       //l-left, r-right, t-true, f-false, lt-leftTrue, rf-rightTrue
            int lf = solve(i,idx-1,0,s), rf = solve(idx+1,j,0,s);
            
            if(s[idx]=='&'){
                if(isTrue == 1){
                    count = (count + lt*rt)%mod;
                }else{
                    count = (count + lt*rf + lf*rt + lf*rf)%mod;
                }
            }else if(s[idx] =='|'){
                if(isTrue == 1){
                    count = (count + lt*rf + lf*rt + lt*rt)%mod;
                }else{
                    count = (count + lf*rf)%mod;
                }
                
            }else{
                if(isTrue==1){
                    count = (count + lt*rf + lf*rt)%mod;
                }else{
                    count = (count +lt*rt + lf*rf)%mod; 
                }
            }
        }
        
        return t[i][j][isTrue] = count;
    }
    
    int countWays(int n, string s){
        // code here
        memset(t, -1, sizeof(t));
        return solve(0,n-1,1,s);
    }
};
