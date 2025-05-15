class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        int ans=s.size();
        unordered_map<int,int>mp;
        for(auto c: s){
            if(mp.find(c)!=mp.end()) ans+=mp[c];
            mp[c]++;
        }
        return ans;
    }
};
