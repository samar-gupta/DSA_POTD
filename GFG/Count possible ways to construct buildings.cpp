//T.C - O(N)
//S.C - O(1)         //only variables are used
class Solution{
	public:
	int TotalWays(int N)
	{
	    int mod = 1e9+7;
	    long a = 1, b = 2, c = 2;     //as c will be storing result, so declaring c with any value
	    
	    for(int i = 2; i <= N; i++) {
	        c = (a + b) % mod;
	        a = b;
	        b = c;
	    }
	    
	    return (c*c) % mod;
	}
};
