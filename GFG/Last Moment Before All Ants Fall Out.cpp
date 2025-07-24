//Approach : When two ants collide, they simply pass through each other (since they're indistinguishable), so you only need to compute the last time when any ant falls off the rod.
             // Optimized Solution Using Simulation Insight:
             // Collision handling is not required because the result is the same as if ants passed through each other.
//Time Complexity: O(L + R), where L = left.size() and R = right.size() — one pass through each array.
//Space Complexity: O(1) extra space — only a few integer variables are used.
class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int time = INT_MIN;
        
        // Compute max time for left-moving ants to fall off
        for (int i = 0; i < left.size(); i++) {
            time = max(time, left[i]); // Distance to 0
        }

        // Compute max time for right-moving ants to fall off
        for (int i = 0; i < right.size(); i++) {
            time = max(time, n - right[i]); // Distance to n
        }

        return time;
    }
};
