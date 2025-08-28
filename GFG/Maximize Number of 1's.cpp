//Approach-1 :
//T.C : O(2N)
//S.C : O(1)
class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int l = 0, maxLen = 0;
        for (int r = 0; r < arr.size(); r++) {
            if (arr[r] == 0) k--;
            while (k < 0) {
                if (arr[l] == 0) k++;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        
        return maxLen;
    }
};
