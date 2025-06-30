// Approach: Use binary search to maximize the minimum possible height. For each candidate height, check if it can be achieved by at most k waterings using a difference array for efficient range update simulation.
// Time Complexity: O(n * log k), where n is the size of arr and log k is from binary search steps.
// Space Complexity: O(n), for the water difference array.
class Solution {
public:
    // Helper function to check if targetHeight can be achieved with <= k waterings
    bool isPossible(vector<int>& arr, int k, int w, int targetHeight) {
        int         n = arr.size();
        vector<int> water(n + 1, 0);  // Difference array for efficient range addition
        int         daysUsed  = 0;
        int         currWater = 0;

        for (int i = 0; i < n; i++) {
            currWater += water[i];  // Add the effect of previous waterings
            int currHeight = arr[i] + currWater;
            if (currHeight < targetHeight) {
                int need = targetHeight - currHeight; // Water needed at this point
                daysUsed += need;
                if (daysUsed > k) {                   // If exceeded allowed waterings, not possible
                    return false;
                }
                currWater += need;        // Add immediate effect
                water[i]  += need;        // Start effect at i
                if (i + w <= n) {
                    water[i + w] -= need; // End effect after window
                }
            }
        }
        return true;
    }

    // Main function to maximize the minimum height
    int maxMinHeight(vector<int>& arr, int k, int w) {
        int low  = *min_element(arr.begin(), arr.end());
        int high = low + k;

        int result = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(arr, k, w, mid)) {
                result = mid;        // Try to go higher
                low    = mid + 1;
            } else {
                high = mid - 1;      // Try lower
            }
        }
        return result;
    }
};



//Approach : binary search on the answer
//T.C : O(n * log(k))  //  Binary search runs in O(log k) since max value to check is min + k  ,  Each check() call runs in O(n) using prefix diff
//S.C : O(n)    // For the temporary diff[] array used in each check
class Solution {
  public:
    bool check(int mid,int k,int w,int n,vector<int>arr){
        // 2 3 4 5 1
        // choose like interval
        // suppose we have mid =3
        // w=2 [0 to 1] + 2*[3,4] so we cant
        // mid=2 1*[3,4] 
        vector<int>diff(n+1,0);
        int curr_add=0;
        int ops=0;

        for(int i=0;i<n;i++){
            curr_add+=diff[i]; 
            int actual=arr[i]+curr_add;  // current + prev interval this might have been in
            if(actual<mid) {
                int need=mid-actual;
                ops+=need;
                if(ops>k) return false;

                curr_add+=need;
                if(i+w<n) diff[i+w]-=need;
            }
        }
        return true;
    }
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
        // binary search but how do we choose greedily which
        // flowers we increase
        int n=arr.size();
        int l=*min_element(arr.begin(),arr.end());
        int r=l+k;
        
        int ans;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,k,w,n,arr)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};
