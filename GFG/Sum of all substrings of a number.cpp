//Approach-1 : 
//T.C : O(n)
//S.C : O(n)
/*
   dp[i] = sum of all substrings upto index i such that index i is included
   final ans = dp[1] + dp[2] + .... dp[n-1] + dp[n]
*/  
class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int n = s.size();
       vector<int> dp(n+1,0); 
       int ans = dp[0];
       for(int i = 1;i<=n;i++)
       {
           dp[i] = (dp[i-1]*10) + (s[i-1] - '0')*(i);
           ans += dp[i];
           
       }
       //int ans = accumulate(dp.begin(), dp.end(),0);
       return ans;
    }
};


//Approach-2 : 
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int n = s.length();
        int result = 0;
        int prev = 0;

        for (int i = 0; i < n; ++i) {
            int digit = s[i] - '0';
            prev = (prev * 10 + (i + 1) * digit); 
            result += prev;
        }

        return result;
    }
};
