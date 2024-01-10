class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int ans = 0, sum = 0;
	    unordered_map<int, int> mm;
	    
	    for(int i = 0; i<n; i++) {
        
	        sum += arr[i];
	        int rem = sum % k;
	        
	        if(rem < 0) rem += k;
	        
	        if(rem == 0) {
	            ans = i + 1;
	        }
	        
	        else {
	            if(mm[rem]) ans = max(ans, i+1 - mm[rem]);
	            else mm[rem] = i+1;
	        }
	    }
	    
	    return ans;
	}
};
