//Company Tags  : GOOGLE
//Leetcode Link : https://leetcode.com/problems/maximum-running-time-of-n-computers/

//Approach-1 (Using Linesr search from minute = max_limit till minute = 1 -- TLE
//T.C : O(m*k)
//S.C : O(1)
class Solution {
public:
    typedef long long ll;

    bool possible(vector<int>& batteries, ll time, int n) {
        ll target = n * time;

        for (int b : batteries) {
            target -= min((ll)b, time);
            if (target <= 0) return true;
        }
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {

        long long sum = 0;
        for (int b : batteries) sum += b;

        // Max possible minutes if evenly distributed
        long long maxMinutes = sum / n;

        // Linear search: from max → 1
        for (long long t = maxMinutes; t >= 1; t--) {
            if (possible(batteries, t, n)) return t;
        }
        return 0;
    }
};


//Approach-2 (Using Binary Search on the result minutes) . T.C. : O(m⋅logk) - m = input array length and k = range of minutes
//T.C : O(m*log(k))
//S.C : O(1)
class Solution {
public:
    typedef long long ll;
    
    bool possible(vector<int>& batteries, ll mid_time, int n) {
        
        ll target = n*mid_time; //each computer will run mid_time minutes
        
        ll sum = 0;
        
        for(int i = 0; i<batteries.size(); i++) {
            
            target -= min((ll)batteries[i], mid_time);
            
            if(target <= 0)
                return true;
            
        }
        return target <= 0;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        
        ll l = *min_element(begin(batteries), end(batteries));
        
        long long sum_total_minutes = 0;
        
        for(auto &mints : batteries){
            sum_total_minutes += mints;
        }
        
        ll r = sum_total_minutes/n;
        
        ll result = 0;
        
        while(l <= r) {
            
            ll mid_time = l + (r-l)/2;
            
            if(possible(batteries, mid_time, n)) {
                result = mid_time;
                l = mid_time+1;
            } else {
                r = mid_time-1;
            }
        }
        
        return result;
    }
};
