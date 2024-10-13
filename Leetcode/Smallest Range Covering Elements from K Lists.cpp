//Leetcode Link : https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists

//Approach-1 (Using vector of indexes)
//T.C : O(n*k)
//S.C : O(k)
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        vector<int> vec(k, 0); //{0, 0, 0....}

        vector<int> resultRange = {-1000000, 1000000}; //(a, b)

        while(true) {
            int minEl        = INT_MAX;
            int maxEl        = INT_MIN;
            int minElListIdx = 0;

            for(int i = 0; i < k; i++) {
                int listIdx = i;
                int elIdx = vec[i];
                int element = nums[listIdx][elIdx];

                if(element < minEl) {
                    minEl = element;
                    minElListIdx = listIdx;
                }

                maxEl = max(maxEl, element);
            }

            //range (minEl, maxEl)
            if(maxEl - minEl < resultRange[1] - resultRange[0]) {
                resultRange[0] = minEl;
                resultRange[1] = maxEl;
            }

            //now shorten this range by moving minElement idx
            int nextIndex = vec[minElListIdx]+1;
            if(nextIndex >= nums[minElListIdx].size()) {
                break;
            }
            vec[minElListIdx] = nextIndex;
        }

        return resultRange;
    }
};



//Approach-2 (Using heap)
//T.C : O(n*log(k))
//S.C : O(k)
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        //{element, listIdx, idx} //vector<int>{a, b, c}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int maxEl = INT_MIN;
        for(int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            maxEl = max(maxEl, nums[i][0]);
        }

        vector<int> resultRange = {-1000000, 1000000};

        while(!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            int minEl = curr[0];
            int listIdx = curr[1];
            int idx     = curr[2];

            if(maxEl - minEl < resultRange[1] -  resultRange[0]) {
                resultRange[0] = minEl;
                resultRange[1] = maxEl;
            }

            //decrease the range for minimum idx
            if(idx+1 < nums[listIdx].size()) {
                int nextElement = nums[listIdx][idx+1];
                pq.push({nextElement, listIdx, idx+1});
                maxEl = max(maxEl, nextElement);
            } else {
                break;
            }
        }

        return resultRange;
    }
};
