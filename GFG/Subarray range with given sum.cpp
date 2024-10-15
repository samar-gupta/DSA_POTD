class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        // Your code here
        unordered_map<int,int> mp;
        int n = arr.size();
        int sum = 0;
        int cnt=  0;
        for(int i = 0 ; i < n ; i++){
            sum+=arr[i];
            if(sum == tar) cnt++;
            if(mp.find(sum - tar) != mp.end()){
                cnt+=mp[sum-tar];
            }
            mp[sum]++;
        }
        return cnt;
    }
};
