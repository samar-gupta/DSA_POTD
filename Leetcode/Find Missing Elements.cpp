//Leetcode Link : https://leetcode.com/problems/find-missing-elements/description/

//Approach-1
//T.C : O(nlogn + T), T = total number of elements between maxEl and minEl
//S.C : O(1)
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int curr = nums[0];
        vector<int> result;

        for(int i = 0; i < nums.size();) {
            if(curr < nums[i]) { //missing curr
                result.push_back(curr);
            } else {
                i++;
            }
            curr++;
        }

        return result;
    }
};


//Approach-2
//T.C : O(n + T), T = total number of elements between maxEl and minEl
//S.C : O(1)
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        //constraints : 1 <= nums[i] <= 100
        vector<bool> present(101, false);
        //or you can use unordered_set<int>

        int maxEl = nums[0];
        int minEl = nums[0];

        for(int i = 0; i < nums.size(); i++) {
            maxEl = max(maxEl, nums[i]);
            minEl = min(minEl, nums[i]);
            present[nums[i]] = true;
        }

        vector<int> result;

        for(int curr = minEl; curr <= maxEl; curr++) {
            if(!present[curr]) {
                result.push_back(curr);
            }
        }

        return result;
    }
};
