class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        int n=arr.size();
        
        int totalEven=0;
        int totalOdd=0;
        
      
        for(int i=0;i<n;i++){
            
            if(i&1){
                totalOdd+=arr[i];
            }
            else{
                totalEven+=arr[i];
            }
                
        }
        
        int leftEven=0;
        int leftOdd=0;
        int cnt=0;
        
      
        for (int i=0;i<n;i++){
            
            if(i&1){
                totalOdd-=arr[i];
            }
            else{
                totalEven-=arr[i];
            }
                
            
            int newEvenSum=leftEven+totalOdd;
            int newOddSum =leftOdd+totalEven;
            
            if(newEvenSum==newOddSum){
                cnt++;
            }
                
       
            if(i&1){
                leftOdd+=arr[i];
            }
            else{
                leftEven+=arr[i];
            }
                
        }
        
        return cnt;
    }
};
