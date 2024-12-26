class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int i=0,j=n-1;
        while(i<j){
            if(arr[i]+arr[j]==target) return true;
            else if(arr[i]+arr[j]>target) j--;
            else i++;
        }
        return false;
    }
};
