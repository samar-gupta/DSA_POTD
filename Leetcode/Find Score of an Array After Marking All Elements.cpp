//Leetcode Link : https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements

//Approach-1 (Sorting array with indices)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec(n);

        for(int i = 0; i < n; i++) {
            vec[i] = {nums[i], i};
        }

        sort(begin(vec), end(vec)); //O(nlogn)

        long long score = 0;
        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++) { //O(n)
            int element = vec[i].first;
            int idx     = vec[i].second;
            if(visited[idx] == false) {
                visited[idx] = true;
                score += element;

                if(idx-1 >= 0 && visited[idx-1] == false) {
                    visited[idx-1] = true;
                }
                if(idx+1 < n && visited[idx+1] == false) {
                    visited[idx+1] = true;
                }
            }
        }

        return score;
    }
};



//Approach-2 (Using min-heap)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    #define P pair<int, int>
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);

        priority_queue<P, vector<P>, greater<P>> pq;
        for(int i = 0; i < n; i++) {//n
            pq.push({nums[i], i}); //log(n)
        }

        long long score = 0;
        while(!pq.empty()) { //n
            P temp = pq.top();
            int element = temp.first;
            int idx = temp.second;
            pq.pop(); //log(n)

            if(!visited[idx]) {
                visited[idx] = true;
                score += element;

                if(idx-1 >= 0 && !visited[idx-1]) {
                    visited[idx-1] = true;
                }
                if(idx+1 < n && !visited[idx+1]) {
                    visited[idx+1] = true;
                }
            }
        }

        return score;
    }
};
