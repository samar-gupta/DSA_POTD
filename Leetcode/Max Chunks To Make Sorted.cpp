//Leetcode Link : https://leetcode.com/problems/max-chunks-to-make-sorted/

//Approach-1 : 
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxval = 0;
        int count = 0;
        
        for(int i=0; i<arr.size(); i++) {
            maxval = max(maxval, arr[i]);
            if(maxval == i) {
                count++;
            }
        }
        
        return count;
    }
};
