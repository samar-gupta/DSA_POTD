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
