//Approach : 
class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        // code here
        int ones = 0;
        
        for (int num : arr) {
            if (num == 1) {
                ones++;
            }
        }
        
        int currentGain = 0;
        int maxGain = 0;
        
        for (int num : arr) {
            int value;
            
            if (num == 0) {
                value = 1;
            } else {
                value = -1;
            }
            
            currentGain = max(value, currentGain + value);
            maxGain = max(maxGain, currentGain);
        }
        
        return ones + maxGain;
    }
};




//old
class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // int r=0;
        int count=0;
        int flip=0;
        // while(r<n){
        //     if(a[r]==0){
        //         count++;
        //     }else{
        //         count--;
        //     }
            
        //     flip=max(flip,count);
            
        //     if(count<0){
        //         count=0;
        //     }
            
        //     r++;
        // }
        
        for(int r=0;r<n;r++){
            if(a[r]==0){
                count++;
            }else{
                count--;
            }
            flip=max(flip,count);
            if(count<0){
                count=0;
            }
        }
        
        for(int i=0;i<n;i++){
            if(a[i]==1) flip++;
        }
        return flip;
    }
};
