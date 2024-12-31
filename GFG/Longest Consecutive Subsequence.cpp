class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        sort(arr.begin(), arr.end());
        int result=0;
        int count=1;
        
        for(int i=1; i<arr.size(); i++){
            if(arr[i]==arr[i-1]+1){
                count++;
            }else if(arr[i]==arr[i-1]){
                continue;
            }else{
                count=1;
            }
            result = max(result ,count);
        }
        
        return result;
    }
};
