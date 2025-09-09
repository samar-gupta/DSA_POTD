//Leetcode Link : https://leetcode.com/problems/number-of-people-aware-of-a-secret

//Approach-1 - Recursion + Memoization
//T.C : O(n*(forget-delay))
//S.C : O(n)
class Solution {
public:
    int MOD = 1e9 + 7;
    int n, delay, forget;
    vector<int> t;

    //This returns number of people who first learn the secret on "day"
    int solve(int day) {
        if (day == 1) 
            return 1;
        if (day <= 0) 
            return 0;
            
        if (t[day] != -1)
            return t[day];

        long long result = 0;
        // people who can share today are those who learned it in
        // [day - forget + 1, day - delay]
        for (int prev = day - forget + 1; prev <= day - delay; prev++) {
            if (prev > 0) {
                result = (result + solve(prev)) % MOD;
            }
        }
        return t[day] = (int) result;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        this->n      = n;
        this->delay  = delay;
        this->forget = forget;
        t.assign(n + 1, -1);

        int total = 0;
        // only count people who haven't forgotten by day n
        for (int day = n - forget + 1; day <= n; day++) {
            if (day > 0) {
                total = (total + solve(day)) % MOD;
            }
        }
        return total;
    }
};


//Approach-2 - Bottom Up
//T.C : O(n*(forget-delay))
//S.C : O(n)
class Solution {
public:
    int M = 1e9+7;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> t(n+1);
        // t[day] = number of people who learn the secret on "day"

        t[1] = 1;

        for(int day = 2; day <= n; day++) {
            long long count = 0;
            for(int prev = day - forget+1; prev <= day - delay; prev++) {
                if(prev > 0) {
                    count = (count + t[prev]) % M;
                }
            }
            t[day] = count;
        }

        int result = 0;
        for(int day = n-forget+1; day <= n; day++) {
            if(day > 0) {
                result = (result + t[day]) % M;
            }
        }

        return result;
        
    }
};


//Approach-3 - Bottom Up Optimised using sliding window
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int MOD = 1e9 + 7;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> t(n + 1, 0);
        // t[day] = number of people who learn the secret on "day"

        t[1] = 1;
        
        int count = 0; 

        for (int day = 2; day <= n; day++) {
            // people who become eligible to share on this day
            if (day - delay > 0) {
                count = (count + t[day - delay]) % MOD;
            }
            // people who forget on this day
            if (day - forget > 0) {
                count = (count - t[day - forget] + MOD) % MOD;
            }
            t[day] = count; //total number of people who will get to know today
        }


        // Count the people who still remember on day n
        int result = 0;
        for (int day = n - forget + 1; day <= n; day++) {
            if (day > 0) {
                result = (result + t[day]) % MOD;
            }
        }

        return result;
    }
};
