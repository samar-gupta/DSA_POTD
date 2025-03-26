//Approach-1 : 
class Solution {
  public:
    int wordBreak(string &s, vector<string> &dictionary) {
        // code here
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;  

        for (int i = 0; i < n; i++) {
            if (!dp[i])
                continue;
            for (const string &word : dictionary) {
                int len = word.size();
           
                if (i + len <= n && s.substr(i, len) == word) {
                    dp[i + len] = true;
                }
            }
        }
        return dp[n] ? 1 : 0;
    }
};


//
class Solution {
  public:
    int wordBreak(string &s, vector<string> &dictionary) {
        // code here
        int n=s.length();
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(auto it: dictionary){
                int start= i- it.size();
                if(start>=0 && dp[start] && s.substr(start, it.size()) == it){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
    }
};


//old version
class Solution {
public:
    bool solve(int idx,int n,string s,unordered_set<string> st)
    {
        if(idx == n) 
            return true;
        
        string k;
        
        for(int l=1; idx+l<=n; l++)
        {
            k = s.substr(idx,l);
            if(st.find(k) != st.end())
            {
                if(solve(idx+l,n,s,st) == true)
                return true;
            }
        }
        
        return false;
    }
    
    int wordBreak(int n, string s, vector<string> &dictionary) {
        unordered_set<string> st;
        for(int i=0; i<n; i++) {
            st.insert(dictionary[i]);
        }
        bool ans = solve(0,s.size(),s,st);
        return ans;
    }
};
