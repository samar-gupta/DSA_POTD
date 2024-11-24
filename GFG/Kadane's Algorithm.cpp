//Approach-1 : 
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


//Approach-2 : 
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int maxSum = arr[0];
        int currSum = arr[0];
        
        for (int i = 1; i < arr.size(); i++) {
            currSum = max(currSum + arr[i], arr[i]);
            maxSum = max(currSum, maxSum);
        }
        
        return maxSum;
    }
};
