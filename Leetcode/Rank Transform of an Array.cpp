//Leetcode Link : https://leetcode.com/problems/rank-transform-of-an-array/

//T.C: O(n*logn)
//S.C: O(n)
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> mp; //number -> rank
        set<int> st(begin(arr), end(arr)); //ordered set keeps them in sorted order
        
        int rank = 1;
        for(auto &num : st) {
            mp[num] = rank;
            rank++;
        }
        
        for(int i = 0; i < arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }
        
        return arr;
    }
};
