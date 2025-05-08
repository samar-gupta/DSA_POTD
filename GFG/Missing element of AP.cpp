//Approach-1 : (Linear Approach)
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int n = arr.size();
        int prevDiff = arr[1] - arr[0];
      
        for(int i = 2; i < n; i++) {
            int currDiff = arr[i] - arr[i - 1];
            if (currDiff != prevDiff) {
                return arr[i - 1] + prevDiff;
            }
        }
       
        return arr[n - 1] + prevDiff;
    }
};


//Approach-2 : (Using Binary Search)
//T.C : O(logN)
//S.C : O(1)
class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int n=arr.size();
        int l=0,r=n-1;
        int d=arr[1]-arr[0];
        
        while(l<=r){
            int mid=l+((r-l)/2);
            
            if(arr[0]+mid*d < arr[mid]){
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        
        return arr[0]+(l*d);
    }
};
