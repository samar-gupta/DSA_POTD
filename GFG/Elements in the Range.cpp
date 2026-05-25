class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        vector<bool> check(end+1);
    
        // Marking from array
        for(int &val: arr) {
            if(val >= start && val <= end) {
                check[val] = true;
            }
        }
    
        // Checking range
        for(int i = start; i <= end; i++) {
            if(!check[i]) {
                return false;
            }
        }
    
        return true;
    }
};
