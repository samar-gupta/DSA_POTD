//Leetcode Link : https://leetcode.com/problems/set-intersection-size-at-least-two/description/

/*
  Intuition :
      Every interval needs at least two numbers from our chosen set.
      To make the set as small as possible, we should choose the numbers that:
      Are placed towards the end of intervals (so future intervals can also use them)
      Are maximum and common to many intervals
      So the best greedy idea is:
      👉 Sort intervals by their ending point (smallest end first)
      This way, when we pick numbers for the current interval, those numbers can also help in later intervals.
      Then for each interval:
      If it already has two numbers, do nothing.
      If it has one, add one more (choose the largest possible number).
      If it has zero, add two numbers:
      → end − 1 and end
     because these two have the highest chance to appear in future intervals.
     This guarantees the minimum possible new numbers added.

  Approach :
      Sort intervals by: end point (ascending)
        if same end, sort start (descending)
      
      Keep track of the last two selected numbers (a and b).
     
      For each interval:
        Check if a and b fall inside the interval.
        Based on how many are inside:
          0 inside: add end-1 and end
          1 inside: add end
          2 inside: nothing needed
        Count how many numbers we added → that’s the answer.

  This greedy always works because we pick the rightmost numbers which help cover maximum future intervals.
*/
//Approach-1 : 
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    static bool cmp(const vector<int>& x, const vector<int>& y) {
        if(x[1] == y[1]) return y[0] < x[0];
        return x[1] < y[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0, a = -1, b = -1;
        for(int i = 0; i < intervals.size();i++) {
            int l = intervals[i][0], r = intervals[i][1];
            if(l > b) {
                a = r - 1;
                b = r;
                ans += 2;
            } else if(l > a) {
                a = b;
                b = r;
                ans += 1;
            }
        }
        return ans;
    }
};


//Approach-1 : 
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    // Sort by end ascending; if tie, start descending
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if (a[1] != b[1]) return a[1] < b[1];
        return a[0] > b[0];
    }

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        
        // Sort intervals using greedy order
        sort(intervals.begin(), intervals.end(), comp);

        // s1 = second largest picked number
        // s2 = largest picked number
        int s1 = -1, s2 = -1;
        int ans = 0;

        // Process each interval
        for (auto &v : intervals)
        {
            int l = v[0];
            int r = v[1];

            // Case 1: interval already contains both points
            if (l <= s1 && s2 <= r)
                continue;

            // Case 2: contains only s2 → need 1 more point
            if (l <= s2) 
            {
                ans += 1;
                s1 = s2;   // shift largest to second largest
                s2 = r;    // add new point at r
            } 

            // Case 3: contains none → need 2 points
            else 
            {
                ans += 2;
                s1 = r - 1; // pick (r-1)
                s2 = r;     // pick r
            }
        }

        return ans;
    }
};

