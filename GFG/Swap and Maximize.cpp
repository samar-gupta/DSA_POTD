class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        sort(begin(arr), end(arr));
        
        long long res=0;
        
        for(int i=0;i<n;i++) {
            res+=abs(arr[i]-arr[n-i-1]);
        }
    
        return res;
    }
};
