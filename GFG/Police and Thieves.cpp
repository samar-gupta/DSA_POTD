// Approach: Use two pointers to scan for the next policeman and the next thief; match them if their indices differ by at most k, otherwise advance the earlier pointer.
// Time Complexity: O(n) – each element is visited at most once by each pointer.
// Space Complexity: O(1) – only a fixed number of integer variables are used.
class Solution {
public:
    int catchThieves(vector<char>& arr, int k) {
        int n     = arr.size();
        int i     = 0;    // pointer to scan for 'P'
        int j     = 0;    // pointer to scan for 'T'
        int count = 0;    // total thieves caught

        while (i < n && j < n) {
            // move i to the next policeman
            while (i < n && arr[i] != 'P') {
                i++;
            }
            // move j to the next thief
            while (j < n && arr[j] != 'T') {
                j++;
            }

            // if both pointers are valid and within k distance, catch!
            if (i < n && j < n && abs(i - j) <= k) {
                count++;
                i++;
                j++;
            }
            // if thief is too far left, move thief pointer right
            else if (j < n && j < i) {
                j++;
            }
            // if policeman is too far left, move policeman pointer right
            else if (i < n && i < j) {
                i++;
            }
        }
        return count;
    }
};
