class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        int ans = 0;
        int sum = 0;
        unordered_map<int, int>mp;
        mp[sum] = -1;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                sum += -1;
            } else {
                sum += 1;
            }
            if(mp.find(sum) != mp.end()){
                ans = max(ans, i-mp[sum]); 
            } else {
                mp[sum] = i;
            }
        }
        return ans;
    }
};
