/*
    Company Tags                : Meta, Google, Amazon
    Leetcode Link               : https://leetcode.com/problems/eliminate-maximum-number-of-monsters/
*/

/********************************************************** C++ **********************************************************/
//Using simple Greedy
//T.C : O(nlogn)
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();

        vector<int> time(n);

        for(int i = 0; i<n; i++) {
            time[i] = ceil((float) dist[i] / speed[i]);
        }

        sort(begin(time), end(time));

        int count = 1;
        int time_passed = 1;

        for(int i = 1; i<n; i++) {
            
            if(time[i] - time_passed <=0) {
                return count;
            }

            count++;
            time_passed++;
        }

        return count;
    }
};
