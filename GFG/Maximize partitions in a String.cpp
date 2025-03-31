//Approach-1 : 
class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        int n = s.size();
        vector<int> mp(26);
        for(int i = 0; i < n; i++) {
            mp[s[i]-'a'] = i;
        }
        int ans = 0, ind = 0;
        for(int i = 0; i < n; i++) {
            ind = max(ind, mp[s[i]-'a']);
            if (ind == i) {
                ans++;
            }
        }
        return ans;
    }
};


//Approach-1 :
class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        unordered_map<char, int> lastIndex;
        int n = s.size();
        
        // Store last occurrence of each character
        for (int i = 0; i < n; i++) {
            lastIndex[s[i]] = i;
        }

        int partitions = 0, maxLast = -1;
        for (int i = 0; i < n; i++) {
            maxLast = max(maxLast, lastIndex[s[i]]);
            if (i == maxLast) {  // Partition ends here
                partitions++;
            }
        }
        
        return partitions;
    }
};
