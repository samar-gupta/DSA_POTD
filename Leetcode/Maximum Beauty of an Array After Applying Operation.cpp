//Leetcode Link : https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation

//Approach-1 (By converting to intervals and finding the max intervals we can get)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<pair<int, int>> ranges;
        for (int num : nums) {
            ranges.push_back({num - k, num + k});
        }

        sort(ranges.begin(), ranges.end());

        int maxBeauty = 0;
        deque<int> deq; //You can use queue as well - See my video above

        //NOTE : The intervals have equal size and hence this approach works like a charm.
        //If the intervals didn't have equal size, then it will fail in some cases.
        for (const auto& range : ranges) {
            while (!deq.empty() && deq.front() < range.first) {
                deq.pop_front();
            }

            deq.push_back(range.second);

            maxBeauty = max(maxBeauty, (int)deq.size());
        }

        return maxBeauty;
    }
};


//Approach-2 (Sorting and Using Binary Search)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int maxBeauty = 0;
        //Proof in the video for nums[i] + 2*k
        for (int i = 0; i < nums.size(); i++) {
            auto upperBound = upper_bound(nums.begin(), nums.end(), nums[i] + 2 * k); //You can write your own binarySearch - See my video above

            maxBeauty = max(maxBeauty, int(upperBound - nums.begin()) - i);
        }

        return maxBeauty;
    }
};


//Approach-3 (Using Sliding Window)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int j = 0;
        int maxBeauty = 0;

        while (i < n) {

            while (j < n && nums[j] - nums[i] <= 2 * k) {
                j++;
            }

            maxBeauty = max(maxBeauty, j - i);

            i++;
        }

        return maxBeauty;
    }
};
