class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
        if(arr[0]==0)return -1;
        int s = arr[0];   //step
        int maxReach=arr[0];
        int jump=1;
        int n=arr.size();
        
        for(int i=1;i<n;i++){
            if(i==n-1)return jump;
            maxReach = max(maxReach, i+arr[i]);
            s--;
            if(s == 0){
                jump++;
                if(i>=maxReach)return -1;
                s = maxReach-i;
            }
        }
        return -1;
    }
};
