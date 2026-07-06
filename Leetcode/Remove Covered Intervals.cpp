//Leetcode Link : https://leetcode.com/problems/remove-covered-intervals/

//Approach-1 (Using O(n) space and sorting)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        int n = intervals.size();

        auto lambda = [](vector<int>& vec1, vector<int>& vec2) {
            if(vec1[0] == vec2[0]) {
                return vec1[1] > vec2[1];
            }

            return vec1[0] < vec2[0];
        };

        sort(begin(intervals), end(intervals), lambda);

        result.push_back(intervals[0]);

        for(int i = 1; i < n; i++) {
            if(result.back()[0] <= intervals[i][0] && result.back()[1] >= intervals[i][1]) {
                continue;
            }

            result.push_back(intervals[i]);
        }

        return result.size();
    }
};


//Approach-2 (Using O(n) space and sorting + Simplified condition check)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        int n = intervals.size();

        auto lambda = [](vector<int>& vec1, vector<int>& vec2) {
            if(vec1[0] == vec2[0]) {
                return vec1[1] > vec2[1];
            }

            return vec1[0] < vec2[0];
        };

        sort(begin(intervals), end(intervals), lambda);

        result.push_back(intervals[0]);

        for(int i = 1; i < n; i++) {
            if(result.back()[1] >= intervals[i][1]) { //simplified
                continue;
            }

            result.push_back(intervals[i]);
        }

        return result.size();
    }
};

//Approach-3 (Using constant space and sorting)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        auto lambda = [](vector<int>& vec1, vector<int>& vec2) {
            if(vec1[0] == vec2[0]) {
                return vec1[1] > vec2[1];
            }

            return vec1[0] < vec2[0];
        };

        sort(begin(intervals), end(intervals), lambda);

        //result.push_back(intervals[0]);
        int lastIntervalKaEnd = intervals[0][1];
        int count = 1;

        for(int i = 1; i < n; i++) {
            if(lastIntervalKaEnd >= intervals[i][1]) {
                continue;
            }

            lastIntervalKaEnd = intervals[i][1];
            count++;
        }

        return count;
    }
};
