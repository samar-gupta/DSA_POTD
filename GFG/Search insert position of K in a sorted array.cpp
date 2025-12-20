//Approach: 
//Basic binary search (T.C. -> O(logn) S.C. -> O(1))
class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k < arr[0]) return 0;
        if(k > arr[n-1]) return n;
        
        int l = 0, r = n-1;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            if(arr[mid] == k) return mid;
            else if(arr[mid] > k) r = mid - 1;
            else l = mid + 1;
        }
        
        return l;
    }
};


//Approach:
//Basic binary search (T.C. -> O(logn) S.C. -> O(1))
class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int N = are.size();
        int start=0;
        int end=N-1;
        int ans=N;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(arr[mid]>=k)
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};


//Approach:
//1 liner (T.C. -> O(logn) S.C. -> O(1))
class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        return lower_bound(arr.begin(), arr.end(), k) - arr.begin();
    }
};
