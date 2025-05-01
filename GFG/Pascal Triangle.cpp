class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<int> ans(n, 1);
        for(int i=1;i<n;i++) {
           for(int j=i-1;j>0;j--) {
               ans[j]=ans[j]+ans[j-1];
           }
        }
        return ans;
    }
};
