//Approach-1 : 
//T.C : O(N log(N))
class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> lis;
        int sum=0, lisSum[n+1]; //lisSum[i] -> stores sum of lis of length i
        lisSum[0]=0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            int index = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            if(index == lis.size())
                lis.push_back(arr[i]);
            else
                lis[index] = arr[i];
            lisSum[index+1] = lisSum[index] + arr[i];
        }
        return sum - lisSum[lis.size()];
    }
};
