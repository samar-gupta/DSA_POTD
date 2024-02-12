class Solution {
    static long sequence(int n) {
        int mod = 1000000007;
        long ans = 1;
        int k = 2;
        for (int i = 2; i <= n; i++) {
            long t = 1;
            for (int j = 1; j <= i; j++) {
                t = (t * k) % mod;
                k++;
            }
            ans = (ans + t) % mod;
        }
        return ans;
    }
}
