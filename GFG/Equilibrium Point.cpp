class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int total = 0;
        for(int ele : arr) total += ele;
        int leftSum = 0;
        for(int i=0;i<arr.size();i++){
            int rightSum = total - leftSum - arr[i];
            if(leftSum == rightSum) return i;
            leftSum += arr[i];
        }
        return -1;
    }
};
