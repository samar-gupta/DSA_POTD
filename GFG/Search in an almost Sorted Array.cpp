//T.C : O(logN)
//S.C : O(1)
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int l = 0, r = n-1;
        
        while(l <= r){
            int mid = (l+r)/2;
            if(arr[mid] == target) return mid;
            else if(arr[mid] > target){
                if(mid+1 < n && arr[mid+1] == target) return mid+1;
                else r = mid-1;
            }
            else{
                if(mid > 0 && arr[mid-1] == target) return mid-1;
                else l = mid+1;
            }
        }
        
        return -1;
    }
};
