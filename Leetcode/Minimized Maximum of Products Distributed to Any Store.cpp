//Leetcode Link : https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo = 1;
        int hi = 1e5;
        int ans = -1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (isItPossible(mid, quantities, n)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
    
private:
    bool isItPossible(int x, vector<int>& quantities, int n) {
        for (int products : quantities) {
            // Calculate how many shops are required to distribute `products` with max `x` per shop
            n -= (products + x - 1) / x; // Equivalent to `ceil(products / x)` using integer arithmetic
            
            if (n < 0) // More shops needed than available
                return false;
        }
        return true; // All products distributed within available shops
    }
};
