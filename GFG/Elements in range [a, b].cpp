class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        // Sort the array
        sort(arr.begin(),arr.end());
        
        vector<int> ans;
        
        for (auto &q : queries) {
            int a=q[0];
            int b=q[1];
            
            // First element >= a
            int left=lower_bound(arr.begin(),arr.end(),a) - arr.begin();
            
            // First element > b
            int right = upper_bound(arr.begin(),arr.end(),b) - arr.begin();
            
            ans.push_back(right - left);
        }
        
        return ans;
    }
};
