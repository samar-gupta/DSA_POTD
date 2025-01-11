class Solution {
  public:
    int longestUniqueSubstr(string &S) {
        // code here
        unordered_map<int, int> mp;
        int i = 0; 
        int j = 0;
        int n = S.length();
        int ans = 0;
        while(i < n){
            mp[S[i]]++;
            while(mp[S[i]] > 1){
                mp[S[j]]--;
                j++;
            }
            ans = max(i - j + 1, ans);
            i++;
        }
        return ans;
    }
};
