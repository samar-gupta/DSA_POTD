//Approach-1 : Using hash map to store the frequency of prefix sums I've seen so far
//T.C : O(n)
//S.C : O(n)
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
