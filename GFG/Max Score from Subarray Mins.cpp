//Approach : Indirectly this question is same as the max sum of consecutive numbers because the two numbers will always be the smallest and second smallest for the subarray of two elements.
           // They just made it tricky by asking for all subarray and adding min two element sum
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int ans = 0;
        
        for(int i = 0; i < n-1; i++){
            ans = max(ans, arr[i] + arr[i+1]);
        }
        return ans;
    }
};
