//Leetcode Link : https://leetcode.com/problems/number-of-unique-xor-triplets-i

//Approach (Bit observation)
//T.C : O(log2(n))
//S.C : O(1)
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n == 1 || n == 2)
            return n;
        
        int ans = 1; //2^0;
        while(ans <= n) {
            ans = (ans << 1);    // ans *= 2
        }

        return ans;
    }
};
