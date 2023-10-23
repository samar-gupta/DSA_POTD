class Solution{
	public:
	int maxSumIS(int arr[], int n) {  
    
	    vector<int> dp(arr, arr+n);
    
	    for(int i = 1; i < n; i++) {
	        for(int j = 0; j < i; j++) {
            
	            if(arr[i] > arr[j]){
	                dp[i] = max(dp[i], arr[i]+dp[j]);
	            }
            
	        }
	    }
    
	    return *max_element(dp.begin(), dp.end());
	}  
};
