class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<int,int> mp;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i<n; i++) {
            sum += arr[i];
            if(mp.find(sum - k) != mp.end()) 
            {
                ans += mp[sum - k];
            }
            if(sum == k)
                ans ++;
            mp[sum]++;
        }
        return ans;
    }
};
