//Approach-1 : (Using Binary Search on Ans)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
  public:
    bool isPossible(vector<int>& arr, int n, int k, int maxPages) {

        int count = 1;

        int currSum = 0;

        for (int pages : arr) {
            if (currSum + pages > maxPages) {
                count++;
                currSum = pages;
                if (count > k) return false;
            } else {
                currSum += pages;
            }
        }
        return true;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();

        if (k > n) return -1;


        int low = 0, high = 0;
        for (int pages : arr) {
            low = max(low, pages);
            high += pages;
        }

        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(arr, n, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};


//old
class Solution {
  public:
  bool isPossible(vector<int>&arr,int k,int mid){
      int cnt=1;
      int sum=0;
      for(int i=0;i<arr.size();i++){
          if(sum+arr[i]>mid){
              sum=arr[i];
              cnt++;
          }
          else
          sum+=arr[i];
      }
      return cnt<=k;
  }
  
    int findPages(vector<int> &arr, int k) {
        if(k>arr.size())
        return -1;
       int low=*max_element(arr.begin(),arr.end());
       int high=accumulate(arr.begin(),arr.end(),0);
       int ans=-1;
       while(low<=high){
           int mid=(low+high)/2;
           if(isPossible(arr,k,mid)){
              high=mid-1;
              ans=mid;
           }
           else
               low=mid+1;
       }
       return ans;
    }
};
