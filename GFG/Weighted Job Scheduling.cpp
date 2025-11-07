//Approach-1 : 
class Solution {
  public:
    int binarySearch(int idx, int target, vector<vector<int>>& jobs) {
        int n = jobs.size();
        int res = n;
        int s = idx, e = n - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (jobs[mid][0] >= target) { // next job start >= target
                res = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return res;
    }

    int solve(int i, vector<vector<int>>& jobs, vector<int>& dp) {
        if (i >= jobs.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int nextIdx = binarySearch(i + 1, jobs[i][1], jobs);

        int take = jobs[i][2] + solve(nextIdx, jobs, dp);
        int notTake = solve(i + 1, jobs, dp);

        return dp[i] = max(take, notTake);
    }
    
    int maxProfit(vector<vector<int>> &jobs) {
        // code here
        sort(jobs.begin(), jobs.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        vector<int> dp(jobs.size(), -1);
        return solve(0, jobs, dp);
    }
};


//Approach-2 : 
class Solution {
  public:
    static bool comp(vector<int> &a,vector<int> &b) {
        return a[1] < b[1];
    }
    
    int maxProfit(vector<vector<int>> &jobs) {
        // code here
        int n=jobs.size();
        
        // Sort jobs by end time
        sort(jobs.begin(), jobs.end(),comp);
        
        vector<int> endTimes(n);
        for(int i=0;i<n;i++) {
            endTimes[i]=jobs[i][1];
        }
        
        vector<long long> dp(n);
        dp[0]=jobs[0][2]; // profit of first job
        
        for(int i=1;i<n;i++) {
            long long profitInclude=jobs[i][2];
            
            // find the last job that ends <= start of current job
            int idx=upper_bound(endTimes.begin(), endTimes.end(),jobs[i][0]) - endTimes.begin()-1;
            
            if(idx>=0){
                profitInclude+=dp[idx];
            }
            
            long long profitExclude=dp[i-1];
            
            dp[i]=max(profitInclude,profitExclude);
        }
        
        return dp[n-1];
    }
};
