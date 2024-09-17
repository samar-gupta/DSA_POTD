class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int mini = arr[0] + k;
        int maxi = arr[n-1] - k;
        int ans = arr[n-1] - arr[0];
        for(int i = 0;i<arr.size();i++){
            int low = min(mini,arr[i+1] - k);
            int high = max(maxi,arr[i] + k);
            if(low>=0){
                ans = min(ans,abs(high-low));
            }
        }
        
        return ans;
    }
};
