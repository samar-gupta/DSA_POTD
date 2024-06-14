//Leetcode Link : https://leetcode.com/problems/minimum-increment-to-make-array-unique/description

//Approach-1 (Using sorting)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int moves = 0;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] <= nums[i-1]) {
                moves += (nums[i-1] - nums[i] + 1);
                nums[i] = nums[i-1]+1;
            }
        }

        return moves;
    }
};



//Approach-2 (Using Counting Sort)
//T.C : O(n+maxVal)
//S.C : O(n+maxVal)
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int maxElement = 0;
        int moves = 0;

        for (int val : nums) {
            maxElement = max(maxElement, val);
        }

        vector<int> count(n + maxElement, 0);

        for (int val : nums) {
            count[val]++;
        }

        for (int i = 0; i < count.size(); i++) {
            if (count[i] <= 1) continue;

            int extra = count[i] - 1;
            count[i + 1] += extra;
            count[i] = 1;
            moves += extra;
        }

        return moves;
    }
};
