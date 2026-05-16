class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        // code here.
        sort(arr.begin(), arr.end());

        long long smallestMissing = 1;

        for (int num : arr) {

            if (num > smallestMissing) {
                break;
            }

            smallestMissing += num;
        }

        return smallestMissing;
    }
};



//old
class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        // Your code goes here.
        int ans=1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=ans){
                ans = ans+arr[i];
            }
        }
        return ans;
    }
};
