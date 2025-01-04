class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int n = arr.size();
        int count = 0;
        unordered_map<int,int>mp;
 
        for(auto &i : arr) 
            mp[i]++;
        
        for(int i = 0; i < n; i++) { 
            mp[arr[i]]--;
            for(int j = i-1; j>=0; j--) {
                int pairsum = arr[i] + arr[j];
                if(mp.find(target - pairsum) != mp.end()) {
                    count += mp[target - pairsum];
                }
            }
        }
        
        return count;
    }
};
