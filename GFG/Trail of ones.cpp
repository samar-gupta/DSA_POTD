//updated
// Approach: Use an iterative Fibonacci-based recurrence—at each length i, double the previous count (append 0 or 1) and add Fib(i) for new “11” endings.
// Time Complexity: O(n) because we loop from 3 to n once.
// Space Complexity: O(1) using only a fixed number of integer variables.
class Solution {
public:
    int countConsec(int n) {
        if (n == 2) {                // Base: only "11" has consecutive 1’s when length = 2
            return 1;
        }

        int firstNum  = 0;          // Fib(i-2)
        int secondNum = 1;          // Fib(i-1)
        int thirdNum;               // Fib(i)
        int result = 1;             // Count of “bad” strings for length = 2

        for (int i = 3; i <= n; ++i) {
            thirdNum  = firstNum + secondNum;     // Compute Fib(i)
            result    = result * 2 + thirdNum;    // Double previous + new “11” endings
            firstNum  = secondNum;                // Shift window
            secondNum = thirdNum;
        }

        return result;               // Final count for length = n
    }
};



//old
class Solution {
  public:
    long long MOD=1e9+7;
    long long power(long long a, long long b){
        long long ans=1;
        while(b>0){
            if(b&1){
                ans*=a;
                ans%=MOD;
            }
            a*=a;
            a%=MOD;
            b >>=1;
        }
        return ans;

    }
  
    int numberOfConsecutiveOnes(int n) {
        // code here
        vector<int>a(n);
        vector<int>b(n);
        
        a[0]=1; b[0]=1;
        for(int i=1;i<n;i++){
            a[i]=(a[i-1]+b[i-1])%MOD;
            b[i]=a[i-1];
        }
        
        return (power(2,n)+MOD - (a[n-1]+b[n-1])%MOD)%MOD;
    }
};
