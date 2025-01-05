class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int s = 0;    //start
        int e = n-1;  //end
        int c = 0;    //count
        
        while(s<e)
        {
            if(arr[s] + arr[e] < target)
            {
                c += (e-s);
                s++;
            }
            else
            {
                e--;
            }
        }
        
        return c;
    }
};
