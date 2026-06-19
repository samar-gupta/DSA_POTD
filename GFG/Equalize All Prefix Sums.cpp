class Solution {
  public:
    vector<int> optimalArray(vector<int> &arr) {
        // code here
        vector<int>ans;
        ans.push_back(0);
        for(int i=1;i<arr.size();i++)
        {
            ans.push_back(ans.back()+(arr[i]-arr[i/2]));
        }
        return ans;
    }
};
