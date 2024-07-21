class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        int n = arr.size();
        if(n==1) return arr[0];
        long long mod = 1e9+7;
        int flag = 0;
        long long result = 1, maxi = INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                flag = 1;
                continue;
            }
            if(arr[i]<0){
                maxi = max((long long)arr[i], maxi);
            }
            result = ((result)%mod * arr[i])%mod;
            
        }
        if(result<0){
            result = result/maxi;
        }
        if(result==1 && flag==1) return 0;
        return result;
    }
};
