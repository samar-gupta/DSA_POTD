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



//Approach - Sort and use map
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        vector<int> temp(arr);
        sort(begin(temp), end(temp));

        int rank = 1;
        unordered_map<int, int> rankMap;
        vector<int> result(n);

        for(int i = 0; i < n; i++) {
            if(i > 0 && temp[i] > temp[i-1]) {
                rank++;
            }
            rankMap[temp[i]] = rank;
        }

        for(int i = 0; i < n; i++) {
            result[i] = rankMap[arr[i]];
        }

        return result;
    }
};
