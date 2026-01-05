Approach:
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size(); 
        int l = 0;
        int r = k;
        
        int currSum = accumulate(arr.begin(), arr.begin()+k, 0);
        int result = currSum;
        
        while(r<n) {
            currSum = currSum + arr[r] - arr[l];
            result = max(result, currSum);
            l++;
            r++;
        }
        
        return result;
    }
};


//old
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int K) {
        // code here
        int N = arr.size();
        long long sum=0,maxans=0;
        for(int i=0;i<K;i++) sum+=arr[i];
        maxans=max(maxans,sum);
        for(int i=K;i<N;i++){
            sum-=arr[i-K];
            sum+=arr[i];
            maxans=max(maxans,sum);
        }
        return maxans;
    }
};
