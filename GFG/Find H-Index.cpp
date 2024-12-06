class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // code here
        int len= citations.size();
        vector<int> bucket(len+1);
        
        for(int c: citations){
            bucket[min(c, len)]++;
        }
        
        int count=0;
        
        for(int i=len;i>=0;i--){
            count+=bucket[i];
            if(count >= i){
                return i;
            }
        }
        
        return 0;
    }
};
