class Solution {
  public:
    static bool comp(int a, int b){
        //ye ek inbuilt function hai jo set bit nikal kar deta hai c++ me
        return __builtin_popcount(a) > __builtin_popcount(b);
    }
    
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        stable_sort(arr,arr+n,comp);
    }
};
