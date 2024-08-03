//Leetcode Link : https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays

//Approach - 1 (Sorting)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] != target[i])
                return false;
        }
        return true;
    }
};



//Approach-2 (Using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int num : arr) {
            mp[num]++;
        }

        for (int &num : target) {
            if (mp.find(num) == mp.end())
                return false;

            mp[num]--;
            if (mp[num] == 0) {
                mp.erase(num);
            }
        }
        return mp.size() == 0;
    }
};
