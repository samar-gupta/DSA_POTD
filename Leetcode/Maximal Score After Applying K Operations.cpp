//Leetcode Link : https://leetcode.com/problems/maximal-score-after-applying-k-operations

//Approach (standard heap approach)
//T.C : O(n + klogn)
//S.C : O(k)
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum = 0;

        priority_queue<int> pq(begin(nums), end(nums)); //First time creation of heap "heapify" is O(n)
        //Refer - https://stackoverflow.com/questions/9755721/how-can-building-a-heap-be-on-time-complexity
        //Or you can refer NPTEL video on Heap on youtube. 

        while(k--) {
            int maxEl = pq.top();
            pq.pop();

            sum += maxEl;
            maxEl = ceil(maxEl/3.0);
            pq.push(maxEl);
        }

        return sum;
    }
};

