class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        // your code here
        int s=0, maxSum = INT_MIN, minSum=INT_MAX, curr=0, currNeg=0;
        for(int i: arr){
            s+=i;
            curr = max(curr+i, i);
            maxSum = max(curr, maxSum);
            
            currNeg = min(i, currNeg+i);
            minSum = min(minSum, currNeg);
        }
        
        if(s == minSum){
            return maxSum;
        }
        return max(maxSum, s-minSum);
    }
};
