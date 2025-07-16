//Approach-1 : (Using Sieve of Eratosthenes and using maths property)
#define ll long long int
class Solution {
  public:
    ll power(ll a, int n) 
    {
        ll val=1;
        for(int i=0;i<8;i++)
        {
            val*=a;
            if(val>n)
            {
                return false;
            }
        }
        return true;
    }
    
    int countNumbers(int n) {
        // Code Here
        int ans=0;
        int k=sqrt(n);
        vector<bool>arr(k+1,true);
        arr[1]=false;
        for(int i=2;i*i<=k;i++)
        {
            if(arr[i]==true)
            {
                for(int j=2*i;j<=k;j+=i) 
                {
                    arr[j]=false; 
                }
            }
        }
        
        vector<ll>primes;
        for(ll i=2;i<=k;i++)
        {
            if(arr[i]==true)
            {
                primes.push_back(i);
            }
        }
        
        for(int i=0;i<primes.size();i++)
        {
            ll a=primes[i];
            if(power(a,n))
            {
                ans++;
            }
            else{
                break;
            }
        }
        
        for(int i=0;i<primes.size();i++)
        {
            for(int j=i+1;j<primes.size();j++)
            {
                ll a=primes[i];
                ll b=primes[j];
                ll val=a*a*1LL*b*b;
                if(val<=n)
                {
                    ans++;
                }
                else{
                    break;
                }
            }
        }
        
        return ans;
    }
};
