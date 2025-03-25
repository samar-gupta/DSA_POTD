//updated (working)
class Solution {
  public:
    bool evaluate(int b1, int b2, char op){
        if(op == '&'){
            return b1& b2;
        }
        else if(op == '|'){
            return b1|b2;
        }
        else{
            return b1^b2;
        }
    }
  
    int helper(int start, int end, int req, string &s, vector<vector<vector<int>>>&dp){
        if(start==end){
            return (req == (s[start]=='T')) ? 1:0;
        }
        
        if(dp[start][end][req]!=-1) return dp[start][end][req];
        
        int ans=0;
        for(int k=start+1;k<end;k++){
            int leftTrue = helper(start, k-1, 1, s, dp);
            int leftFalse = helper(start, k-1, 0, s, dp);
            
            int rightTrue=  helper(k+1, end, 1, s, dp);
            int rightFalse = helper(k+1, end , 0, s, dp);
            
            if(evaluate(1,1, s[k]) == req){
                ans+=leftTrue*rightTrue;
            }
            if(evaluate(1,0, s[k]) == req){
                ans+=leftTrue*rightFalse;
            }
            if(evaluate(0,1, s[k]) == req){
                ans+=leftFalse*rightTrue;
            }
            if(evaluate(0,0, s[k]) == req){
                ans+=leftFalse*rightFalse;
            }
        }
        return dp[start][end][req] =  ans;
    }
  
    int countWays(string &s) {
        // code here
        int n=s.length();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(2,-1)));
        return helper(0, n-1, 1, s, dp);
    }
};



//old version
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
