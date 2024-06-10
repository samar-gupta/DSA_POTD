//Leetcode Link : https://leetcode.com/problems/height-checker/?envType=daily-question&envId=2024-06-10

//Approach : (Using Counting Sort for practice) , we can use just //sort(begin(heights), end(heights));
class Solution {
public:
    void countingSort(vector<int>& nums) {
        int minVal = *min_element(begin(nums), end(nums));
        int maxVal = *max_element(begin(nums), end(nums));

        unordered_map<int, int> mp;
        for(int &num : nums) {
            mp[num]++;
        }

        int i = 0;
        for(int num = minVal; num <= maxVal; num++) {
            while(mp[num] > 0) {
                nums[i] = num;
                i++;
                mp[num]--;
            }
        }
    }

    int heightChecker(vector<int>& heights) {
        int n = heights.size();

        vector<int> sortedHeights = heights;
        countingSort(sortedHeights);

        int result = 0;
        for(int i = 0; i < n; i++) {
            if(heights[i] != sortedHeights[i]) {
                result++;
            }
        }

        return result;
    }
};
