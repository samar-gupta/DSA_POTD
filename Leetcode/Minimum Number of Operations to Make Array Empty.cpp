//Leetcode Link  : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        
        int result = 0;
        
        for(auto &it : mp) {
            int freq = it.second;
            
            if(freq == 1) { //we can only remove equal elements
                return -1;
            }
            
            result += ceil((double)freq/3);
        }
        
        return result;
    }
};
