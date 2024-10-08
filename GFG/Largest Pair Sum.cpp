class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        int maxi1 = -1 ; 
        int maxi2 = -1 ; 
           
        for(int i=0; i<arr.size() ; i++){
            if(maxi1<arr[i]){
                maxi2 = maxi1 ;   //previous value of maxi1 assign into maxi2
                maxi1 = arr[i] ;    
            }
            else if(maxi2<arr[i]){
                maxi2 = arr[i] ; 
            }
        }
           
        return maxi1 + maxi2 ; 
    }
};
