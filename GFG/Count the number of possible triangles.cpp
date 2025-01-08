class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ans=0;
        sort(begin(arr), end(arr), greater<int>());
        for(int i=0;i<n-2;i++){
            int largerSide = arr[i];
            int l=i+1,r=n-1;
            while(l<r){
                if(arr[l]+arr[r]>largerSide){
                    ans+=r-l;
                    l++;
                }
                else
                    r--;
            }
        }
        return ans;
    }
};
