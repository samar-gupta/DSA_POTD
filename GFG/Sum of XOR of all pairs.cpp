//Approach : 
/*
  1. Loop through each bit position from 0 to 31 (since numbers go up to 10⁵).
  2. For each bit:
       Count how many numbers have that bit set (1).
       Let that count be count1.
       Then count0 = n - count1.
  3. Number of pairs where XOR gives 1 at this bit:
       count1 * count0
  4. Each such pair contributes 2^bit to the answer.
  5. Add (count1 * count0 * (1 << bit)) to the result.
  6. Do this for all bits and return the final sum.
*/
class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        int n = arr.size();
        long long result = 0;
        
        for (int bit = 0; bit < 32; bit++) {
            long long count1 = 0;
            
            for (int i = 0; i < n; i++) {
                if (arr[i] & (1 << bit)) {
                    count1++;
                }
            }
            
            long long count0 = n - count1;
            
            result += count1 * count0 * (1LL << bit);
        }
        
        return result;
    }
};



// old
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
