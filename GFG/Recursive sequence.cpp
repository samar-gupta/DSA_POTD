**************************************************/  C++ /********************************************************************
class Solution{
public:
    long long sequence(int n){
        int mod = 1e9+7;
        
        long long ans = 1;
        int k = 2;
        
        for(int i = 2; i <= n; i++) {
            
            long long t = 1;
            
            for(int j = 1; j <= i; j++) {
                t = (t * k) % mod;
                k++;
            }
            
            ans = (ans + t) % mod;
        }
        
        return ans;
    }
};





**************************************************/  Python /********************************************************************
  class Solution:
    def sequence(self, n):
        mod = 10**9 + 7
        ans = 1
        k = 2
        for i in range(2, n + 1):
            t = 1
            for j in range(1, i + 1):
                t = (t * k) % mod
                k += 1
            ans = (ans + t) % mod
        return ans
  
