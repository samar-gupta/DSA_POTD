//Approach:
/*
1. Start with answer = 0.
2. Keep a variable len to store the current strictly increasing segment length.
3. Initially, len = 1 because one element alone is always a segment of length 1.
4. Traverse the array from index 1 to n-1.
5. If arr[i] > arr[i-1], then the increasing segment continues:
     Increase len
     Add len - 1 to the answer
6. Otherwise:
     Reset len = 1
7. Return the final answer.

For example:
Array:
[1, 4, 5, 3, 7, 9]
1 -> 4 increasing, len = 2, add 1
4 -> 5 increasing, len = 3, add 2
5 -> 3 breaks, len = 1
3 -> 7 increasing, len = 2, add 1
7 -> 9 increasing, len = 3, add 2

Total:
1 + 2 + 1 + 2 = 6

*/
class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int n = arr.size();
        
        int ans = 0;
        
        int len = 1;
        
        for (int i = 1; i < n; i++) {
            
            if (arr[i] > arr[i - 1]) {
                len++;
                
                ans += (len - 1);
            } 
            else {
                len = 1;
            }
        }
        
        return ans;
    }
};
