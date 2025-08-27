//Approach-1 : (Sorting)
//T.C : O(nlogn) + O(n^2)
//S.C : O(1)
class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n < 3) return 0;

        sort(arr.begin(), arr.end());
        int res = 0;

        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (arr[i] + arr[j] > arr[k]) {
                    res += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }
        return res;
    }
};


//old
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
