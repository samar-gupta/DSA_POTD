class Solution {
  public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        // code here
        int ans = 0;
        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());
        for (int i = 0; i < n; i++) {
            ans += abs(chairs[i] - passengers[i]);
        }
        return ans;
    }
};
