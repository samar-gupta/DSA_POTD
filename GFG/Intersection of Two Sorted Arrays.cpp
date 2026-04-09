//Approach-1 :
/*
1. Start two pointers:
    i = 0 for array a
    j = 0 for array b
2. Compare a[i] and b[j]
    If a[i] < b[j], move i
    If a[i] > b[j], move j
    If both are equal:
      Add that element to answer
      Skip all duplicate occurrences of that element in both arrays
3. Continue until one array ends.

This works because both arrays are sorted.
*/
class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> ans;
        
        int i = 0, j = 0;
        int n = a.size(), m = b.size();
        
        while (i < n && j < m) {
            
            if (a[i] < b[j]) {
                i++;
            }
            
            else if (a[i] > b[j]) {
                j++;
            }
            
            else {
                ans.push_back(a[i]);
                
                int current = a[i];
                
                while (i < n && a[i] == current) {
                    i++;
                }
                
                while (j < m && b[j] == current) {
                    j++;
                }
            }
        }
        
        return ans;
    }
};
