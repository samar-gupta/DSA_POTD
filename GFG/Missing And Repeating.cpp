class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int repeated = 0, missing = 0;
        
        unordered_map<int, int> freq;
        
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2) {
                repeated = i; 
            }
            if (freq[i] == 0) {
                missing = i;  
            }
        }
        
        return {repeated, missing};
    }
};
