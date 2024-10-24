class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
        int n = arr.size();
        if(n==1){
            return arr;
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=0 && arr[i+1]!=0 && arr[i]==arr[i+1]){
                arr[i]+=arr[i];
                arr[i+1] = 0;
            }
        }
        vector<int>ans(n);
        int i = 0;
        int j = n-1;
        for(int k=0;k<n;k++){
            if(arr[k]==0){
                ans[j--] = arr[k];
            }
            else{
                ans[i++] = arr[k];
            }
        }
        return ans;
    }
};
