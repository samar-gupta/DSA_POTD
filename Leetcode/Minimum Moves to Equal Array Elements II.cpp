//Leetcode Link : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

//Approach-1 (Greedily Pick mid element)
//T.C : O(nlogn) for sorting
//S.C : O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int mid = nums[n/2];

        int moves = 0;
        for(int i = 0; i < n; i++) {
            moves += abs(nums[i] - mid);
        }

        return moves;
    }
};


//Approach-2 (Iterate till n/2)
//T.C : O(nlogn) for sorting
//S.C : O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int mid = nums[n/2];

        int moves = 0;
        for(int i = 0; i < n/2; i++) {
            moves += abs(nums[i] - mid);
            moves += abs(nums[n-i-1] - mid);
        }

        return moves;
    }
};


//Approach-3 (Use nth_element for Average Sort)
//T.C : Average O(n) for nth_element
//S.C : O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        nth_element(begin(nums), begin(nums)+n/2, end(nums)); //O(n) average

        int mid = nums[n/2];

        int moves = 0;
        for(int i = 0; i < n/2; i++) {
            moves += abs(nums[i] - mid);
            moves += abs(nums[n-i-1] - mid);
        }

        return moves;
    }
};
