class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	long ans = 0;
    	for(int i=0; i<32; i++) {

    	    long zeros = 0, ones = 0;
    	    
    	    for(int j=0; j<n; j++) {
    	        
    	        if(arr[j]%2 == 0) zeros++;         //(arr[j] & (1 << i)) == 0)
    	            else ones++;
    	        
    	        arr[j] = arr[j] / 2;
    	    }
    	    
    	    ans += (zeros*ones)*(1<<i);
    	}
    	
    	return ans;
    }
};
