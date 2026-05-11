class Solution {
  public:
    bool isPalindrome(string &s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    
    bool palindromePair(vector<string>& arr) {
        // Code here
        unordered_map<string, int> mp;
        
        int n = arr.size();
        
        // store all strings
        for(int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }
        
        for(int i = 0; i < n; i++) {
            
            string s = arr[i];
            int len = s.length();
            
            // split into prefix + suffix
            for(int j = 0; j <= len; j++) {
                
                string prefix = s.substr(0, j);
                string suffix = s.substr(j);
                
                // CASE 1:
                // prefix palindrome
                // need reverse(suffix)
                
                if(isPalindrome(prefix, 0, prefix.length() - 1)) {
                    
                    string revSuffix = suffix;
                    reverse(revSuffix.begin(), revSuffix.end());
                    
                    if(mp.count(revSuffix) && mp[revSuffix] != i) {
                        return true;
                    }
                }
                
                // CASE 2:
                // suffix palindrome
                // need reverse(prefix)
                
                // j != len avoids duplicate checking
                if(j != len && isPalindrome(suffix, 0, suffix.length() - 1)) {
                    
                    string revPrefix = prefix;
                    reverse(revPrefix.begin(), revPrefix.end());
                    
                    if(mp.count(revPrefix) && mp[revPrefix] != i) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};
