class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int i = 0, j = 1;
      
        while(i<n && j<n){
            int diff = abs(arr[j] - arr[i]);
            
            if(diff == x && i != j){
                return 1;
            }
            else if(diff < x){
                j++;
            }
            else{
                i++;
            }

            //Ensuring i and j don't overlap incorrectly 
            if(i == j) {
                j++;
            }
        
        }
        
        return -1;
    }
};
