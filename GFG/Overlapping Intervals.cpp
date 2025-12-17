//Approach-1:
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        for(int i=1;i<arr.size();i++)
        {
            if(ans.back()[1]>=arr[i][0])ans.back()[1]=max(arr[i][1],ans.back()[1]);
            else ans.push_back(arr[i]);
        }
        
        return ans;
    }
};


//Approach-1:
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int cnt=0;
      
        ans.push_back(arr[0]);
        for(int i=1;i<n;i++){
           if(ans[cnt][1]>=arr[i][0]){
               ans[cnt][1]=max(ans[cnt][1],arr[i][1]);
           }
           else{
               ans.push_back(arr[i]);
               cnt++;
           }
        }
        return ans;
    }
};
