//Company Tags  : GOOGLE
//Leetcode Link : https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i

//Approach - Using Cumulative Sum of Frequencies and trying all possible targets in nums
//T.C : O(maxVal), maxVal = maximum element in nums + k
//S.C : O(maxVal), maxVal = maximum element in nums + k
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxEl = *max_element(begin(nums), end(nums)) + k;

        vector<int> freq(maxEl + 1, 0);

        for(int &num : nums) {
            freq[num]++;
        }

        //cumulative sum of frequenceis
        for(int i = 1; i <= maxEl; i++) {
            freq[i] += freq[i-1];
        }

        int result = 0;
        for(int target = 0; target <= maxEl; target++) {
            if(freq[target] == 0)
                continue;
            
            int leftNum  = max(0, target-k); //l
            int rightNum = min(maxEl, target+k); //r

            int totalCount  = freq[rightNum] - (leftNum > 0 ? freq[leftNum-1] : 0);

            int targetCount = freq[target] - (target > 0 ? freq[target-1] : 0);

            int needConversion = totalCount - targetCount;

            int maxPossibleFreq = targetCount + min(needConversion, numOperations);

            result = max(result, maxPossibleFreq);
        }

        return result;
    }
};


//Approach - Using Difference Array Technique
//T.C : O(maxVal), maxVal = maximum element in nums + k
//S.C : O(maxVal), maxVal = maximum element in nums + k
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(begin(nums), end(nums)) + k;

        vector<int> diff(maxVal+2, 0);
        unordered_map<int, int> freq;

        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            int l = max(nums[i]-k, 0);
            int r = min(nums[i]+k, maxVal);

            diff[l]++;
            diff[r+1]--;
        }


        int result = 1;

        for(int target = 0; target <= maxVal; target++) {
            diff[target] += (target > 0 ? diff[target-1] : 0);

            int targetFreq     = freq[target];
            int needConversion = diff[target] - targetFreq;

            int maxPossibleFreq = min(needConversion, numOperations);

            result = max(result, targetFreq + maxPossibleFreq);
        }

        return result;
    }
};
