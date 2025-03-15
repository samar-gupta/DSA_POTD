//Leetcode Link : https://leetcode.com/problems/house-robber-iv

//Approach-1 (Brute Force - Recursion + Memoization)
//T.C : O(n*k)
//S.C : O(n*k)
class Solution {
public:
    int n;
    int solve(vector<int>& nums, int i, int k, vector<vector<int>>& t) {
        if(k == 0) {
            return 0; //no more house to be covered
        }

        if(i >= n) { //invalid path
            return INT_MAX;
        }   

        if(t[i][k] != -1) {
            return t[i][k];
        }

        int take = max(nums[i], solve(nums, i+2, k-1, t));

        int not_take = solve(nums, i+1, k, t);


        return t[i][k] = min(take, not_take);
    }
    int minCapability(vector<int>& nums, int k) {
        n = nums.size();
        vector<vector<int>> t(n+1, vector<int>(k+1, -1));
        return solve(nums, 0, k, t);
    }
};


//Approach-2 (Binary Search on Answer "Minimize the Maximum Robbed Amount(capability)")
//T.C : O(n*log(maxC))
//S.C : O(1)
class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int k) {
        int house = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= mid) {
                house++;
                i++; //skipping adjacent house
            }
        }

        return house >= k; //we managed to rob atleast k houses
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();

        int l = *min_element(begin(nums), end(nums));
        int r = *max_element(begin(nums), end(nums));

        int result = r;

        while(l <= r) { //O(log(maxC) * n )
            int mid = l + (r-l)/2; //capability

            if(isPossible(nums, mid, k) == true) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
};
