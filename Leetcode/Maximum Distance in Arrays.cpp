//Leetcode Link : https://leetcode.com/problems/maximum-distance-in-arrays

//Approach - Simple Greedy
//T.C : O(m)
//S.C : O(1)
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int MIN = arrays[0].front();
        int MAX = arrays[0].back();

        int result = 0;

        for(int i = 1; i < arrays.size(); i++) {
            int currMin = arrays[i].front();
            int currMax = arrays[i].back();

            result = max({result, abs(currMin - MAX), abs(currMax - MIN)});

            MAX = max(MAX, currMax);
            MIN = min(MIN, currMin);
        }
        return result;
    }
};
