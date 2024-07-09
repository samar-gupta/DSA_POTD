class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = -1, minDiff = INT_MAX;
        
        for(int i=0; i<n; i++){
            int L = i+1, R = n-1;
            
            int currSum = 0;
            
            while(L<R){
                int currSum = arr[i] + arr[L] + arr[R];
                int currDiff = abs(currSum - target);
                
                if(currDiff < minDiff){
                    minDiff = currDiff;
                    ans = currSum;
                }
                else if(currDiff == minDiff){
                    ans = max(ans, currSum);
                }
                
                if(currSum > target) R--;
                else if(currSum == target) return target;
                else L++;
            }
        }
        
        return ans;
    }
};
