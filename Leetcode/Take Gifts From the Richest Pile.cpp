//Leetcode Link : https://leetcode.com/problems/take-gifts-from-the-richest-pile

//Approach (Using max-heap)
//T.C : O(n + k*logn)
//S.C : O(n)
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        //Heapify - O(n)
        priority_queue<int> pq(begin(gifts), end(gifts)); //max-heap

        long long sum = 0;
        for(int &gift : gifts) { //O(n)
            sum += gift;
        }

        while(k--) { //O(k)
            int maxEl = pq.top(); //O(1)
            pq.pop(); //O(log(n))

            int remaining = sqrt(maxEl); //Ignoring this time complexity
            sum -= (maxEl - remaining);
            pq.push(remaining);//O(log(n))
        }

        return sum;

    }
};
