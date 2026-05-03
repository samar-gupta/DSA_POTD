class Solution {
public:
    static bool comp(int a, int b) {
        return __builtin_popcount(a) > __builtin_popcount(b);
    }

    vector<int> sortBySetBitCount(vector<int> arr) {
        stable_sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};
