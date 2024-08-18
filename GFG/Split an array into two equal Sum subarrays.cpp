class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int n=arr.size();
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=arr[i];
        }
        if (totalSum%2 != 0) return false;
        
        int currSum=0;
        for(int i=0;i<n;i++){
            currSum+=arr[i];
            if(currSum==totalSum-currSum)
                return true;
        }
        
        return false;
    }
};
