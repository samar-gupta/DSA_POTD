class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        // Your code goes here;
        vector<int>ans;
        sort(b.begin(),b.end());
        for(int i=0;i<q;i++) {
            int val = query[i];
            int sval = a[val];
            int count = upper_bound(b.begin(),b.end(),sval)-b.begin();
            ans.push_back(count);
        }
        return ans;
    }
};
