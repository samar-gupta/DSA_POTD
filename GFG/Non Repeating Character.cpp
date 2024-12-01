class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        // Your code here
        vector<int>vis(26,0);
        for(char i:s) vis[i-'a']++;
        for(char i:s){
            if(vis[i-'a']==1) return i;
        }
        return '$';
    }
};
