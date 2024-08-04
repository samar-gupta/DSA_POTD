//Leetcode Link : https://leetcode.com/problems/range-sum-of-sorted-subarray-sums

//Approach-1 (Brute Force)
//T.C : O(n^2 * logn) - we have total n^2 elements in temp
//S.C : O(n)
class Solution {
public:
    int M = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                temp.push_back(sum);
            }
        }
        
        sort(begin(temp), end(temp));

        // Find the sum of all values between left and right.
        int result = 0;
        for (int i = left - 1; i <= right - 1; i++) {
            result = (result + temp[i]) % M;
        }
        return result;
    }
};



//Approach-2 (How to find sorted subarray sums using Heap)
//T.C : O(n^2 *n logn)
//S.C : O(n)
class Solution {
public:
    typedef pair<int, int> P;
    int M = 1e9+7;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<P, vector<P>, greater<P>> pq;
        
        //pair<sum, i> -> (subarray sum, till index i)
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        int result = 0;

        for (int i = 1; i <= right; i++) {
            auto p = pq.top();
            pq.pop();

            // If the current index is greater than or equal to left, add the
            // value to the answer.
            if (i >= left) {
                result = (result + p.first) % M;
            }

            // If index is less than the last index, increment it and add its
            // value
            if (p.second < n - 1) {
                p.second++;
                p.first += nums[p.second];
                pq.push(p);
            }
        }
        return result;
    }
};
