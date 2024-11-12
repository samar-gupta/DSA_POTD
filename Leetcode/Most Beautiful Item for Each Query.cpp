//Leetcode Link : https://leetcode.com/problems/most-beautiful-item-for-each-query

//Approach (simple binary search and preprocessing)
//T.C : O(nlogn + n + mlogn)
//S.C : O(1)
class Solution {
public:

    int customBinarySearch(vector<vector<int>>& items, int queryPrice) {
        int l = 0;
        int r = items.size()-1;

        int mid;
        int maxBeauty = 0;

        while(l <= r) {
            mid = l + (r-l)/2;

            if(items[mid][0] > queryPrice) {
                r = mid-1; //ignore current and right side items. Move to left now.
            } else {
                maxBeauty = max(maxBeauty, items[mid][1]);
                l = mid+1;
            }
        }

        return maxBeauty;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();

        vector<int> result(m);

        //step-1 : Sort the array based on price in asencind order
        sort(begin(items), end(items)); //{pricei, beautyi}

        int maxBeautySeen = items[0][1];
        for(int i = 1; i < n; i++) {
            maxBeautySeen = max(maxBeautySeen, items[i][1]);
            items[i][1] = maxBeautySeen;
        }


        for(int i = 0; i < m; i++) {
            int queryPrice = queries[i];
            result[i] = customBinarySearch(items, queryPrice);
        }

        return result;

    }
};
