class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
        int n=arr.size();
        int i=0;
        int swaps=0;
        while(i<n){
            if(arr[i]!=(i+1)){
                swap(arr[i],arr[arr[i]-1]);
                swaps++;
                
                if(swaps>2) return false;
            }
            else{
                i++;
            }
        }
        if(swaps==0 or swaps==2) return true;
        return false;
    }
};
