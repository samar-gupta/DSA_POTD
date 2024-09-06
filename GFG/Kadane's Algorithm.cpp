class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        // code here...
        long long ans = arr[0];
        long long sum = 0;
         
        for(int i=0;i<arr.size();i++){
            sum +=arr[i];
            ans=max(ans,sum);
            if(sum<0) sum=0;
         }
         
         return ans;
    }
};
