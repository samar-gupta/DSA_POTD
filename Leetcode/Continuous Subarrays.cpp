//Leetcode Link : https://leetcode.com/problems/continuous-subarrays

//Approach-1 (Using Ordered Map)
//T.C : ~O(n) - Explained in the video why O(n) ?
//S.C : ~O(1) - Explained in the video why O(1) ?
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        map<int, int> mp;

        int i = 0;
        int j = 0;

        long long count = 0;

        while(j < n) {
            mp[nums[j]]++;
            
            while(abs(mp.rbegin()->first - mp.begin()->first) > 2) { //it means it is out of the bound
                //shrink window -move i index
                mp[nums[i]] -= 1;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            count += j-i+1;
            j++;
        }

        return count;
    }
};



//Approach-2 (Using heap)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    #define P pair<int, int>

    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        priority_queue<P, vector<P>, greater<P>> minHeap;
        priority_queue<P> maxHeap;


        int i = 0;
        int j = 0;
        long long count = 0;

        while(j < n) { //O(n)
            minHeap.push({nums[j], j}); //Log(n)
            maxHeap.push({nums[j], j}); //Log(n)

            while(abs(maxHeap.top().first - minHeap.top().first) > 2) {
                i++;

                while(!maxHeap.empty() && maxHeap.top().second < i) {
                    maxHeap.pop();
                }

                while(!minHeap.empty() && minHeap.top().second < i) {
                    minHeap.pop();
                }
            }

            count += j-i+1;
            j++;
        }
        //T.C: O(nlogn)
        return count;
    }
};
