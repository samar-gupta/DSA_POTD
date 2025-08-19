//Approach-1 : 
//T.C : O(n)+O(nlogm) ~ O(nlogn)
//S.C : O(n)
class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        int n = arr.size();

        vector<int> ans(n, -1);


        vector<int> suff(n);
        suff[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            suff[i] = min(arr[i], suff[i + 1]);
        }

        for (int i = 0; i < n; ++i) {
            int res = -1;
            int l = i + 1, r = n - 1;

            while (l <= r) {
                int mid = (l + r) / 2;
                if (suff[mid] < arr[i]) {
                    res = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            ans[i] = res;
        }

        return ans;
    }
};
