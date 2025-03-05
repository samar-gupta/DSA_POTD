//updated
class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
        // Sort words by length
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        
        unordered_map<string, int> dp; // Stores longest chain ending at word
        int maxLength = 1;
        
        for (const string &word : words) {
            dp[word] = 1; // Initialize chain length as 1
            
            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1); // Remove 1 char
                if(dp.find(prev) != dp.end()) { 
                    dp[word] = max(dp[word], dp[prev] + 1);
                }
            }
            
            maxLength = max(maxLength, dp[word]);
        }
        
        return maxLength;
    }
};


//old 
class Solution {
  public:
    bool static comp (string &s1, string &s2){
        return s1.length() < s2.length();
    }
    
    bool check(string &s1, string &s2){
        if(s1.length() != s2.length() + 1){
            return false;
        }
        int i = 0;
        int j = 0;
        while(i < s1.length()){
            if(j < s2.length() && s1[i] == s2[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return i == s1.length() && j == s2.length();
    }
    
    int longestStringChain(vector<string>& words) {
        // Code here
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp (n, 0);
        dp[0] = 1;
        int ans = 1;
        for(int i = 1; i < n; i++){
            int curr = 1;
            for(int j = 0; j < i; j++){
                if(check(words[i], words[j])){
                    curr = max(curr, dp[j] + 1);
                }
            }
            ans = max(curr, ans);
            dp[i] = curr;
        }
        return ans;
    }
};
