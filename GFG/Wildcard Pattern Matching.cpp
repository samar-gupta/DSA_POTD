class Solution {
  public:
    /*You are required to complete this method*/
    
    int dp[201][201];
    
    
    bool solve(string pattern , string str , int i , int j){
        if(i >= pattern.length() && j >= str.length()) return true;
        if(i >= pattern.length()) return false;
        if(j >= str.length()){
            int k = i;
            while(k < pattern.length() && pattern[k] == '*'){
                k++;
            }
            if(k >= pattern.length()) return true;
            else return false;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(pattern[i] != '*' && pattern[i] != '?'){
            if(pattern[i] == str[j]){
                return solve(pattern,str,i+1,j+1);
            }
            else{
                return false;
            }
        }
        
        else if(pattern[i] == '?'){
            return solve(pattern,str,i+1,j+1);
        }
        
        bool include = solve(pattern,str,i,j+1);
        bool exclude = solve(pattern,str,i+1,j);
        return dp[i][j] = include || exclude;
    }
    
    int wildCard(string pattern, string str) {
        memset(dp,-1,sizeof(dp));
        return solve(pattern,str,0,0);
    }
};
