//Approach: (Binary Search on Answer)
class Solution {
  public:
    
    bool isPossible(int mid,int n,vector<int>&ranks)
    {
        int donuts=0;
        for(auto it:ranks)
        {
            int x=(-1+sqrt(1+(8.0*mid)/it))/2;
            donuts+=x;
            if(donuts>=n)
            {
                return true;
            }
        }
        return false;
    }
  
    int minTime(vector<int>& ranks, int n) {
        // code here
        
        int mn=INT_MAX;
        for(auto it:ranks)
        {
            mn=min(it,mn);
        }
        int l=0;
        int h=mn*((n*(n+1))/2);
        int ans=h;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(isPossible(mid,n,ranks))
            {
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
