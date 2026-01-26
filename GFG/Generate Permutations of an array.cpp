class Solution {
  public:
  
    void solve(int i,vector<int>arr,vector<vector<int>>&ans)
    {
        int n=arr.size();
        if(i==n)
        {
            ans.push_back(arr);
            return;
        }
        for(int j=i;j<n;j++)
        {
            swap(arr[i],arr[j]);
            solve(i+1,arr,ans);
            swap(arr[i],arr[j]);
        }
    }
  
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        vector<vector<int>>ans;
        solve(0,arr,ans);
        return ans;
    }
};
