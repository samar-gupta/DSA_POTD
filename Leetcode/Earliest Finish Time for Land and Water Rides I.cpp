//Leetcode Link : https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/description/

//Approach-1 :
/*
  The tourist must complete one land ride and one water ride.
  
  Since the second ride only depends on arrival time, 
    we always want the first ride in either category to finish as early as possible, 
    then compare both possible orders.
    
      There are only 2 possible orders to find the earliest finish time:
        Land→Water rides
        Water→Land rides
        
      After evaluating both orders, we take the minimum.
*/
//T.C : O(n+m)
class Solution {
public:
    int earliestFinishTime(vector<int>& startL, vector<int>& durL, vector<int>& startW, vector<int>& durW) {
        int minL = 3000, minW = minL, res = minW;
        int n = startL.size(), m = startW.size();

        for (int i = 0; i < n; i++)
            minL = min(minL, startL[i] + durL[i]);

        for (int i = 0; i < m; i++) {
            minW = min(minW, startW[i] + durW[i]);
            res = min(res, max(minL, startW[i]) + durW[i]);
        }

        for (int i = 0; i < n; i++)
            res = min(res, max(minW, startL[i]) + durL[i]);

        return res;
    }
};
