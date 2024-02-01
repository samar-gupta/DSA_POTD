//Company Tags     : Google
//Leetcode Link    : https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/

//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> result;
        
        sort(begin(nums), end(nums));
        
        for(int i = 0; i < n; i += 3) {          //i <= n-3 
            if(nums[i+2] - nums[i] > k) {
                return {};
            }
            
            result.push_back({nums[i], nums[i+1], nums[i+2]});
        }
        
        return result;
    }
};
