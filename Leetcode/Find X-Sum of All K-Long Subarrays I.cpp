//Leetcode Link : https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i

//Approach (Using max-heap + sliding window)
//T.C : O(n * k * log(k))
//S.C : O(k)
class Solution {
public:
    typedef pair<int, int> P; //freq, element
    int findTopXSum(unordered_map<int, int>& mp, int x) {
        //min-heap
        priority_queue<P, vector<P>, greater<P>> pq; //O(k) space

        for(auto &it : mp) { //O(k * log(k))
            pq.push({it.second, it.first});

            if(pq.size() > x) {
                pq.pop(); //remove smallest element from the top
            }
        }

        int sum = 0;
        while(!pq.empty()) { //K
            auto [freq, val] = pq.top(); //
            pq.pop(); //log(k)

            sum += freq*val;
        }

        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        unordered_map<int, int> mp; //O(k)

        vector<int> result;

        int i = 0;
        int j = 0;
        //T.C : O(n * klogk)
        while(j < n) { //khandani sliding window template
            mp[nums[j]]++;

            if(j - i + 1 == k) {
                result.push_back(findTopXSum(mp, x));

                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            j++;
        }

        return result;
    }
};
