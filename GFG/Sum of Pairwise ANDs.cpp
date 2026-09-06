#define ll long long int
class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        // code here
        ll ans=0;
        int n=arr.size();
        for(int j=0;j<32;j++)
        {
            ll count=0;
            for(int i=0;i<n;i++)
            {
                ll curr=arr[i];
                if((curr>>j)&1)
                {
                    count++;
                }
            }
            ans+=(1LL<<j)*((count*1LL*(count-1))/2);
        }
        return ans;
    }
};
