//Leetcode Link : https://leetcode.com/problems/maximum-total-damage-with-spell-casting

//Approach-1 - Recursion + Memoization
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    typedef long long ll;
    int n;                                
    unordered_map<ll,ll> mp;      
    vector<ll> t;           

    long long solve(int i, const vector<ll>& nums) {
        if (i >= n) 
            return 0;

        if (t[i] != -1)
            return t[i];

        //skip current damage
        ll skip = solve(i + 1, nums);

        //take current damage
        int j = lower_bound(begin(nums) + i + 1, end(nums), nums[i] + 3) - begin(nums);
        ll take = nums[i] * mp[nums[i]] + solve(j, nums);

        return t[i] = max(skip, take);
    }

    long long maximumTotalDamage(vector<int>& power) {
        for (int x : power) 
            mp[x]++;

        vector<ll> nums(mp.size());

        for (auto &p : mp)
            nums.push_back(p.first);

        sort(begin(nums), end(nums));
        n = nums.size();
        t.assign(n, -1);

        return solve(0, nums);
    }
};


//Approach-2 - Bottom Up
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    typedef long long ll;
    long long maximumTotalDamage(vector<int>& power) {
        // Step 1: Count frequency of each unique power value
        unordered_map<ll, ll> mp;
        
        for (int &x : power)
            mp[x]++;

        // Step 2: \\Collect and sort unique values
        vector<ll> nums(mp.size());
        for (auto &p : mp)
            nums.push_back(p.first);

        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<ll> t(n, 0);
        //dp[i] = Maximum Total Damage if we start from index i
        
        long long result = INT_MIN;

        for (int i = n - 1; i >= 0; --i) {
            //skip current value
            ll skip = (i + 1 < n) ? t[i + 1] : 0;

            //take current value
            int j   = lower_bound(begin(nums) + i + 1, end(nums), nums[i] + 3) - begin(nums);
            ll take = nums[i] * mp[nums[i]] + ((j < n) ? t[j] : 0);

            t[i]   = max(skip, take);
            result = max(result, t[i]);
        }

        return result;
    }
};
