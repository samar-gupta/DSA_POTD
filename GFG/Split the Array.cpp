class Solution {
  public:
    int countgroup(vector<int>& arr) {
        // Complete the function
        int n=arr.size();
        int xorAll = 0, mod = 1e9 + 7;
        
        for(int i=0; i<n; i++){
            xorAll^=arr[i];         
        }
        
        if(xorAll!=0){
            return 0;
        }
        
        return int(pow(2,n-1)-1)%mod;
    }
};
