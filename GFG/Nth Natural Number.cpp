class Solution {
  public:
    long long findNth(long long n) {
        // code here.
        long ans=0, base=1;
        while(n>0){
            long rem = n%9;
            ans += rem * base;
            n /= 9;
            base *= 10;
        }
        return ans;
    }
};
