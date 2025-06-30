//Company Tags  : LiveRamp
//Leetcode Link : https://leetcode.com/problems/longest-harmonious-subsequence/

//Approach (Using map and counting)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;

        int result = 0; //to store maximum subsequence length

        for(int &num : nums) {
            mp[num]++;
        }

        for(int &num : nums) {
            int minNum = num;
            int maxNum = num+1;

            if(mp.count(maxNum)) {
                result = max(result, mp[minNum] + mp[maxNum]);
            }
        }

        return result;
    }
};
