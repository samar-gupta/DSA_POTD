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
