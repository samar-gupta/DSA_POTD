class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int l = 0;
        int h = n-1;
        
        while(l<h){
            int mid = l+(h-l)/2; 
            if(arr[mid] > arr[h]) l = mid + 1;
            else h = mid;
        }
        
        return l;
    }
};
