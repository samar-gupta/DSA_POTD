//Approach-1 : (DP Memo)
//T.C : O(n^2) + O(n^2)
//S.C : O(n^2)
class Solution {
  public:
    
    int n;
    vector<vector<int>> dp; 
  
    bool isPalindrome(const string &s, int i, int j) {
        if (i >= j) return true;

        if (dp[i][j] != -1) return dp[i][j]; 
    
        return dp[i][j] = (s[i] == s[j]) && isPalindrome(s, i + 1, j - 1);
    }
    
    int countPS(string &s) {
        // code here
        n = s.size();

        dp.assign(n, vector<int>(n, -1));

        int count = 0;
    
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { 
                if (isPalindrome(s, i, j))  count++;
            }
        }
        return count;
    }
};


//Approach-2 : (DP Tabulation)
//T.C : O(n^2) 
//S.C : O(n^2)
class Solution {
  public:
    int countPS(string &s) {
        // code here
        int n = s.length();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int count = 0;

        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {
                
                if (gap == 0) dp[i][j] = true;
                else if (gap == 1)  dp[i][j] = (s[i] == s[j]);
                else dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];

                if (dp[i][j] && (j - i + 1) >= 2) count++;
            }
        }

        return count;
    }
};


//Approach-3 : 
//T.C : O(n^2) 
//S.C : O(1)
class Solution {
  public:
  
    int expandFromCenter(const string &s, int left, int right) {
        int count = 0;

        while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
            if (right - left + 1 >= 2) count++;
            left--;
            right++;
        }

        return count;
    }
    
    int countPS(string &s) {
        // code here
        int n = s.size();
        int count = 0;

        for (int center = 0; center < n; center++) {
            count += expandFromCenter(s, center, center);
            count += expandFromCenter(s, center, center + 1);
        }

        return count;
    }
};



//old
class Solution {
  public:
    int expand(int l,int r,string s){
        int cnt=0;
        int n=s.length();
        while(l>=0 && r<n && s[l]==s[r]){
            if(r-l>=1) cnt++;
            l--;
            r++;
        }
        return cnt;
    }
    
    int countPS(string &s) {
        // code here
        // centre expansion method
        int ans=0;
        int n=s.length();
        for(int i=0;i+1<n;i++){
            // consider a single centre
            ans+=expand(i,i,s);
            // consider 2 centres
            ans+=expand(i,i+1,s);
        }
        return ans;
    }
};
