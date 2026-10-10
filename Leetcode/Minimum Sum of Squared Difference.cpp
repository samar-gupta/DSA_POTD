//Leetcode Link : https://leetcode.com/problems/minimum-sum-of-squared-difference/

//Approach-1 (Brute Force - TLE)
//T.C : O((n + k1 + k2) * log n), k is huge
//S.C : O(n)
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        priority_queue<int> pq;
        for (int i = 0; i < n; ++i) {
            pq.push(abs(nums1[i] - nums2[i]));
        }

        int K = k1 + k2;

        while (K > 0 && pq.top() > 0) {
            int largestDiff = pq.top();
            pq.pop();
            pq.push(largestDiff - 1);
            K--;
        }

        long long result = 0;
        while (!pq.empty()) {
            long long d = pq.top();
            pq.pop();
            result += d * d;
        }

        return result;
    }
};


//Approach-2 (Using Counting Sort)
//T.C : O(n + maxDiff), maxDiff <= 10^5
//S.C : O(n)
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }

        int maxDiff = *max_element(diff.begin(), diff.end());

        // countDiff[d] = conut of each diff
        vector<int> countDiff(maxDiff + 1, 0);
        for (int d : diff) {
            countDiff[d]++;
        }

        int K = k1 + k2;

        for (int currDiff = maxDiff; currDiff > 0 && K > 0; currDiff--) {
            int countOps             = min(countDiff[currDiff], K);

            countDiff[currDiff]     -= countOps;
            countDiff[currDiff - 1] += countOps;
            K                       -= countOps;
        }

        
        long long result = 0;
        for (long long d = 1; d <= maxDiff; ++d) {
            result += countDiff[d] * d * d;
        }

        return result;
    }
};
