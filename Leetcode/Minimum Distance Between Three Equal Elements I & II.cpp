/*
    Leetcode Link               : https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i
                                  https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii
*/
//You can do brute force for all three indices for a number.

//Approach - Optimal : Using map forstoring indices and checking for 3 indices for a number 
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        int result = INT_MAX;

        for(int k = 0; k < n; k++) {
            mp[nums[k]].push_back(k);

            if(mp[nums[k]].size() >= 3) {
                vector<int> &vec = mp[nums[k]];
                int siz = vec.size();

                int i = vec[siz-3];
                result = min(result, k-i);
            }
        }

        return result >= INT_MAX ? -1 : 2*result;
    }
};
