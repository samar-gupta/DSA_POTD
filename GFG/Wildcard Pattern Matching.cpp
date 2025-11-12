//Approach-1 :
class Solution {
  public:
    bool wildCard(string &str, string &pattern) {
        // code here
        int n = pattern.size();
        int m = str.size();

        // Create a 2D DP array initialized with 0
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Iterate over the pattern and string in reverse order
        for (int i = n; i >= 0; i--) {
            for (int j = m; j >= 0; j--) {
                
                // Case 1: Both pattern and string are fully traversed
                if (i == n && j == m) {
                    dp[i][j] = 1;
                }
                
                // Case 2: Pattern is fully traversed, but string is not
                else if (i == n) {
                    dp[i][j] = 0;
                }
                
                // Case 3: String is fully traversed, but pattern is not
                else if (j == m) {
                    if (pattern[i] == '*') {
                        // '*' can match an empty sequence
                        dp[i][j] = dp[i+1][j];
                    } else {
                        dp[i][j] = 0;
                    }
                }
                
                // Case 4: Compare characters of pattern and string
                else {
                    if (pattern[i] == str[j]) {
                        // Characters match, move both pointers
                        dp[i][j] = dp[i+1][j+1];
                    } 
                    else if (pattern[i] == '?') {
                        // '?' matches any single character
                        dp[i][j] = dp[i+1][j+1];
                    } 
                    else if (pattern[i] == '*') {
                        // '*' can match an empty sequence or any sequence
                        dp[i][j] = dp[i+1][j] || dp[i][j+1];
                    } 
                    else {
                        // Characters do not match
                        dp[i][j] = 0;
                    }
                }
            }
        }
        
        // Return the result for the entire strings
        return dp[0][0];
    }
};



//old
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
