//Leetcode Link : https://leetcode.com/problems/count-days-without-meetings

//Approach (Simple sorting based on starting point)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();

        sort(begin(meetings), end(meetings));

        int result = 0;
        int start = 0;
        int end = 0;

        for(auto &meet : meetings) {
            if(meet[0] > end) {
                result += meet[0] - end - 1;
            }

            end = max(end, meet[1]);
        }

        if(days > end) {
            result += days-end;
        }

        return result;
    }
};
