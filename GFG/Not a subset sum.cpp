class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        // Your code goes here.
        int ans=1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=ans){
                ans = ans+arr[i];
            }
        }
        return ans;
    }
};
