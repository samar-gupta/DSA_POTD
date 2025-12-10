//Approach:
//This approach finds the missing and repeating numbers 
//by comparing what the sum and sum of squares should be 
//for numbers from 1 to n with what they actually are in the array. 
//The difference between expected and actual sum gives (missing – repeating), 
//and the difference between expected and actual sum of squares gives (missing² – repeating²). 
//Dividing these two differences gives (missing + repeating). 
//Once we have both (missing – repeating) and (missing + repeating), 
//we simply solve the two equations to get the missing and repeating numbers. 
//This avoids overflow from using products and works efficiently using only sums and squared sums.
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long n=arr.size();
        long aSum=(n*(n+1))/2;
        long aSum2=(n*(n+1)*(2*n+1))/6;
        long obSum=0;
        long obSum2=0;
        for(long val:arr){
            obSum+=val;
            obSum2+=(val*val);
            
        }
        long val1=aSum-obSum;
        long val2=aSum2-obSum2;
        val2=val2/val1;
        int missing=(val1+val2)/2;
        int repeating =val2-missing;
        return {repeating,missing};
    }
};


//Approach:
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int repeated = 0, missing = 0;
        
        unordered_map<int, int> freq;
        
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2) {
                repeated = i; 
            }
            if (freq[i] == 0) {
                missing = i;  
            }
        }
        
        return {repeated, missing};
    }
};
