//Company Tags  : JIO (for a Flutter developer role)
//Leetcode Link : https://leetcode.com/problems/minimum-absolute-difference

//Approach (Sort and find and collect)
//T.C : O(nlogn) 
//S.C : O(1)
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(begin(arr), end(arr));
        vector<vector<int>> result;
        int n = arr.size();
        
        int minDiff = INT_MAX;
        for(int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i-1];
            minDiff = min(diff, minDiff);
        }
        
        for(int i = 1; i<n; i++) {
            int diff = arr[i]-arr[i-1];
            
            if(diff == minDiff) {
                result.push_back({arr[i-1], arr[i]});
            }
        }
        
        
        return result;
        
    }
};
