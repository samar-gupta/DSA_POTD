class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int sum = 0;     //arrSum
        int tsum = 0;    //totalSum
        for(int i = 0 ; i<arr.size() ; i++)
        {
            sum += arr[i];
        }
        for(int i = 1 ; i<=(arr.size()+1) ; i++)
        {
            tsum += i;
        }
        return (tsum-sum);   //missing = totalSum - arrSum
    }
};
