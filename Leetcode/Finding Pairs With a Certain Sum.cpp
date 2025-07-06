//Leetcode Link : https://leetcode.com/problems/finding-pairs-with-a-certain-sum

//Approach (Using map and approach similar to Two Sum Problem)
//T.C : O(m+n) for FindSumPairs(), O(1) for add() and O(n) for count()
//S.C : O(m+n) for vec1 and vec2
class FindSumPairs {
public:
    vector<int> vec1, vec2;
    unordered_map<int, int> mp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1;
        vec2 = nums2;
        for(int &x : vec2) {
            mp[x]++;
        }
    }
    
    void add(int index, int val) {
        mp[vec2[index]]--;
        vec2[index] += val;
        mp[vec2[index]]++;
    }
    
    int count(int tot) {
        int c = 0;
        for(int &x : vec1) {
            c += mp[tot-x];
        }

        return c;
    }
};
