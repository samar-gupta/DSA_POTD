class Solution{
public:
void help(vector<int>&arr,int n,int k,int i,int sum,vector<int>&temp,set<vector<int>>&st  ){
    if(sum==k){
      st.insert(temp);
      return;
    }
    if(i==n) return;
    help(arr,n,k,i+1,sum,temp,st);
    if(sum+arr[i]<=k){
        temp.push_back(arr[i]);
        help(arr,n,k,i+1,sum+arr[i],temp,st);
        temp.pop_back();        
    }
}
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        sort(arr.begin(),arr.end());
        vector<int>temp;
        set<vector<int>>st;
        help(arr,n,k,0,0,temp,st);
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
        
    }

};
