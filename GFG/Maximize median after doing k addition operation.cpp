//Approach-1 : (Using Binary Search on Ans)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
  public:
    bool check(int mid , vector<int> &arr , int k)
    {
        int n = arr.size();
        int x = arr[(n - 1) / 2] , y = arr[n / 2];
        long long z = x + y , cnt = 0;
        int prev = arr[n / 2];
        if((2 * 1LL * mid > z) && (n % 2 == 0))
        {
            cnt += (2 * mid - z);
            prev = max(prev , mid);
        }
        
        if(n % 2 == 1 && mid > y)
        {
            cnt += (mid - y);
            prev = max(prev , mid);
        }
        
        for(int i = (n / 2) + 1; i < n; i++)
        {
            if(arr[i] < prev)
                cnt += (prev - arr[i]);
            else
                prev = arr[i];
        }
        
        return (cnt <= k);
        
    }
    
    int maximizeMedian(vector<int>& arr, int k) {
        // code here
        sort(arr.begin() , arr.end());
        int n = arr.size();
        int start = arr[(n - 1) / 2] , end = arr.back() + k;
        int ans = arr[(n - 1) / 2];
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(check(mid , arr , k))
                ans = mid , start = mid + 1;
            else
                end = mid - 1;
        }
        return ans;
    }
};
