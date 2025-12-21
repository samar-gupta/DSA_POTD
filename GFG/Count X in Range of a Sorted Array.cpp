/*
🔹 Intuition:
The array is sorted, so all occurrences of any number x appear contiguously.
Instead of scanning every element for each query (which would be slow), we can:
  Find the first occurrence of x
  Find the last occurrence of x
Once we know these two positions, counting how many times x appears inside [l, r] becomes simple.
Binary Search allows us to do this efficiently.

🔹 Approach:
For each query [l, r, x]:

Use lower_bound to find
-->the first index where arr[i] >= x
(this gives the first possible position of x)

Use upper_bound to find
--> the first index where arr[i] > x
(subtract 1 to get the last occurrence of x)

Now check:
If x lies completely outside [l, r], answer is 0
Otherwise, take the overlap between:
[first, last] (positions of x)
[l, r] (query range)
Count = right − left + 1

🔹 Dry Run:
Input arr = [1, 2, 2, 4, 5, 5, 5, 8] query = [0, 7, 5]
Steps
lower_bound(5) = 4
upper_bound(5) = 7 → last = 6
Range of x = 5 → [4, 6]
Query range → [0, 7]
Overlap:
left = max(4, 0) = 4 right = min(6, 7) = 6
Count:
6 - 4 + 1 = 3
✔️ Correct answer
Query [0, 3, 7]
lower_bound(7) = 7
upper_bound(7) = 7 → last = 6
first > r → not present
Answer = 0

🔹 Time & Space Complexity:
Time Complexity: O(q × log n)
(each query uses two binary searches)

Auxiliary Space: O(1)
(excluding output array)
*/
class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        int n=arr.size();
        vector<int> ans;
        
        for(auto &q : queries){
            int l=q[0];
            int r=q[1];
            int x=q[2];
            
            // first index >= x
            int first=lower_bound(arr.begin(),arr.end(),x) - arr.begin();
            
            // first index > x
            int last=upper_bound(arr.begin(),arr.end(),x) - arr.begin()-1;
            
            // Check if x exists in the given range
            if(first > r || last < l){
                ans.push_back(0);
            } 
            else{
                int left=max(first, l);
                int right=min(last, r);
                ans.push_back(right - left + 1);
            }
        }
        
        return ans;
    }
};
