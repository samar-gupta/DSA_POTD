//Approach :
/*
1. Start from the first element and find a group of consecutive numbers with the same parity (odd or even).
2. Sort each group in descending order so the largest numbers come first.
3. Move to the next group and repeat until the whole array is processed.
4. Return the updated array.
*/
class Solution {
  public:
    vector<int> lexicographicallyLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && (arr[j] % 2 == arr[j + 1] % 2)) {
                j++;
            }
            sort(arr.begin() + i, arr.begin() + j + 1, greater<int>());
            i = j + 1;
        }
        return arr;
    }
};
